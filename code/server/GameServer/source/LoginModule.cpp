#include "LoginModule.h"
#include "error.h"
#include "User.h"
#include "UserMgr.h"
#include "PlayerMgr.h"
#include "NameText.h"
#include "GameServer.h"
#include "NoticeModule.h"
#include "DataModule.h"
#include "LuaEngine.h"
#include "Event.h"
#include "gtime.h"
#include "MessageTypeDefine.pb.h"
#include "MessageServer.pb.h"
#include "MessageUser.pb.h"
#include "MessagePlayer.pb.h"
#include "MessageGameobj.pb.h"


CLoginModule::CLoginModule()
{
	SetDefLessFunc(m_LoginMap);
}

CLoginModule::~CLoginModule()
{
}

bool CLoginModule::OnMsg(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	switch( pack->Type() )
	{
	case Message::MSG_PLAYER_LOGIN_REQUEST:		_HandlePacket_PlayerLogin(pack);	break;
	case Message::MSG_USER_lOGIN_REQUEST:		_HandlePacket_UserLogin(pack);		break;
	case Message::MSG_PLAYER_LOGOUT_REQEUST:	_HandlePacket_PlayerLogout(pack);	break;
	case Message::MSG_PLAYER_LOAD_COUNT:		_HandlePacket_PlayerCount(pack);	break;
	case Message::MSG_REQUEST_PLAYER_CREATE:	_HandlePacket_PlayerCreate(pack);	break;
	case Message::MSG_PLAYER_CHECKNAME_RESPONSE:_HandlePacket_PlayerOnCreate(pack);	break;
	case Message::MSG_SERVER_WORLD_RESPONSE:	_HandlePacket_LoadWorldData(pack);	break;
	default:	return false;
	}

	return true;
}

bool CLoginModule::_HandlePacket_UserLogin(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::UserLogin msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	CUser* pUser = UserMgr.GetObj( msg.uid() );
	if( pUser )
	{
		if( pUser->m_GateSocket != pack->GetNetID() )
		{
			//发送踢号
			Message::UserDisplace msgKick;
			msgKick.set_uid( msg.uid() );
			PACKET_COMMAND packKick;
			PROTOBUF_CMD_PACKAGE(packKick, msgKick, Message::MSG_USER_DISPLACE);
			pUser->SendGateMsg( &packKick );

			Log.Notice("[Login] Displace Online User:"INT64_FMT, player->GetFieldI64(Role_Attrib_UserID));
		}

		pUser->m_GateSocket = pack->GetNetID();

		if( pUser->HavePlayer() )
		{
			PersonID pid = pUser->GetLoginPlayer();
			CPlayer* player = PlayerMgr.GetObj(pid);
			if( !player )
			{
				Log.Error("[Login] Player Error(User:"INT64_FMT", Player:"INT64_FMT")", pUser->m_ID, pid);
				return false;
			}

			OnPlayerLogin(player);
		}
		else
		{
			Log.Debug("[Login] Online User not have player: (User:"INT64_FMT", Player:"INT64_FMT")", pUser->m_ID, pUser->GetLoginPlayer());

			//向GateServer同步该账号无角色
			Message::PlayerCount msgCount;
			msgCount.set_uid( msg.uid() );
			//msgCount.set_count( 0 );

			PACKET_COMMAND packCount;
			PROTOBUF_CMD_PACKAGE(packCount, msgCount, Message::MSG_PLAYER_LOAD_COUNT);
			pUser->SendGateMsg( &packCount );
		}
	}
	else
	{
		pUser = UserMgr.Create( msg.uid() );
		if( !pUser )
			return false;

		pUser->m_ID = msg.uid();
		pUser->m_GateSocket = pack->GetNetID();

		Message::UserLogin message;
		message.set_uid(msg.uid());
		message.set_world(msg.world());
		message.set_server(msg.server());
		message.set_type("player");
		message.set_key("userid");

		//向data发送请求，加载角色数据
		PACKET_COMMAND packet;
		PROTOBUF_CMD_PACKAGE(packet, message, Message::MSG_USER_lOGIN_REQUEST);
		GETSERVERNET(&GameServer)->sendMsg(GameServer.getServerSock(CBaseServer::Linker_Server_Data), &packet);
	}

	Log.Notice( "[Login] User:"INT64_FMT, msg.uid() );

	return true;
}

bool CLoginModule::_HandlePacket_PlayerLogin(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::PlayerLogin msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	CUser* pUser = UserMgr.GetObj( msg.uid() );
	if( !pUser )
		return false;

	CPlayer* player = PlayerMgr.GetObj( msg.pid() );
	if( !player )
	{
		player = PlayerMgr.Create( msg.templateid(), msg.pid() );
		if( !player )
		{
			Log.Error("[Login] no player, User:"INT64_FMT" Player:"INT64_FMT, msg.uid(), msg.pid());
			return NULL;
		}
	}

	pUser->RelatePlayer( player->GetID() );
	player->SetLoadTime(timeGetTime());
	player->SetOnline(Online_Flag_Load);
	player->SetFieldI64( Role_Attrib_UserID, msg.uid() );
	player->SetGateSocket( pUser->m_GateSocket );

	m_LoginMap.Insert(msg.pid(), msg.pid());

	return true;
}

bool CLoginModule::_HandlePacket_PlayerLogout(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::PlayerLogout msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	return OnPlayerLogout( msg.pid() );
}

bool CLoginModule::_HandlePacket_PlayerCount(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::PlayerCount msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	CUser* pUser = UserMgr.GetObj( msg.uid() );
	if( !pUser )
		return false;

	if( msg.player_size() <= 0 )
	{	
		pUser->SendGateMsg(pack);
	}
	else
	{
		PersonID playerid = msg.player(0);
		m_LoginMap.Insert(playerid, playerid);

		Message::ReqPlayerData msgData;
		msgData.set_pid(playerid);
		msgData.set_type("player");
		msgData.set_key("playerid");
		
		PACKET_COMMAND packData;
		PROTOBUF_CMD_PACKAGE(packData, msgData, Message::MSG_GAMEOBJ_REQUEST);
		GETSERVERNET(&GameServer)->sendMsg(GameServer.getServerSock(CBaseServer::Linker_Server_Data), &packData);
	}

	return true;
}

bool CLoginModule::_HandlePacket_PlayerCreate(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::CreatePlayer msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	//验证名字合法性
	if( !NameTextMgr.CheckName(msg.name().c_str()) )
	{
		NoticeModule.SendErrorMsg(pack->GetNetID(), msg.uid(), Error_Create_NameInvalid);
		Log.Error("[Login] Check Name Invalid:%s User:"INT64_FMT, msg.name().c_str(), msg.uid());
		return false;
	}

	//以职业作为模板id
	CPlayer* player = PlayerMgr.Create( msg.roletemplate() );
	if( !player )
		return false;

	player->m_GameObj->setFieldI64("playerid", player->GetID());
	player->m_GameObj->setFieldI64("userid", msg.uid());
	player->m_GameObj->setFieldString("name", msg.name().c_str());
	player->m_GameObj->setFieldInt("template", msg.roletemplate());

	player->SetLoadTime(timeGetTime());
	player->SetOnline(Online_Flag_Load);
	player->SetName( msg.name().c_str() );
	player->SetFieldI64( Role_Attrib_UserID, msg.uid() );
	player->SetGateSocket( pack->GetNetID() );

	//验证重名
	Message::CheckNameRequest msg1;
	msg1.set_uid( msg.uid() );
	msg1.set_pid( player->GetID() );
	msg1.set_name( msg.name().c_str() );
	PACKET_COMMAND pack1;
	PROTOBUF_CMD_PACKAGE(pack1, msg1, Message::MSG_PLAYER_CHECKNAME_REQUEST);
	player->SendDataMsg( &pack1 );

	return true;
}

bool CLoginModule::_HandlePacket_PlayerOnCreate(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::CheckNameResponse msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	CPlayer* player = PlayerMgr.GetObj( msg.pid() );
	if( !player )
		return false;

	if( !msg.result() )
	{
		NoticeModule.SendErrorMsg(player->GetGateSocket(), player->GetFieldI64(Role_Attrib_UserID), Error_Create_NameRepeat);
		Log.Debug("[Login] Check Name Repeat:%s User:"INT64_FMT, player->GetName(), msg.uid());
		PlayerMgr.Delete( msg.pid() );
		return false;
	}

	//执行脚本
	LuaParam param[1];
	param[0].SetDataNum( player->GetID() );
	if( !LuaEngine.RunLuaFunction("OnCreate", "Player", NULL, param, 1) )
	{
		Log.Debug("[Login] RunLuaFunction Error, Player:"INT64_FMT" User:"INT64_FMT, player->GetID(), msg.uid());
		PlayerMgr.Delete( player->GetID() );
		return false;
	}
	//同步DataServer创建
	DataModule.syncCreate(player->m_GameObj, GameServer.getServerSock(CBaseServer::Linker_Server_Data));

	CEvent* evnt = MakeEvent(Event_Player_Create, player->GetID(), player->GetFieldI64(Role_Attrib_UserID), NULL, true);
	player->OnEvent(evnt);

	OnPlayerLogin(player);

	return true;
}

bool CLoginModule::_HandlePacket_LoadWorldData(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::WorldDataResponse msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	int64 id = msg.playerid() > 0 ? msg.playerid() : g_MakeInitPlayerID(GameServer.getSelfWorld());

	PlayerMgr.SetLoadFactID(id);

	return true;
}

bool CLoginModule::OnPlayerLogin(CPlayer* player)
{
	if( !player )
		return false;

	//执行脚本
	LuaParam param[1];
	param[0].SetDataNum(player->GetID());
	LuaEngine.RunLuaFunction("OnLogin", "Player", NULL, param, 1);

	player->SetOnline(Online_Flag_On);
	player->SetFieldI64(Role_Attrib_LoginTime, GetTimeSec());

	_OnPlayerSync(player);

	CEvent* evnt = MakeEvent(Event_Player_Login, player->GetID(), NULL, true);
	player->OnEvent(evnt);

	Log.Notice("[Login] Online User:"INT64_FMT" Player:"INT64_FMT" Name:%s", player->GetFieldI64(Role_Attrib_UserID), player->GetID(), player->GetName());

	return true;
}

bool CLoginModule::_OnPlayerSync(CPlayer* player)
{
	if( !player )
		return false;

	//同步客户端
	{
		Message::PlayerLogin msgLogin;
		msgLogin.set_uid(player->GetFieldI64(Role_Attrib_UserID));
		msgLogin.set_pid(player->GetID());
		PACKET_COMMAND packLogin;
		PROTOBUF_CMD_PACKAGE(packLogin, msgLogin, Message::MSG_PLAYER_LOGIN_REQUEST);
		player->SendClientMsg(&packLogin);

		player->DataSync();

		Message::PlayerLoadOver msg;
		msg.set_pid(player->GetID());
		PACKET_COMMAND pack;
		PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_PLAYER_LOAD_OVER);
		player->SendClientMsg(&pack);
	}

	// 同步DataServer
	player->SyncFieldToData("login");
	player->SyncFieldToData("attr");

	return true;
}

bool CLoginModule::OnPlayerLogout(PersonID id)
{
	CPlayer* player = PlayerMgr.GetObj( id );
	if( !player )
		return false;

	//下线前同步属性存盘
	player->SetFieldI64(Role_Attrib_LogoutTime, GetTimeSec(), false);
	player->SyncFieldToData("login");

	//登出事件
	CEvent* evnt = MakeEvent(Event_Player_Logout, player->GetID(), NULL, true);
	player->OnEvent(evnt);

	//通知dataserver
	Message::PlayerLogout msg;
	msg.set_pid( id );

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_PLAYER_LOGOUT_REQEUST);
	player->SendDataMsg( &pack );
	//同步DataServer创建
	DataModule.syncRemove(player->m_GameObj, GameServer.getServerSock(CBaseServer::Linker_Server_Data));

	Log.Notice("[Logout] Online User:"INT64_FMT" Player:"INT64_FMT, player->GetFieldI64(Role_Attrib_UserID), id);

	UserMgr.Delete( player->GetFieldI64(Role_Attrib_UserID) );
	PlayerMgr.Delete( id );

	return true;
}

void CLoginModule::eventPlayerLoadover(PersonID id)
{
	int idx = m_LoginMap.Find(id);
	if( !m_LoginMap.IsValidIndex(idx) )
		return;
	m_LoginMap.RemoveAt(idx);

	CPlayer* player = PlayerMgr.GetObj(id);
	if( !player )
	{
		CMetadata* json = DataModule.GetObj( id );
		if( !json )
			return;

		player = PlayerMgr.Create( json->getFieldInt("template"), id );
		if( !player )
			return;
	}

	CUser* pUser = UserMgr.GetObj( player->GetFieldI64(Role_Attrib_UserID) );
	if( !pUser )
	{
		PlayerMgr.Delete(id);
		return;
	}

	pUser->RelatePlayer( player->GetID() );
	player->SetGateSocket( pUser->m_GateSocket );
	player->SetLoadTime(timeGetTime());
	player->SetOnline(Online_Flag_Load);

	OnPlayerLogin(player);
}
