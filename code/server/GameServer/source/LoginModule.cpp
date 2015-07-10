#include "LoginModule.h"
#include "error.h"
#include "User.h"
#include "UserMgr.h"
#include "PlayerMgr.h"
#include "NameText.h"
#include "PacketDefine.h"
#include "ServerMgr.h"
#include "MainServer.h"
#include "NoticeModule.h"
#include "LuaEngine.h"
#include "Event.h"
#include "gtime.h"
#include "MessageUserLogin.pb.h"
#include "MessagePlayerLogin.pb.h"
#include "MessagePlayerCount.pb.h"
#include "MessageReqPlayerData.pb.h"
#include "MessagePlayerLogout.pb.h"
#include "MessageCreatePlayer.pb.h"
#include "MessageLoadWorldData.pb.h"
#include "MessageCheckNameRequest.pb.h"
#include "MessageCheckNameResponse.pb.h"
#include "MessagePlayerLoadOver.pb.h"
#include "MessageUserDisplace.pb.h"


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
	case D2G_REQUEST_LOGIN_GAMEWORLD:	_HandlePacket_PlayerLogin(pack);	break;
	case A2D_REQUEST_USER_LOGIN:		_HandlePacket_UserLogin(pack);		break;
	case A2G_NOTIFY_PLAYER_LOGOUT:		_HandlePacket_PlayerLogout(pack);	break;
	case D2P_NOTIFY_PLAYER_COUNT:		_HandlePacket_PlayerCount(pack);	break;
	case P2D_REQUEST_PLAYER_CREATE:		_HandlePacket_PlayerCreate(pack);	break;
	case G2D_RESPONSE_CHECK_NAME:		_HandlePacket_PlayerOnCreate(pack);	break;
	case D2G_NOTIFY_WORLD_DATA:			_HandlePacket_LoadWorldData(pack);	break;
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
			PROTOBUF_CMD_PACKAGE( packKick, msgKick, G2A_NOTIFY_USER_DISPLACE );
			pUser->SendGateMsg( &packKick );
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

			_OnPlayerSync(player);

			CEvent* evnt = MakeEvent(Event_Player_Login, player->GetID(), NULL, true);
			player->OnEvent(evnt);

			Log.Notice("[Login] Displace Online User:"INT64_FMT" Player:"INT64_FMT" Name:%s", player->GetFieldI64(Role_Attrib_UserID), player->GetID(), player->GetName());
		}
		else
		{
			Log.Debug("[Login] Online User not have player: (User:"INT64_FMT", Player:"INT64_FMT")", pUser->m_ID, pUser->GetLoginPlayer());

			//向GateServer同步该账号无角色
			Message::PlayerCount msgCount;
			msgCount.set_uid( msg.uid() );
			//msgCount.set_count( 0 );

			PACKET_COMMAND packCount;
			PROTOBUF_CMD_PACKAGE( packCount, msgCount, D2P_NOTIFY_PLAYER_COUNT );
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

		//向data发送请求，加载角色数据
		MainServer.SendMsgToServer(ServerMgr.getDataSock(), pack);
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

	pUser->SendGateMsg(pack);

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
	PROTOBUF_CMD_PACKAGE( pack1, msg1, G2D_REQUEST_CHECK_NAME );
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

	//通知DataServer创建
	Message::CreatePlayer msgCreate;
	msgCreate.set_name( player->GetName() );
	msgCreate.set_roletemplate( player->GetFieldInt(Role_Attrib_TemplateID) );
	msgCreate.set_uid( player->GetFieldI64(Role_Attrib_UserID) );
	msgCreate.set_stunt( player->GetFieldInt(Role_Attrib_UseStuntSkill) );
	msgCreate.set_quality( player->GetFieldInt(Role_Attrib_Quality) );
	msgCreate.set_pid( player->GetID() );
	PACKET_COMMAND packCreate;
	PROTOBUF_CMD_PACKAGE( packCreate, msgCreate, P2D_REQUEST_PLAYER_CREATE );
	player->SendDataMsg( &packCreate );

	//执行脚本
	LuaParam param[1];
	param[0].SetDataNum( player->GetID() );
	if( !LuaEngine.RunLuaFunction("OnCreate", "Player", NULL, param, 1) )
	{
		Log.Debug("[Login] RunLuaFunction Error, Player:"INT64_FMT" User:"INT64_FMT, player->GetID(), msg.uid());
		PlayerMgr.Delete( player->GetID() );
		return false;
	}

	CEvent* evnt = MakeEvent(Event_Player_Create, player->GetID(), player->GetFieldI64(Role_Attrib_UserID), NULL, true);
	player->OnEvent(evnt);

	OnPlayerLogin(player);

	return true;
}

bool CLoginModule::_HandlePacket_LoadWorldData(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::LoadWorldData msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	int64 id = msg.playerid() > 0 ? msg.playerid() : g_MakeInitPlayerID(MainServer.World());

	PlayerMgr.SetLoadFactID(id);

	return true;
}

bool CLoginModule::OnPlayerLogin(CPlayer* player)
{
	if( !player )
		return false;

	//player->DataInit();  //移到CPlayerMgr::_HandlePacket_PlayerLoadOver
	player->SetOnline(Online_Flag_On);
	player->SetFieldI64(Role_Attrib_LoginTime, GetTimeSec(), false, true);
	player->SyncFieldInt(Role_Attrib_Fighting, false, true );

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

	//通知GateServer创建成功并登陆
	Message::PlayerLogin msgLogin;
	msgLogin.set_uid(player->GetFieldI64(Role_Attrib_UserID));
	msgLogin.set_pid(player->GetID());
	PACKET_COMMAND packLogin;
	PROTOBUF_CMD_PACKAGE(packLogin, msgLogin, D2G_REQUEST_LOGIN_GAMEWORLD);
	player->SendClientMsg(&packLogin);

	player->DataSync();

	//执行脚本
	LuaParam param[1];
	param[0].SetDataNum( player->GetID() );
	LuaEngine.RunLuaFunction("OnLogin", "Player", NULL, param, 1);

	//加载结束
	Message::PlayerLoadOver msg;
	msg.set_pid(player->GetID());
	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, D2G_NOTIFY_PLAYER_LOADOVER);
	player->SendClientMsg(&pack);

	return true;
}

bool CLoginModule::OnPlayerLogout(PersonID id)
{
	CPlayer* player = PlayerMgr.GetObj( id );
	if( !player )
		return false;

	//下线前同步属性存盘
	player->SetFieldI64(Role_Attrib_LogoutTime, GetTimeSec(), false, true);

	//登出事件
	CEvent* evnt = MakeEvent(Event_Player_Logout, player->GetID(), NULL, true);
	player->OnEvent(evnt);

	//通知dataserver
	Message::PlayerLogout msg;
	msg.set_pid( id );

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE( pack, msg, A2G_NOTIFY_PLAYER_LOGOUT );
	player->SendDataMsg( &pack );

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
		return;

	OnPlayerLogin(player);
}
