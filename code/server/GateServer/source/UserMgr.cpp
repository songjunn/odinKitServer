#include "UserMgr.h"
#include "GateServer.h"
#include "Packet.h"
#include "error.h"
#include "curl/curl.h"
#include "MessageTypeDefine.pb.h"
#include "MessageCommon.pb.h"
#include "MessageUser.pb.h"
#include "MessageServer.pb.h"
#include "MessagePlayer.pb.h"

const int g_PacketLimitTime = 10;
static int g_PacketLimitCount = 0;

CUserMgr::CUserMgr()
{
    curl_global_init(CURL_GLOBAL_ALL);
}

CUserMgr::~CUserMgr()
{
    curl_global_cleanup();
}

void CUserMgr::InitConfig(int hearttime, int packlimit)
{
    m_HeartTimeout = hearttime;
    g_PacketLimitCount = packlimit * g_PacketLimitTime;
}

bool CUserMgr::OnLogic()
{
    VPROF("CUserMgr::OnLogic");

    _UserHeartLogic();

    return true;
}

void CUserMgr::_UserHeartLogic()
{
    //VPROF("_UserHeartLogic");

    TMV t = time(NULL);
    SOCKET sock = m_list.Head();
    while(CUser* user = GetObj(sock)) {
        sock = m_list.Next(sock);

        if( m_HeartTimeout > 0 && t - user->m_HeartTime > m_HeartTimeout ) {
	    Log.Notice("[Heart] Heart Timeout, User:"INT64_FMT, user->m_id);
	    Exit( user );
	}
    }
}

bool CUserMgr::OnMsg(PACKET_COMMAND* pack)
{
    if (!pack)
	return false;

    switch(pack->Type()) {
        case Message::MSG_REQUEST_USER_HEART:	_HandlePacket_UserHeart(pack);    break;
	case Message::MSG_REQUEST_USER_LOGIN:	_HandlePacket_UserLogin(pack);    break;
	case Message::MSG_REQUEST_USER_LOGOUT:	_HandlePacket_UserLogout(pack);   break;
        case Message::MSG_REQUEST_PLAYER_CREATE:_HandlePacket_PlayerCreate(pack); break;
        case Message::MSG_PLAYER_LOGIN_REQUEST:	_HandlePacket_PlayerLogin(pack);  break;
	case Message::MSG_PLAYER_LOAD_COUNT:	_HandlePacket_PlayerCount(pack);  break;
        case Message::MSG_SERVER_NET_CLOSE:     _HandlePacket_NetClose(pack);     break;
        case Message::MSG_USER_DISPLACE:        _HandlePacket_UserDisplace(pack); break;
	default: return false;
    }

    return true;
}

bool CUserMgr::_HandlePacket_UserHeart(PACKET_COMMAND* pack)
{
    if (!pack)
	return false;

    /*Message::UserHeartRequest msg;
      PROTOBUF_CMD_PARSER( pack, msg );*/

    SendHeartResponse(GetObj(pack->GetNetID()));

    return true;
}

bool CUserMgr::_HandlePacket_UserLogin(PACKET_COMMAND* pack)
{
	Message::ClientLogin msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	CLinker* server = GateServer.getServerByType(CBaseServer::Linker_Server_Game);
	if (!server) {
		Log.Error("User login failed. Cannot find gameserver: user %lld", msg.uid());
		GETCLIENTNET(&GateServer)->shutdown(pack->GetNetID());
		return false;
	}

	CUser* user = UserMgr.Create(pack->GetNetID());
	if (!user) {
		Log.Error("User login failed. Cannot create user: %lld", msg.uid());
		GETCLIENTNET(&GateServer)->shutdown(pack->GetNetID());
		return false;
	}

	CUser* oldUser = GetUserByUID(msg.uid());
	if (oldUser) {
		Displace(oldUser);
		Log.Warning("user %lld relogin, displace the older.", msg.uid());
	}

	TMV t = time(NULL);
	user->m_id = msg.uid();
	user->m_worldID = server->m_worldID;
	user->m_svrID = server->m_nID;
	user->m_ClientSock = pack->GetNetID();
	user->m_GameSock = server->m_Socket;
	user->m_HeartTime = t;
	user->m_CanCreate = false;
	user->m_PackCount = 0;
	user->m_PackTime = t;
	user->m_AccessToken = msg.accesstoken();

	ThreadLib::CreateByPool(httpCheckUserThread, user);

	return true;
}

bool CUserMgr::_HandlePacket_UserLogout(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::UserLogout msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	CUser* user = GetObj( pack->GetNetID() );
	if( user )
		Exit( user );

	return true;
}

bool CUserMgr::_HandlePacket_UserDisplace(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::UserDisplace msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	CUser* user = GetUserByUID(msg.uid());
	if( user )
		Displace( user );

	return true;
}

bool CUserMgr::_HandlePacket_PlayerLogin(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::PlayerLogin msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	CUser* user = GetUserByUID( msg.uid() );
	if( !user )
		return false;

	user->m_LogonPlayer = msg.pid();

	Log.Notice("[Login] Login Sucess, User:"INT64_FMT" Player:"INT64_FMT" Socket:%d", user->m_id, user->m_LogonPlayer, user->m_ClientSock);

	return true;
}

bool CUserMgr::_HandlePacket_PlayerCreate(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::CreatePlayer msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	CUser* user = GetUserByUID( msg.uid() );
	if( !user )
		return false;

	if( !user->m_CanCreate )
		return false;

	GETSERVERNET(&GateServer)->sendMsg( user->m_GameSock, pack );

	return true;
}

bool CUserMgr::_HandlePacket_PlayerCount(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::PlayerCount msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	CUser* user = GetUserByUID( msg.uid() );
	if( !user )
		return false;

	if( msg.player().size() <= 0 )
		user->m_CanCreate = true;

	GETCLIENTNET(&GateServer)->sendMsg(user->m_ClientSock, pack);

	return true;
}

bool CUserMgr::_HandlePacket_NetClose(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::NetControl msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	SOCKET sock = msg.sock();

	CUser* user = UserMgr.GetObj(sock);
	if( user )
		this->RemoveUser(user);

	return true;
}

void CUserMgr::SendHeartResponse(CUser* user)
{
	if (user)
	{
		user->m_HeartTime = time(NULL);

		Message::UserHeartResponse message;
		message.set_stime(user->m_HeartTime);

		PACKET_COMMAND packet;
		PROTOBUF_CMD_PACKAGE(packet, message, Message::MSG_USER_HEART_RESPONSE);
		GETCLIENTNET(&GateServer)->sendMsg(user->m_ClientSock, &packet);
	}
}

void CUserMgr::SendErrorMsg(SOCKET sock, int errid)
{
	Message::ErrorNo msg;
	msg.set_error( errid );

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_COMMON_ERROR);
	GETCLIENTNET(&GateServer)->sendMsg(sock, &pack);
}

void CUserMgr::Exit(CUser* user)
{
	if( !user )
		return;

	GETCLIENTNET(&GateServer)->shutdown(user->m_ClientSock);

	this->RemoveUser(user);
}

void CUserMgr::Displace(CUser* user)
{
	if(!user)
		return;

	SendErrorMsg(user->m_ClientSock, Error_User_Displace);

	GETCLIENTNET(&GateServer)->shutdown(user->m_ClientSock);

	this->RemoveUser(user);
}

void CUserMgr::RemoveUser(CUser* user, bool sync)
{
	if( !user )
		return;

	m_UserLock.LOCK();
	m_UserList.Remove( user->m_id );
	m_UserLock.UNLOCK();

	if( user->m_LogonPlayer > 0 )
	{
		//if( sync )
		{
			Message::PlayerLogout msg;
			msg.set_pid( user->m_LogonPlayer );

			PACKET_COMMAND pack;
			PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_PLAYER_LOGOUT_REQEUST);
			GETSERVERNET(&GateServer)->sendMsg(user->m_GameSock, &pack);
		}
	}

	Log.Notice("[Logout] Remove User:"INT64_FMT, user->m_id);

	Delete( user->m_ClientSock );
}

bool CUserMgr::UserPacketLimit(CUser* user)
{
    if (!user)
	return false;

    if (g_PacketLimitCount <= 0)
	return true;

    TMV curtime = time(NULL);
    if (curtime - user->m_PackTime < g_PacketLimitTime) {
	user->m_PackCount++;
	if (user->m_PackCount >= g_PacketLimitCount) {
	    Log.Error("[CUserMgr] Receive packet too much:%d Time:%d User:"INT64_FMT" Sock:%d", user->m_PackCount, curtime - user->m_PackTime, user->m_id, user->m_ClientSock);
	    Exit(user);
	    return false;
	}
    } else {
	user->m_PackCount = 0;
	user->m_PackTime = curtime;
    }

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
    Log.Debug("httpCheckUser: userid:%lld, address:%s, token:%s", pUser->m_id, GateServer.getAuthAddress().c_str(), pUser->m_AccessToken.c_str());

    char postStr[128] = { 0 };
    sprintf(postStr, "action=2&platform=0&userid=%lld&accesstoken=%s", pUser->m_id, pUser->m_AccessToken.c_str());
    string authUrl = GateServer.getAuthAddress() + ":1313";

    curl_easy_setopt(pUrl, CURLOPT_URL, authUrl.c_str());
    curl_easy_setopt(pUrl, CURLOPT_POSTFIELDS, postStr);
    curl_easy_setopt(pUrl, CURLOPT_WRITEFUNCTION, recvBackData);
    curl_easy_setopt(pUrl, CURLOPT_WRITEDATA, pUser);
    curl_easy_setopt(pUrl, CURLOPT_POST, 1);
    curl_easy_setopt(pUrl, CURLOPT_NOSIGNAL, 1);
    //curl_easy_setopt(pUrl, CURLOPT_VERBOSE, 1);
    //curl_easy_setopt(pUrl, CURLOPT_HEADER, 1);
    //curl_easy_setopt(pUrl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(pUrl, CURLOPT_COOKIEFILE, "curlauth.cookie");
    CURLcode res = curl_easy_perform(pUrl);
    curl_easy_cleanup(pUrl);

    if (res != 0) {
	UserMgr.SendErrorMsg(pUser->m_ClientSock, Error_Login_CheckFailed);
	GETCLIENTNET(&GateServer)->shutdown(pUser->m_ClientSock);
	Log.Error("curl curl_easy_perform error: %s", curl_easy_strerror(res));
	Log.Error("[CUserMgr]Authentication Failed From LoginServer: userid:%lld, address:%s, token:%s", pUser->m_id, GateServer.getAuthAddress().c_str(), pUser->m_AccessToken.c_str());
	return;
    }

    Log.Debug("[CUserMgr]Authentication Successed From LoginServer: userid:%lld, address:%s, token:%s", pUser->m_id, GateServer.getAuthAddress().c_str(), pUser->m_AccessToken.c_str());
}

size_t CUserMgr::recvBackData(void *buffer, size_t nsize, size_t nmemb, void *userp)
{
    if (buffer == NULL) {
        return nsize * nmemb;
    }

    CUser *pUser = (CUser *)userp;
    char *recvdata = (char *)buffer;

    //get result
    char result[16] = {0};
    httpd_get_param(recvdata, "result", result, sizeof(result));

    if (!strcmp(result, "1")) {
        UserMgr.m_UserLock.LOCK();
        UserMgr.m_UserList.Insert(pUser->m_id, pUser);
        UserMgr.m_UserLock.UNLOCK();

        //验证通过，登入游戏
        Message::UserLogin message;
        message.set_uid(pUser->m_id);
        message.set_world(pUser->m_worldID);
        message.set_server(pUser->m_svrID);
        PACKET_COMMAND packet;
        PROTOBUF_CMD_PACKAGE(packet, message, Message::MSG_USER_lOGIN_REQUEST);
        GETSERVERNET(&GateServer)->sendMsg(pUser->m_GameSock, &packet);

        //同步服务器时间
        UserMgr.SendHeartResponse(pUser);
    } else {
        UserMgr.SendErrorMsg(pUser->m_ClientSock, Error_Login_CheckFailed);
        GETCLIENTNET(&GateServer)->shutdown(pUser->m_ClientSock);
        Log.Error("auth user failed: %lld. return content: %s", pUser->m_id, recvdata);
    }

    return nsize * nmemb;
}

