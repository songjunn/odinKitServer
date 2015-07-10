#include "RobotObj.h"
#include "RobotNet.h"
#include "RobotMgr.h"
#include "gtime.h"
#include "Packet.h"
#include "PacketDefine.h"
#include "MessageGuestCheck.pb.h"
#include "MessageClientLogin.pb.h"
#include "MessageCreatePlayer.pb.h"
#include "MessageUserLogout.pb.h"
#include "MessageAttackMonsterRequest.pb.h"
#include "MessageNetTestRequest.pb.h"
#include "MessageDebugRequest.pb.h"
#include "MessageChat.pb.h"
#include "MessageObservePlayerRequest.pb.h"
#include "LuaEngine.h"
#include "MessageWorshiping.pb.h"
#include "MessageSignInSys.pb.h"
#include "MessageBattleJoinRequest.pb.h"
#include "MessageExpandBagRequest.pb.h"
#include "MessageUserHeartRequest.pb.h"
#include "MessageBossJoinRequest.pb.h"
#include "MessageBossAttackRequest.pb.h"
#include "MessageBossInspireRequest.pb.h"
#include "MessageCityHelperRequest.pb.h"

extern  char g_szServerVersion[32];
extern  char	g_szServerIp[32];
extern  int	g_nServerPort;

const char *test_data[] = {
	"1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111", 
	"22222222222", 
	"333333333333333333333", 
	"4444444444444444444444444444444"};

CRobotObj::CRobotObj(int index, const char* name, const char* pwd, int actionTime, int world)
{
	m_index = index;
	strcpy(m_szName, name);
	strcpy(m_szPwd, pwd);

	m_sock = INVALID_SOCKET;
	m_SendNO = 0;
	m_RecvNO = 0;
	m_LastTime = 0;
	m_Stat = ESTAT_NONE;
	m_ActionTime = actionTime;
	m_server = world;
	m_HeartTime = 0;
	m_PlayerID = 0;

	m_OperateCount = 0;
	m_WorshipType = 0;
	m_SignInType = 0;
}

CRobotObj::~CRobotObj()
{
}

bool CRobotObj::Check(const char* szip, int port, const char* ver)
{
	m_sock = RobotNet.Connect(szip, port);
	if( m_sock != INVALID_SOCKET )
	{
		//for(int i=0; i<10; ++i)
		//{
		//	Message::GuestCheck msg;
		//	//msg.set_device(m_szName);
		//	msg.set_server(m_server);

		//	PACKET_COMMAND pack;
		//	PROTOBUF_CMD_PACKAGE(pack, msg, 60000);
		//	RobotNet.SendMsg(m_uid, m_sock, &pack);

		//	Sleep(1000);
		//}

		printf("%s连接LoginServer成功\n", m_szName);

		RobotMgr.m_LogonMap.Insert(m_sock, this);

		Message::GuestCheck msg;
		msg.set_device(m_szName);
		msg.set_server(m_server);

		PACKET_COMMAND pack;
		PROTOBUF_CMD_PACKAGE(pack, msg, P2L_REQUEST_GUEST_CHECK);
		RobotNet.SendMsg(m_uid, m_sock, &pack);

		return true;
	}
	return false;
}

bool CRobotObj::Logon(const char* szip, int port)
{
	RobotMgr.RemoveRobot( m_sock );

	m_sock = RobotNet.Connect(szip, port);
	if( m_sock != INVALID_SOCKET )
	{
		printf("%s连接GateServer成功\n", m_szName);

		RobotMgr.m_LogonMap.Insert(m_sock, this);

		Message::ClientLogin msg;
		msg.set_uid(m_uid);
		msg.set_key(m_key);
		msg.set_server(m_server);

		PACKET_COMMAND pack;
		PROTOBUF_CMD_PACKAGE(pack, msg, P2A_REQUEST_USER_LOGIN);
		RobotNet.SendMsg(m_uid, m_sock, &pack);

		return true;
	}
	return false;
}

void CRobotObj::Logout()
{
	Message::UserLogout msg;
	msg.set_uid( m_uid );

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, P2A_REQUEST_USER_LOGOUT);
	RobotNet.SendMsg(m_uid, m_sock, &pack);
}

void CRobotObj::Heart()
{
	if( m_PlayerID <= 0 )
		return;

	uint64 t = GetTimeSec();
	if( t - m_HeartTime >= 30 )
	{
		Message::UserHeartRequest msg;
		msg.set_pid( m_PlayerID );

		PACKET_COMMAND pack;
		PROTOBUF_CMD_PACKAGE(pack, msg, P2A_REQUEST_USER_HEART);
		RobotNet.SendMsg(m_uid, m_sock, &pack);

		m_HeartTime = t;
	}
}

void CRobotObj::CreatePlayer(int64 uid, int server, const char* name, int vocation, int sex, int camp)
{
	wchar_t* wname = new wchar_t[32];
	int nCount = strlen( name ) + 1;
	MultiByteToWideChar(CP_ACP, 0, name, nCount, wname, nCount );

	Message::CreatePlayer msg;
	msg.set_uid(uid);
	msg.set_server(server);
	msg.set_name(name);
	msg.set_roletemplate(vocation);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, P2D_REQUEST_PLAYER_CREATE);
	RobotNet.SendMsg(m_uid, m_sock, &pack);
}

void CRobotObj::AttackMonster(int64 pid, int scene, int monster)
{
	Message::AttackMonsterRequest msg;
	//msg.set_pid( pid );
	msg.set_scene( scene );
	msg.set_monster( monster );
	msg.set_type(1);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, P2G_REQUEST_ATTACK_MONSTER);
	RobotNet.SendMsg(m_uid, m_sock, &pack);
}

void CRobotObj::ActiveCity(int64 pid, int scene)
{
	char id[1024] = {0};
	_i64toa(m_PlayerID, id, 10);

	Message::DebugRequest msg;
	msg.add_strings("activecity");
	msg.add_strings(id);
	msg.add_strings("103");

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, P2G_REQUEST_DEBUG);
	RobotNet.SendMsg(m_uid, m_sock, &pack);
}

void CRobotObj::AddExp(int exp)
{
	char id[1024] = {0};
	_i64toa(m_PlayerID, id, 10);

	Message::DebugRequest msg;
	msg.add_strings("addexp");
	msg.add_strings(id);
	msg.add_strings("100");

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, P2G_REQUEST_DEBUG);
	RobotNet.SendMsg(m_uid, m_sock, &pack);
}

void CRobotObj::AddItem()
{
	char id[1024] = {0};
	_i64toa(m_PlayerID, id, 10);

	Message::DebugRequest msg;
	msg.add_strings("additem");
	msg.add_strings(id);
	msg.add_strings("10101001");
	msg.add_strings("1");

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, P2G_REQUEST_DEBUG);
	RobotNet.SendMsg(m_uid, m_sock, &pack);
}

void CRobotObj::SendChat()
{
	Message::ChatRequest msg;
	msg.set_id(m_PlayerID);
	msg.set_message("fsdfsdfsdfdsfds");

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, P2G_REQUEST_CHAT_WORLD);
	RobotNet.SendMsg(m_uid, m_sock, &pack);
}

void CRobotObj::RequestObserver()
{
	Message::ObservePlayerRequest msg;
	msg.set_playerid(970200000020000000);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, P2G_REQUEST_OBSERVE_PLAYER);
	RobotNet.SendMsg(m_uid, m_sock, &pack);
}

void CRobotObj::RequestJoinBattle()
{
	Message::BattleJoinRequest msg;

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, P2G_REQUEST_BATTLE_JOIN);
	RobotNet.SendMsg(m_uid, m_sock, &pack);
}

void CRobotObj::RequestAttackBoss()
{
	//join
	Message::BossJoinRequest msg;
	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, P2G_REQUEST_BOSS_JOIN);
	RobotNet.SendMsg(m_uid, m_sock, &pack);

	//inspire
	Message::BossInspireRequest msg1;
	PACKET_COMMAND pack1;
	PROTOBUF_CMD_PACKAGE(pack1, msg1, P2G_REQUEST_BOSS_INSPIRE);
	RobotNet.SendMsg(m_uid, m_sock, &pack1);

	//attack
	Message::BossAttackRequest msg2;
	PACKET_COMMAND pack2;
	PROTOBUF_CMD_PACKAGE(pack2, msg2, P2G_REQUEST_BOSS_ATTACK);
	RobotNet.SendMsg(m_uid, m_sock, &pack2);
}

void CRobotObj::RequestHelper()
{
	Message::CityHelperRequest msg;
	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, P2G_REQUEST_HELPER_INFO);
	RobotNet.SendMsg(m_uid, m_sock, &pack);
}

void CRobotObj::ActiveStar()
{

}

void CRobotObj::UplevelStar()
{
	
}

void CRobotObj::AddHero()
{
	char id[1024] = {0};
	_i64toa(m_PlayerID, id, 10);

	Message::DebugRequest msg;
	msg.add_strings("addhero");
	msg.add_strings(id);
	msg.add_strings("10");
	msg.add_strings("0");

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, P2G_REQUEST_DEBUG);
	RobotNet.SendMsg(m_uid, m_sock, &pack);
}

void CRobotObj::DoNetTest()
{
	Message::NetTestRequest msg;

	msg.set_no(m_SendNO);
	for (int i = 0; i < 0; ++i)
	{
		msg.add_idata(m_SendNO + i);
	}
	msg.set_sdata(test_data[m_SendNO%4]);
	//msg.set_sdata(test_data[1]);
	++m_SendNO;

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, P2G_REQUEST_NET_TEST);
	RobotNet.SendMsg(m_uid, m_sock, &pack); 
	//printf("send message [%d:%s]\n", P2G_REQUEST_NET_TEST, msg.ShortDebugString().c_str());
}

void CRobotObj::OnNetTest(int RecvNO, const char* sdata)
{
	if (m_RecvNO != RecvNO || strcmp(sdata, test_data[m_RecvNO%4]) != 0)
	{
		fprintf(stderr, "receive data is error [%d, %s] [%d, %s]\n", m_RecvNO,test_data[m_RecvNO%4],RecvNO, sdata);
		Log.Error("receive data is error [%d, %s] [%d, %s]\n", m_RecvNO,test_data[m_RecvNO%4],RecvNO, sdata);
		return;
	}
	++m_RecvNO;
}

void CRobotObj::DoLoginTest()
{
	RobotNet.Shutdown(m_sock);
	this->Check(g_szServerIp, g_nServerPort, g_szServerVersion);
	//Log.Notice("DoLoginTest");
}

bool CRobotObj::DoActiveBehavior(int type)
{
	if (getStat() != ESTAT_LOGINGATE)
	{
		return false;
	}
	if ( timeGetTime() - m_LastTime > 20 )
	{
		m_LastTime = timeGetTime();

		LuaParam pParam[1];	
		pParam[0].SetDataNum(this->m_sock);
		LuaEngine.RunLuaFunction("DoActiveBehavior", "ActiveUnit", NULL, pParam, 1);
	}

	return true;
}

void CRobotObj::DoWorship()
{
	if(m_WorshipType > 11) return;

	Message::DoWorshiping msg;

	int iType = 0;
	int iGroup = 0;
	switch (m_WorshipType)
	{
	case 0:
	case 1: iType = 1; iGroup = 0; break;
	case 2: iType = 2; break;
	case 3: iType = 1; iGroup = 1; break;
	case 4: iType = 2; break;
	case 5: iType = 1; iGroup = 2; break;
	case 6: iType = 2; break;
	case 7: iType = 1; iGroup = 3; break;
	case 8: iType = 2; break;
	case 9: iType = 3; break;
	case 10:iType = 1; iGroup = 3; break;
	case 11:iType = 2; break;
	}

	msg.set_opttype(iType);
	msg.set_group(iGroup);
	m_WorshipType++;
	
	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, P2G_REQUEST_WORSHIPING);
	RobotNet.SendMsg(m_uid, m_sock, &pack); 
}

void CRobotObj::DoSignIn()
{
	if(m_SignInType > 8) return;

	Message::SignInSystemRequest msg;

	int iType = 0;
	int iSubType = 0;
	switch (m_SignInType)
	{
	case 0: iType = 0; break;
	case 1: iType = 1; break;
	case 2: iType = 2; break;
	case 3: iType = 3; iSubType = 20; break;
	case 4: iType = 4; break;
	case 5: iType = 5; iSubType = 6; break;
	case 6: iType = 6; break;
	case 7: iType = 7; break;
	case 8: iType = 8; break;
	}

	msg.set_opttype(iType);
	msg.set_subtype(iSubType);
	m_SignInType++;

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE( pack, msg, P2G_REQUEST_DOSIGNIN );
	RobotNet.SendMsg(m_uid, m_sock, &pack);
}

void CRobotObj::ExpandBag()
{
	//Message::ExpandBag msg;
	//PACKET_COMMAND pack;

	//msg.set_pid(GetPlayerID());
	//PROTOBUF_CMD_PACKAGE( pack, msg, P2G_REQUEST_BAG_EXPAND );

	//RobotNet.SendMsg(m_uid, m_sock, &pack);
}

void CRobotObj::DoNonScriptBehavior()
{
	if(m_OperateCount <= 11) {
		DoWorship();
	}
	else if(m_OperateCount > 11 && m_OperateCount <= 20) {
		DoSignIn();
	}
	else if(m_OperateCount > 20) {
		return;	
	}

	//....

	m_OperateCount++;
}
