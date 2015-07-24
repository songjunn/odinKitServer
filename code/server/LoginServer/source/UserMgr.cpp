#include <string>
#include <cctype>
#include <algorithm>
#include "UserMgr.h"
#include "random.h"
#include "MainServer.h"
#include "error.h"
#include "DBOperate.h"
#include "gtime.h"
#include "strtools.h"
#include "md5.h"
#include "curl/curl.h"
#include "MessageTypeDefine.pb.h"
#include "MessageServer.pb.h"
#include "MessageCommon.pb.h"
#include "MessageUser.pb.h"


#define  SW_POST_URL			"http://interface.kedou.com/front/interface/verifyLoginStatus.htm"
#define	 SW_POST_FIELDS_FORMAT	"siteId=%d&time=%s&gameId=%d&memberId=%lld&flagGuid=1&ticket=%s&sign=%s"
#define  SW_COOKIE_FILE			"curlpost.cookie"

char CUserMgr::paysrv_addr[32] = { 0 };
int	 CUserMgr::paysrv_port = 0;

CUserMgr::CUserMgr()
{
	m_GuestIdMax = 0;
	m_HeartTimeout = 0;

	curl_global_init(CURL_GLOBAL_ALL);
}

CUserMgr::~CUserMgr()
{
	curl_global_cleanup();
}

void CUserMgr::SetUserTimeout(TMV t)
{
	m_HeartTimeout = t;
}

void CUserMgr::UserHeartLogic()
{
	VPROF("UserHeartLogic");

	TMV t = time(NULL);

	SOCKET sock = m_list.Head();
	while (CUser* user = GetObj(sock))
	{
		sock = m_list.Next(sock);

		if (m_HeartTimeout > 0 && t - user->m_HeartTime > m_HeartTimeout)
		{
			Log.Error("[UserMgr]User(sock:%d, uid:"INT64_FMT")time out, kick off", user->m_sock, user->m_id);

			_Shutdown(user);
		}
	}
}

bool CUserMgr::LoadFactId(int worldID)
{
	m_GuestIdMax = g_LoadGuestFactID(worldID);
	return true;
}

void CUserMgr::SendErrorMsg(CUser* user, int errid)
{
	if (!user)
		return;

	Message::ErrorNo msg;
	msg.set_error(errid);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_COMMON_ERROR);
	GETCLIENTNET->sendMsg(user->m_sock, &pack);
}

bool CUserMgr::OnMsg(PACKET_COMMAND* pack)
{
	if (!pack)
		return false;

	switch (pack->Type())
	{
	case Message::MSG_REQUEST_USER_CHECK:	_HandlePacket_UserCheck(pack);		break;
	case Message::MSG_REQUEST_GUEST_CHECK:	_HandlePacket_GuestCheck(pack);		break;
	case Message::MSG_SERVER_NET_ACCEPT:	_HandlePacket_NetAccept(pack);		break;
	case Message::MSG_SERVER_NET_CLOSE:		_HandlePacket_NetClose(pack);		break;
	default:	return false;
	}

	return true;
}

bool CUserMgr::_HandlePacket_UserCheck(PACKET_COMMAND* pack)
{
	if (!pack)
		return false;

	Message::UserCheck msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	CUser* pUser = GetObj(pack->GetNetID());
	if (!pUser)
		return false;

	pUser->m_sock = pack->GetNetID();
	pUser->m_server = msg.server();
	pUser->m_id = atoll(msg.userid().c_str());
	pUser->m_ticket = msg.ticket();
	pUser->m_client = msg.client();

	//验证账号密码，需与运维平台对接
	ThreadLib::CreateByPool(httpCheckUserThread, pUser);

	return true;
}

bool CUserMgr::_HandlePacket_GuestCheck(PACKET_COMMAND* pack)
{
	if (!pack)
		return false;

	Message::GuestCheck msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	Log.Notice("[Login] Guest:%s Sock:%d Request Login", msg.device().c_str(), pack->GetNetID());

	CUser* pUser = GetObj(pack->GetNetID());
	if (!pUser)
		return false;

	pUser->m_sock = pack->GetNetID();
	pUser->m_server = msg.server();
	pUser->m_device = msg.device();
	std::transform(pUser->m_device.begin(), pUser->m_device.end(), pUser->m_device.begin(), ::tolower);

	//验证游客账号
	bool bExit = false;
	if (!_CheckGuest(pUser, bExit))
	{
		SendErrorMsg(pUser, Error_Login_CheckFailed);
		Log.Notice("[Login] Guest:%s Check Failed", pUser->m_device.c_str());
		goto end;
	}

	if (!bExit)
	{
		if (!_CreateGuest(pUser))
		{
			Log.Notice("[Login] Guest:%s Create Failed", pUser->m_device.c_str());
			goto end;
		}
	}

	Log.Notice("[Login] Guest(device:%s, uid:"INT64_FMT") Check Success", pUser->m_device.c_str(), pUser->m_id);
	_CheckSuccess(pUser);

end:
	_Shutdown(pUser);

	return true;
}

bool CUserMgr::_HandlePacket_NetAccept(PACKET_COMMAND* pack)
{
	if (!pack)
		return false;

	Message::NetControl msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	SOCKET sock = msg.sock();
	CUser* user = UserMgr.Create(sock);
	if (!user)
		return false;

	user->m_sock = sock;
	user->m_HeartTime = time(NULL);

	return true;
}

bool CUserMgr::_HandlePacket_NetClose(PACKET_COMMAND* pack)
{
	if (!pack)
		return false;

	Message::NetControl msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	SOCKET sock = msg.sock();

	UserMgr.Delete(sock);

	return true;
}

bool CUserMgr::_CheckGuest(CUser* pUser, bool& exit)
{
	exit = g_GetGuestByDevice(pUser->m_device.c_str(), pUser->m_guestid);
	pUser->m_id = MakeUserIdFromGuest(pUser->m_guestid);
	return true;
}

bool CUserMgr::_CreateGuest(CUser* pUser)
{
	pUser->m_guestid = _MakeGuestID();
	pUser->m_id = MakeUserIdFromGuest(pUser->m_guestid);

	return g_SaveGuest(pUser->m_device.c_str(), pUser->m_guestid);
}

void CUserMgr::_Shutdown(CUser* pUser)
{
	if (!pUser)
		return;

	//断开user
	GETCLIENTNET->shutdown(pUser->m_sock);

	UserMgr.Delete(pUser->m_sock);
}

bool CUserMgr::_CheckSuccess(CUser* pUser)
{
	if (!pUser)
		return false;

	//取得该服负载最低的GateServer
	CServerObj* pServer = GETSERVERMGR->GetLowerGate(pUser->m_server);
	if (!pServer)
	{
		Log.Error("[Login] Get Lower GateServer Failed, World:%d User:"INT64_FMT, pUser->m_server, pUser->m_id);
		return false;
	}

	//生成密钥
	int64 session = RandomInt(0x0000, 0xffff);

	Log.Notice("[Login] Allot GateServer(%s:%d) To User(uid:"INT64_FMT", session:%d)", pServer->m_extIP, pServer->m_extPort, pUser->m_id, session);

	//通知GateServer
	Message::LoginSession msg1;
	msg1.set_uid(pUser->m_id);
	msg1.set_key(session);

	PACKET_COMMAND pack1;
	PROTOBUF_CMD_PACKAGE(pack1, msg1, Message::MSG_USER_PRLOGIN_REQUEST);
	GETSERVERNET->sendMsg(pServer->m_Socket, &pack1);

	//通知Client
	Message::ConnectGate msg2;
	msg2.set_uid(pUser->m_id);
	msg2.set_key(session);
	msg2.set_server(pUser->m_server);
	msg2.set_ip(pServer->m_extIP);
	msg2.set_port(pServer->m_extPort);

	PACKET_COMMAND pack2;
	PROTOBUF_CMD_PACKAGE(pack2, msg2, Message::MSG_USER_GET_GATESVR);
	GETCLIENTNET->sendMsg(pUser->m_sock, &pack2);

	return true;
}

bool CUserMgr::_MakeKeys(int64& key)
{
	return true;
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
		SendErrorMsg(pUser, Error_Login_CheckFailed);
		Log.Error("curl curl_easy_perform error: %s", curl_easy_strerror(res));
	}

	GETCLIENTNET->shutdown(pUser->m_sock);
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
	MD5 md5Tool;
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
	char *xmlstr = (char *)buffer;
	if (strlen(xmlstr) < 1024 
		&& ParseXmlString(xmlstr, "msgId", xmlvalue, 32) && strcmp(xmlvalue, "0") == 0
		&& ParseXmlString(xmlstr, "loginStatus", xmlvalue, 32) && strcmp(xmlvalue, "1") == 0
		&& ParseXmlString(xmlstr, "guid", guid, 64) 
		&& ParseXmlString(xmlstr, "accessToken", accessToken, 128)) { //验证成功
		pUser->m_guid = guid;
		pUser->m_accessToken = accessToken;

		UserMgr.sendSWChecker(pUser);
		UserMgr._CheckSuccess(pUser);
	}
	else {
		SendErrorMsg(pUser, Error_Login_CheckFailed);
		Log.Error("check sw_user failed: %lld. return content: %s", pUser->m_id, xmlstr);
	}

	return nmemb;
}

void CUserMgr::sendSWChecker(CUser *pUser)
{
	/*Message::NotifySWChecker msg;
	msg.set_guid(pUser->m_guid);
	msg.set_accesstoken(pUser->m_accessToken);
	msg.set_paysrvip(paysrv_addr);
	msg.set_srvport(paysrv_port);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, L2P_NOTIFY_SW_CHECKER);
	GETCLIENTNET->sendMsg(pUser->m_sock, &pack);*/
}

