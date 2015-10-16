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
    memset(m_paySvr, 0, sizeof(m_paySvr));
    m_payPort = 0;

    curl_global_init(CURL_GLOBAL_ALL);
}

CUserMgr::~CUserMgr()
{
    curl_global_cleanup();
}

void CUserMgr::InitConfig(int keytime, int hearttime, int packlimit)
{
    m_KeyTimeout = keytime;
    m_HeartTimeout = hearttime;
    g_PacketLimitCount = packlimit * g_PacketLimitTime;

    m_KeysList.Purge(1000);
}

bool CUserMgr::OnLogic()
{
    VPROF("CUserMgr::OnLogic");
    _UserKeyLogic();
    _UserHeartLogic();

    return true;
}

void CUserMgr::_UserKeyLogic()
{
    //VPROF("_UserKeyLogic");

    TMV t = time(NULL);

    UserID uid = m_KeysList.Head();
    while( uid > 0 ) {
	UserID temp = uid;
	uid = m_KeysList.Next( uid );

	UserKey* ukey = m_KeysList.Find( temp );
	if( !ukey ) {
	    m_KeysList.Remove( temp );
	}
	else if( t - ukey->m_time > m_KeyTimeout ) {
	    Log.Notice("[Login] User Key Timeout ("INT64_FMT":"INT64_FMT")", ukey->m_id, ukey->m_key);
	    m_KeysList.Remove( temp );
	    SAFE_DELETE( ukey );
	}
    }
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
    if( !pack )
	return false;

    switch(pack->Type()) {
        case Message::MSG_REQUEST_USER_HEART:	_HandlePacket_UserHeart(pack);    break;
	case Message::MSG_REQUEST_USER_LOGIN:	_HandlePacket_UserLogin(pack);    break;
	case Message::MSG_REQUEST_USER_LOGOUT:	_HandlePacket_UserLogout(pack);   break;
        case Message::MSG_REQUEST_PLAYER_CREATE:_HandlePacket_PlayerCreate(pack); break;
        case Message::MSG_PLAYER_LOGIN_REQUEST:	_HandlePacket_PlayerLogin(pack);  break;
	case Message::MSG_PLAYER_LOAD_COUNT:	_HandlePacket_PlayerCount(pack);  break;
        case Message::MSG_SERVER_NET_CLOSE:     _HandlePacket_NetClose(pack);     break;
        case Message::MSG_SERVER_NET_ACCEPT:    _HandlePacket_NetAccept(pack);    break;
	case Message::MSG_COMMON_ERROR:		_HandlePacket_GameError(pack);    break;
	case Message::MSG_USER_DISPLACE:	_HandlePacket_UserDisplace(pack); break;
        case Message::L2A_RESPONSE_AUTH_CHECKER:_HandlePacket_AuthSuccess(pack);  break;
	default: return false;
    }

    return true;
}

bool CUserMgr::_HandlePacket_UserHeart(PACKET_COMMAND* pack)
{
    if( !pack )
	return false;

    /*Message::UserHeartRequest msg;
      PROTOBUF_CMD_PARSER( pack, msg );*/

    SendHeartResponse(GetObj(pack->GetNetID()));

    return true;
}

bool CUserMgr::_HandlePacket_UserLogin(PACKET_COMMAND* pack)
{
    /*if( !pack )
      return false;

      Message::ClientLogin msg;
      PROTOBUF_CMD_PARSER( pack, msg );

      //验证md5密钥
      if( _CheckUserKey(msg.uid(), msg.key(), pack->GetNetID()) )
	{
		CUser* user = GetObj(pack->GetNetID());
		if( user )
		{
			CServerObj* server = ServerMgr.GetLowerGame();
			if( server )
			{
				CUser* oldUser = GetUserByUID(msg.uid());
				if( oldUser )
					Displace( oldUser );

				user->m_id = msg.uid();
				user->m_ClientSock = pack->GetNetID();
				user->m_GameSock = server->m_Socket;
				user->m_HeartTime = time(NULL);

				m_UserLock.LOCK();
				m_UserList.Insert( user->m_id, user );
				m_UserLock.UNLOCK();

				//验证通过，登入游戏
				Message::UserLogin message;
				message.set_uid( user->m_id );
				message.set_world( server->m_worldID );
				message.set_server( server->m_nID );

				PACKET_COMMAND packet;
				PROTOBUF_CMD_PACKAGE( packet, message, A2D_REQUEST_USER_LOGIN );
				MainServer.SendMsgToServer(server->m_Socket, &packet);

				//同步服务器时间
				SendHeartResponse(user);

				return true;
			}
			else
			{
				Log.Error("[Login] Get GameServer Failed, Socket:%d User:"INT64_FMT, pack->GetNetID(), msg.uid());
			}
		}
	}

	SendErrorMsg( pack->GetNetID(), Error_Login_CheckFailed );

	GateNet.Shutdown( pack->GetNetID() );

	return false;
	*/

	Message::ClientLogin msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	CUser *user = GetObj(pack->GetNetID());
	CServerObj* server = ServerMgr.GetLowerGame();
	if (!user || !server) {
		Log.Error("User login failed.Cannot find user or gameserver: packe %d, user %lld", pack->GetNetID(), msg.uid());
		SendErrorMsg(pack->GetNetID(), Error_Login_CheckFailed);
		GateNet.Shutdown(pack->GetNetID());
		return false;
	}

	CUser* oldUser = GetUserByUID(msg.uid());
	if (oldUser) {
		Displace(oldUser);
		Log.Warning("user %lld relogin, displace the older.", msg.uid());
	}

	user->m_id = msg.uid();
	user->m_worldID = server->m_worldID;
	user->m_svrID = server->m_nID;
	user->m_ClientSock = pack->GetNetID();
	user->m_GameSock = server->m_Socket;
	user->m_HeartTime = time(NULL);
	user->m_AccessToken = msg.accesstoken();
	user->m_AuthAddress = msg.authaddress();

	ThreadLib::CreateByPool(httpCheckUserThread, user);

	/*Message::ClientLogin msg2;
	msg2.set_uid(user->m_id);
	msg2.set_accesstoken(user->m_AccessToken);
	msg2.set_key(user->m_ClientSock);

	PACKET_COMMAND pack2;
	PROTOBUF_CMD_PACKAGE(pack2, msg2, A2L_REQUEST_AUTH_CHECKER);
	MainServer.SendMsgToServer(ServerMgr.getLoginSock(), &pack2);*/

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

	CUser* user = /*GetObj( msg.uid() )*/ GetUserByUID(msg.uid());
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

	m_PlayerList.Insert( msg.pid(), user );

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

bool CUserMgr::_HandlePacket_GameError(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::ErrorNo msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	SOCKET s = GetNetIDByPID( pack->GetTrans() );
	if( s != INVALID_SOCKET )
	{
		GETCLIENTNET(&GateServer)->sendMsg(s, pack);
		return true;
	}

	CUser* user = GetUserByUID( msg.userid() );
	if( user )
	{
		GETCLIENTNET(&GateServer)->sendMsg(user->m_ClientSock, pack);
		return true;
	}

	return true;
}

bool CUserMgr::_HandlePacket_NetAccept(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::NetControl msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	SOCKET sock = msg.sock();
	CUser* user = UserMgr.Create(sock);
	if( !user )
		return false;
	
	TMV t = time(NULL);
	user->m_ClientSock = sock;
	user->m_HeartTime = t;
	user->m_CanCreate = false;
	user->m_PackCount = 0;
	user->m_PackTime = t;

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
		UserMgr.RemoveUser(user);

	return true;
}

bool CUserMgr::_HandlePacket_SWCharge(PACKET_COMMAND* pack)
{
	Message::SWChargeChecker msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	CUser *pUser = GetUserByUID(msg.userid());
	if (!pUser) {
		Log.Error("_HandlePacket_SWCharge !pUser. user: %lld, money: %d", msg.userid(), msg.money());
		return false;
	}

	Message::SWChargeChecker msg2;
	msg2.set_playerid(pUser->m_LogonPlayer);
	msg2.set_money(msg.money());

	PACKET_COMMAND pack2;
	PROTOBUF_CMD_PACKAGE(pack2, msg2, S2S_NOTIFY_SWCHARGE);
	MainServer.SendMsgToServer(pUser->m_GameSock, &pack2);

	Log.Notice("SWCharge. user: %lld, player: %lld, money: %d", pUser->m_id, pUser->m_LogonPlayer, msg.money());

	return true;
}

bool CUserMgr::_HandlePacket_UserForbidden(PACKET_COMMAND* pack)
{
	Message::ManageResponse msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	UserID uid = msg.userid();
	CUser *pUser = GetUserByUID(uid);
	if (!pUser) {
		Log.Error("The forbidden user %lld is not online.", uid);
		return false;
	}

	SendErrorMsg(pUser->m_ClientSock, Error_User_Forbid);

	GateNet.Shutdown(pUser->m_ClientSock);

	return true;
}

bool CUserMgr::_HandlePacket_AuthSuccess(PACKET_COMMAND* pack)
{
	Message::ClientLogin msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	CUser *user = GetObj((SOCKET)msg.key());
	if (!user) {
		Log.Error("Auth success but user %lld not exist.", msg.uid());
		return false;
	}

	if (user->m_id == msg.uid() && user->m_AccessToken == msg.accesstoken()) {
		UserMgr.m_UserLock.LOCK();
		UserMgr.m_UserList.Insert(user->m_id, user);
		UserMgr.m_UserLock.UNLOCK();

		//验证通过，登入游戏
		Message::UserLogin message;
		message.set_uid(user->m_id);
		message.set_world(user->m_worldID);
		message.set_server(user->m_svrID);
		PACKET_COMMAND packet;
		PROTOBUF_CMD_PACKAGE(packet, message, A2D_REQUEST_USER_LOGIN);
		MainServer.SendMsgToServer(user->m_GameSock, &packet);

		//验证成功，回应客户端
		Message::AuthSuccess message2;
		message2.set_paysvr(UserMgr.m_paySvr);
		message2.set_payport(UserMgr.m_payPort);
		PACKET_COMMAND packet2;
		PROTOBUF_CMD_PACKAGE(packet2, message2, A2P_RESPONSE_AUTH_SUCCESS);
		GateNet.SendMsg(user->m_ClientSock, &packet2);

		//同步服务器时间
		UserMgr.SendHeartResponse(user);
	}
	else {
		UserMgr.SendErrorMsg(user->m_ClientSock, Error_Login_CheckFailed);
		GateNet.Shutdown(user->m_ClientSock);
		Log.Error("auth user failed: %lld.", user->m_id);
	}
}

bool CUserMgr::_CheckUserKey(UserID id, int64 key, SOCKET sock)
{
	UserKey* ukey = m_KeysList.Find( id );
	if( !ukey )
	{
		Log.Error("[Login] Check Key Failed, Not Found UserID, User:"INT64_FMT" Socket:%d", id, sock);
		return false;
	}

	if( ukey->m_key != key )
	{
		Log.Error("[Login] Check Key Failed, User:"INT64_FMT" Socket:%d", id, sock);
		return false;
	}
	else
	{
		Log.Notice("[Login] Check Key Success, User:"INT64_FMT" Socket:%d", id, sock);
	}

	SAFE_DELETE( ukey );

	m_KeysList.Remove( id );

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

		m_PlayerList.Remove( user->m_LogonPlayer );
	}

	Log.Notice("[Logout] Remove User:"INT64_FMT, user->m_id);

	Delete( user->m_ClientSock );
}

void CUserMgr::_CreateUserKey(UserID id, int64 key)
{
	UserKey* ukey = NEW UserKey;
	if( !key )
		return;

	ukey->m_id = id;
	ukey->m_key = key;
	ukey->m_time = time(NULL);

	m_KeysList.Insert(id, ukey);
}

bool CUserMgr::UserPacketLimit(CUser* user)
{
	if( !user )
		return false;

	if( g_PacketLimitCount <= 0 )
		return true;

	TMV curtime = time(NULL);
	if( curtime - user->m_PackTime < g_PacketLimitTime )
	{
		user->m_PackCount++;
		if( user->m_PackCount >= g_PacketLimitCount )
		{
			Log.Error("[CUserMgr] Receive packet too much:%d Time:%d User:"INT64_FMT" Sock:%d", user->m_PackCount, curtime - user->m_PackTime, user->m_id, user->m_ClientSock);
			Exit(user);
			return false;
		}
	}
	else
	{
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
	Log.Debug("httpCheckUser: userid:%lld, address:%s, token:%s", pUser->m_id, pUser->m_AuthAddress.c_str(), pUser->m_AccessToken.c_str());

	if (pUser->m_AuthAddress == "") {
		Log.Error("pUser->m_AuthAddress = '', user: %lld", pUser->m_id);
		return;
	}

	char postStr[128] = { 0 };
	sprintf(postStr, "userid=%lld&accesstoken=%s", pUser->m_id, pUser->m_AccessToken.c_str());
	string authUrl = pUser->m_AuthAddress + ":1313";

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
		GateNet.Shutdown(pUser->m_ClientSock);
		Log.Error("curl curl_easy_perform error: %s", curl_easy_strerror(res));
		Log.Error("[CUserMgr]Authentication Failed From LoginServer: userid:%lld, address:%s, token:%s", pUser->m_id, pUser->m_AuthAddress.c_str(), pUser->m_AccessToken.c_str());
		return;
	}

	Log.Debug("[CUserMgr]Authentication Successed From LoginServer: userid:%lld, address:%s, token:%s", pUser->m_id, pUser->m_AuthAddress.c_str(), pUser->m_AccessToken.c_str());
}

size_t CUserMgr::recvBackData(void *buffer, size_t nsize, size_t nmemb, void *userp)
{
	CUser *pUser = (CUser *)userp;
	char *recvdata = (char *)buffer;
	if (recvdata && recvdata[0] && recvdata[0] == '0') {
		UserMgr.m_UserLock.LOCK();
		UserMgr.m_UserList.Insert(pUser->m_id, pUser);
		UserMgr.m_UserLock.UNLOCK();

		//验证通过，登入游戏
		Message::UserLogin message;
		message.set_uid(pUser->m_id);
		message.set_world(pUser->m_worldID);
		message.set_server(pUser->m_svrID);
		PACKET_COMMAND packet;
		PROTOBUF_CMD_PACKAGE(packet, message, A2D_REQUEST_USER_LOGIN);
		MainServer.SendMsgToServer(pUser->m_GameSock, &packet);

		//验证成功，回应客户端
		Message::AuthSuccess message2;
		message2.set_paysvr(UserMgr.m_paySvr);
		message2.set_payport(UserMgr.m_payPort);
		PACKET_COMMAND packet2;
		PROTOBUF_CMD_PACKAGE(packet2, message2, A2P_RESPONSE_AUTH_SUCCESS);
		GateNet.SendMsg(pUser->m_ClientSock, &packet2);

		//同步服务器时间
		UserMgr.SendHeartResponse(pUser);
	}
	else {
		UserMgr.SendErrorMsg(pUser->m_ClientSock, Error_Login_CheckFailed);
		GateNet.Shutdown(pUser->m_ClientSock);
		Log.Error("auth user failed: %lld. return content: %s", pUser->m_id, recvdata);
	}

	return nsize * nmemb;
}

bool CUserMgr::SetPayAddress(const char *paySvr, int payPort)
{
	if (!paySvr || strlen(paySvr) >= 32 || payPort < 1) {
		return false;
	}

	strcpy(m_paySvr, paySvr);
	m_payPort = payPort;

	return true;
}

