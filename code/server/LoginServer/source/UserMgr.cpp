#include <string>
#include <cctype>
#include <algorithm>
#include "UserMgr.h"
#include "PacketDefine.h"
#include "random.h"
#include "LoginServer.h"
#include "error.h"
#include "DBOperate.h"
#include "gtime.h"
#include "strtools.h"
#include "md5.h"
#include "curl/curl.h"
#include "MessageUserCheck.pb.h"
#include "MessageErrorNo.pb.h"
#include "MessageNotifySWChecher.pb.h"
#include "MessageRegistServer.pb.h"
#include "MessageClientLogin.pb.h"

#define  SW_POST_URL			"http://interface.kedou.com/front/interface/verifyLoginStatus.htm"
#define	 SW_POST_FIELDS_FORMAT	"siteId=%d&time=%s&gameId=%d&memberId=%lld&flagGuid=1&ticket=%s&sign=%s"
#define  SW_COOKIE_FILE			"curlpost.cookie"

CUserMgr::CUserMgr()
{
	curl_global_init(CURL_GLOBAL_ALL);
}

CUserMgr::~CUserMgr()
{
	curl_global_cleanup();
}

bool CUserMgr::OnMsg(PACKET_COMMAND* pack)
{
	if (!pack) {
		return false;
	}

	switch (pack->Type())
	{
	case P2L_REQUEST_USER_CHECK:	_HandlePacket_UserCheck(pack);		break;
	case A2L_REQUEST_AUTH_CHECKER:	_HandlePacket_GateAuth(pack);		break;
	
	default:	return false;
	}

	return true;
}

bool CUserMgr::OnGateAuth(struct mg_connection *conn)
{
	if (conn == NULL) {
		Log.Error("GateAuth error conn == NULL.");
		return false;
	}

	char userid[AUTH_VAR_LEN] = { 0 };
	mg_get_var(conn, AUTH_USER_ID, userid, AUTH_VAR_LEN);
	
	UserID uid = atoll(userid);
	if (uid < 1) {
		Log.Error("GateAuth error. Wrong userid: %lld, ip: %s, port: %d", uid, conn->remote_ip, conn->remote_port);
		return false;
	}

	CUser *user = _GetUser(uid);
	if (!user) {
		Log.Error("GateAuth error. No user: %lld, ip: %s, port: %d", uid, conn->remote_ip, conn->remote_port);
		return false;
	}

	char accesstoken[AUTH_VAR_LEN] = { 0 };
	mg_get_var(conn, AUTH_ACCESS_TOKEN, accesstoken, AUTH_VAR_LEN);
	if (string(accesstoken) != user->m_accessToken) {
		Log.Error("Wrong accesstoken. user: %s, accesstoken1: %s, accesstoken2: %s", userid, accesstoken, user->m_accessToken.c_str());
		Log.Error("[CUserMgr]Authentication Failed To GateServer: user: %s, accesstoken: %s", userid, accesstoken);
		return false;
	}

	Log.Debug("[CUserMgr]Authentication Successed To GateServer: user: %s, accesstoken: %s", userid, accesstoken);

	_DelUser(uid);

	return true;
}

void CUserMgr::UserHeartLogic()
{
	VPROF("UserHeartLogic");

	int tempIdx, i=0;
	for (int idx = m_UncheckedUserList.Head(); m_UncheckedUserList.IsValidIndex(tempIdx = idx);)
	{
		idx = m_UncheckedUserList.Next(idx);

		CUser *pUser = _GetUser(m_UncheckedUserList.Element(tempIdx));
		if (!pUser || checkFromThirdPlatform(pUser)) {
			m_UncheckedUserList.Remove(tempIdx);
		}

		if (++i >= PLATFORM_PERIOD_MAX) {
			break;
		}
	}
}

bool CUserMgr::_HandlePacket_UserCheck(PACKET_COMMAND* pack)
{
	Message::UserCheck msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	UserID userid = msg.userid();
	if (userid < 1) {
		return false;
	}

	CUser* pUser = _AddUser(userid);
	if (!pUser) {
		Log.Error("user: "INT64_FMT" create fail, so login failed.", userid);
		GETCLIENTNET(&LoginServer)->shutdown(pack->GetNetID());
		return false;
	}
	if (pUser->m_id == userid) {
		Log.Warning("user: "INT64_FMT" Relogin after soon.", userid);
	}

	pUser->m_sock = pack->GetNetID();
	pUser->m_server = msg.server();
	pUser->m_id = userid;
	pUser->m_ticket = msg.ticket();
	pUser->m_client = msg.client();
	pUser->m_HeartTime = time(NULL);
	pUser->m_auto = msg.bauto();

	if (m_UncheckedUserList.Find(userid) == m_UncheckedUserList.InvalidIndex()) {
		m_UncheckedUserList.AddToTail(userid);
	}

	return true;
}

bool CUserMgr::_HandlePacket_GateAuth(PACKET_COMMAND* pack)
{
	Message::ClientLogin msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	UserID uid = msg.uid();
	string accesstoken = msg.accesstoken();
	CUser *user = NULL;
	if (uid < 1 || !(user = _GetUser(uid)) || accesstoken != user->m_accessToken) {
		Log.Error("GateAuth error. Wrong userid: %lld and accesstoken: %s", uid, accesstoken.c_str());

		uid = -1;
		accesstoken.clear();		
	}
	else {
		Log.Debug("[CUserMgr]Authentication Successed To GateServer: user: %lld, accesstoken: %s", uid, accesstoken.c_str());

		_DelUser(uid);
	}

	Message::ClientLogin msg2;
	msg2.set_uid(uid);
	msg2.set_accesstoken(accesstoken);
	msg2.set_key(msg.key());

	PACKET_COMMAND pack2;
	PROTOBUF_CMD_PACKAGE(pack2, msg2, L2A_RESPONSE_AUTH_CHECKER);
	GETCLIENTNET(&LoginServer)->sendMsg(pack->GetNetID(), &pack2);

	return true;
}

bool CUserMgr::checkFromThirdPlatform(CUser *pUser)
{
	//验证账号密码，需与运维平台对接
	if (pUser->m_auto) { //自动登陆，无需请求验证
		char tmpbuf[16] = { 0 };
		int ntoken = RandomInt(AUTO_ACCESS_LEFT, AUTO_ACCESS_RIGHT);
		sprintf(tmpbuf, "%d", ntoken);
		pUser->m_accessToken = tmpbuf;
		sendSWChecker(pUser);
		GETCLIENTNET(&LoginServer)->shutdown(pUser->m_sock);

		Log.Debug("[CUserMgr]Authentication Successed To Client by auto: user: %lld, ticket: %s", pUser->m_id, pUser->m_ticket.c_str());

		return true;
	}
	else { //向服务器请求验证
		return ThreadLib::CreateByPool(httpCheckUserThread, pUser);
	}
}

void CUserMgr::httpCheckUserThread(void *pParam)
{
	CURL *pUrl = curl_easy_init();
	if (!pUrl) {
		Log.Error("!pUrl. Unknow Error.");
		return;
	}

	CUser *pUser = (CUser *)pParam;
	string postStr = generatePostField(pUser);
	if (postStr.size() < 1) {
		Log.Error("generatePostField Failed.");
		return;
	}

	Log.Debug("httpCheckUser: userid:%lld, client:%d, ticket:%s", pUser->m_id, pUser->m_client, pUser->m_ticket.c_str());

	curl_easy_setopt(pUrl, CURLOPT_URL, SW_POST_URL);
	curl_easy_setopt(pUrl, CURLOPT_POSTFIELDS, postStr.c_str());
	curl_easy_setopt(pUrl, CURLOPT_WRITEFUNCTION, recvBackData);
	curl_easy_setopt(pUrl, CURLOPT_WRITEDATA, pUser);
	curl_easy_setopt(pUrl, CURLOPT_POST, 1);
	curl_easy_setopt(pUrl, CURLOPT_NOSIGNAL, 1);
	//curl_easy_setopt(pUrl, CURLOPT_VERBOSE, 1);
	//curl_easy_setopt(pUrl, CURLOPT_HEADER, 1);
	//curl_easy_setopt(pUrl, CURLOPT_FOLLOWLOCATION, 1);
	curl_easy_setopt(pUrl, CURLOPT_COOKIEFILE, SW_COOKIE_FILE);
	CURLcode res = curl_easy_perform(pUrl);
	curl_easy_cleanup(pUrl);

	if (res != 0) {
		UserMgr.SendErrorMsg(pUser, Error_Login_CheckFailed);
		Log.Error("curl curl_easy_perform error: %s", curl_easy_strerror(res));
		Log.Error("[CUserMgr]Authentication Failed To Client From AccountServer: user: %lld, ticket: %s", pUser->m_id, pUser->m_ticket.c_str());
	} else {
		Log.Debug("[CUserMgr]Authentication Successed To Client From AccountServer: user: %lld, ticket: %s", pUser->m_id, pUser->m_ticket.c_str());
	}

	GETCLIENTNET(&LoginServer)->shutdown(pUser->m_sock);
}

string CUserMgr::generatePostField(CUser *pUser)
{
	//siteId gameId md5Key
	int siteId;
	int gameId;
	char *md5Str;
	if (pUser->m_client == CLIENT_PLATFORM_IOS) {
		siteId = 7033;
		gameId = 7033;
		md5Str = "AE92D92B41FA4038B88E66CF6528619B";
	}
	else if (pUser->m_client == CLIENT_PLATFORM_ANDROID) {
		siteId = 6033;
		gameId = 6033;
		md5Str = "3C62118CB5A747399DD8CE92CF7B2869";
	}
	else {
		return "";
	}


	//time
	char timeStr[20] = { 0 };
	GTime gt;
	GetLocalTime(gt);
	sprintf(timeStr, "%d%02d%02d%02d%02d%02d", gt.gtm_year, gt.gtm_mon, gt.gtm_mday, gt.gtm_hour, gt.gtm_min, gt.gtm_sec);


	//sign: sign = upper(md5(upper(urlencode(siteId | time | memberId | ticket | md5Key))));
	char tmpStr[512] = { 0 };
	char signStr[512] = { 0 };
	sprintf(signStr, "%d|%s|%lld|%s|%s", siteId, timeStr, pUser->m_id, pUser->m_ticket.c_str(), md5Str);
	UrlEncode((unsigned char *)signStr, (unsigned char *)tmpStr, strlen(signStr));
	memset(signStr, 0, sizeof(signStr));
	strnupper(tmpStr, signStr, strlen(tmpStr));
	
	memset(tmpStr, 0, sizeof(tmpStr));
	unsigned char digest[16];
	CUtlMD5 md5Tool;
	md5Tool.MDString(signStr, digest);
	for (int di = 0; di < 16; ++di) {
		sprintf(tmpStr + di * 2, "%02x", digest[di]);
	}
	
	memset(signStr, 0, sizeof(signStr));
	strnupper(tmpStr, signStr, strlen(tmpStr));


	//"siteId=%d&time=%s&gameId=%d&memberId=%s&flagGuid=1&ticket=%s&sign=%s";
	char fortmatStr[1024] = { 0 };
	sprintf(fortmatStr, SW_POST_FIELDS_FORMAT, siteId, timeStr, gameId, pUser->m_id, pUser->m_ticket.c_str(), signStr);

	return string(fortmatStr);
}

size_t CUserMgr::recvBackData(void *buffer, size_t nsize, size_t nmemb, void *userp)
{
	CUser *pUser = (CUser *)userp;
	char xmlvalue[32] = { 0 };
	char guid[64] = {0};
	char accessToken[128] = {0};
	char refreshToken[128] = { 0 };
	char *xmlstr = (char *)buffer;
	if (strlen(xmlstr) < 1024 
		&& ParseXmlString(xmlstr, "msgId", xmlvalue, 32) && strcmp(xmlvalue, "0") == 0
		&& ParseXmlString(xmlstr, "loginStatus", xmlvalue, 32) && strcmp(xmlvalue, "1") == 0
		&& ParseXmlString(xmlstr, "guid", guid, 64) 
		&& ParseXmlString(xmlstr, "accessToken", accessToken, 128)
		&& ParseXmlString(xmlstr, "refreshToken", refreshToken, 128)) { //验证成功
		pUser->m_guid = guid;
		pUser->m_accessToken = accessToken;
		pUser->m_refreshToken = refreshToken;

		UserMgr.sendSWChecker(pUser);
	}
	else {
		UserMgr.SendErrorMsg(pUser, Error_Login_CheckFailed);
		Log.Error("check sw_user failed: %lld. return content: %s", pUser->m_id, xmlstr);
	}

	return nmemb * nsize;
}

void CUserMgr::sendSWChecker(CUser *pUser)
{
	Message::NotifySWChecker msg;
	msg.set_guid(pUser->m_guid);
	msg.set_accesstoken(pUser->m_accessToken);
	msg.set_refreshtoken(pUser->m_refreshToken);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, L2P_NOTIFY_SW_CHECKER);
	GETCLIENTNET(&LoginServer)->sendMsg(pUser->m_sock, &pack);
}

void CUserMgr::SendErrorMsg(CUser* user, int errid)
{
	if (!user)
		return;

	Message::ErrorNo msg;
	msg.set_error(errid);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, S2P_NOTIFY_SYNC_ERROR);
	GETCLIENTNET(&LoginServer)->sendMsg(user->m_sock, &pack);
}

CUser *CUserMgr::_AddUser(UserID userid)
{
	m_UserLock.LOCK();
	CUser *user = GetObj(userid);
	if (!user) {
		user = Create(userid);
	}
	m_UserLock.UNLOCK();

	return user;
}

CUser *CUserMgr::_GetUser(UserID userid)
{
	m_UserLock.LOCK();
	CUser *user = GetObj(userid);
	m_UserLock.UNLOCK();

	return user;
}

void CUserMgr::_DelUser(UserID userid)
{
	m_UserLock.LOCK();
	Delete(userid);
	m_UserLock.UNLOCK();
}
