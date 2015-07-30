#include "UserMgr.h"
#include "MainServer.h"
#include "Packet.h"
#include "error.h"
#include "MessageTypeDefine.pb.h"
#include "MessageCommon.pb.h"
#include "MessageUser.pb.h"
#include "MessagePlayer.pb.h"

const int g_PacketLimitTime = 10;
static int g_PacketLimitCount = 0;

CUserMgr::CUserMgr()
{

}

CUserMgr::~CUserMgr()
{

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
	while( uid > 0 )
	{
		UserID temp = uid;
		uid = m_KeysList.Next( uid );

		UserKey* ukey = m_KeysList.Find( temp );
		if( !ukey )
		{
			m_KeysList.Remove( temp );
		}
		else if( t - ukey->m_time > m_KeyTimeout )
		{
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
	while( CUser* user = GetObj(sock) )
	{
		sock = m_list.Next(sock);

		if( m_HeartTimeout > 0 && t - user->m_HeartTime > m_HeartTimeout )
		{
			Log.Error("[Heart] Heart Timeout, User:"INT64_FMT, user->m_id);

			Exit( user );
		}
	}
}

bool CUserMgr::OnMsg(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	switch(pack->Type())
	{
	case Message::MSG_REQUEST_USER_HEART:	_HandlePacket_UserHeart(pack);		break;
	case Message::MSG_REQUEST_USER_LOGIN:	_HandlePacket_UserLogin(pack);		break;
	case Message::MSG_REQUEST_USER_LOGOUT:	_HandlePacket_UserLogout(pack);		break;
	case Message::MSG_USER_PRLOGIN_REQUEST:	_HandlePacket_UserPreLogin(pack);	break;
	case Message::MSG_PLAYER_LOGIN_REQUEST:	_HandlePacket_PlayerLogin(pack); break;
	case Message::MSG_REQUEST_PLAYER_CREATE:	_HandlePacket_PlayerCreate(pack);	break;
	case Message::MSG_PLAYER_LOAD_COUNT:	_HandlePacket_PlayerCount(pack);	break;
	case Message::MSG_SERVER_NET_CLOSE:	_HandlePacket_NetClose(pack);		break;
	case Message::MSG_SERVER_NET_ACCEPT:	_HandlePacket_NetAccept(pack);		break;
	case Message::MSG_COMMON_ERROR:		_HandlePacket_GameError(pack);		break;
	case Message::MSG_USER_DISPLACE:	_HandlePacket_UserDisplace(pack);	break;
	default:	return false;
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
	if( !pack )
		return false;

	Message::ClientLogin msg;
	PROTOBUF_CMD_PARSER( pack, msg ); 

	CUser* user = UserMgr.Create(pack->GetNetID());
	if (!user)
		return false;

	TMV t = time(NULL);
	user->m_ClientSock = pack->GetNetID();
	user->m_HeartTime = t;
	user->m_CanCreate = false;
	user->m_PackCount = 0;
	user->m_PackTime = t;

	//验证md5密钥
	if( _CheckUserKey(msg.uid(), msg.key(), pack->GetNetID()) )
	{
		CServerObj* server = GETSERVERMGR->GetLowerGame();
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
			PROTOBUF_CMD_PACKAGE(packet, message, Message::MSG_USER_lOGIN_REQUEST);
			GETSERVERNET->sendMsg(server->m_Socket, &packet);

			//同步服务器时间
			SendHeartResponse(user);
			
			return true;
		}
		else
		{
			Log.Error("[Login] Get GameServer Failed, Socket:%d User:"INT64_FMT, pack->GetNetID(), msg.uid());
		}
	}

	SendErrorMsg( pack->GetNetID(), Error_Login_CheckFailed );

	GETCLIENTNET(GateServer)->shutdown( pack->GetNetID() );

	return false;
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

	CUser* user = GetObj( msg.uid() );
	if( user )
		Displace( user );

	return true;
}

bool CUserMgr::_HandlePacket_UserPreLogin(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::LoginSession msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	_CreateUserKey( msg.uid(), msg.key() );

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

	GETSERVERNET->sendMsg( user->m_GameSock, pack );

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

	GETCLIENTNET->sendMsg(user->m_ClientSock, pack);

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
		GETCLIENTNET->sendMsg(s, pack);
		return true;
	}

	CUser* user = GetUserByUID( msg.userid() );
	if( user )
	{
		GETCLIENTNET->sendMsg(user->m_ClientSock, pack);
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
		GETCLIENTNET->sendMsg(user->m_ClientSock, &packet);
	}
}

void CUserMgr::SendErrorMsg(SOCKET sock, int errid)
{
	Message::ErrorNo msg;
	msg.set_error( errid );

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_COMMON_ERROR);
	GETCLIENTNET->sendMsg(sock, &pack);
}

void CUserMgr::Exit(CUser* user)
{
	if( !user )
		return;

	GETCLIENTNET->shutdown(user->m_ClientSock);

	this->RemoveUser(user);
}

void CUserMgr::Displace(CUser* user)
{
	if(!user)
		return;

	SendErrorMsg(user->m_ClientSock, Error_User_Displace);

	GETCLIENTNET->shutdown(user->m_ClientSock);

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
			GETSERVERNET->sendMsg( user->m_GameSock, &pack );
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
		Log.Debug("[CUserMgr] Receive packet count:%d Time:%d User:"INT64_FMT" Sock:%d", user->m_PackCount, curtime - user->m_PackTime, user->m_id, user->m_ClientSock);

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
