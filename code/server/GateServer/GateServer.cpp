// GateServer.cpp : 定义控制台应用程序的入口点。
//

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
#include <windows.h>
#include <tchar.h>
#endif
#include "MainServer.h"
#include "UserMgr.h"
#include "LuaEngine.h"
#include "PathFunc.h"
#ifdef __linux__
#include "linux_time.h"
#include "udsvr.h"
#include "monitor.h"
#endif
#include "MessageTypeDefine.pb.h"
#include "MessageServer.pb.h"
#include "exception.h"


createFileSingleton(CLog);
createFileSingleton(CLuaEngine);
createFileSingleton(CMainServer);
createFileSingleton(CServerMgr);
createFileSingleton(CUserMgr);

CObjectMemoryPool<PACKET_COMMAND>	g_PacketPool;

static TMV g_StatusLogicTime = 0;

void StatusOutput(char* output)
{
    char szPackPool[10240] = {0};
	char szUserPool[10240] = {0};
	char szServer[10240] = {0};

	g_PacketPool.Output(szPackPool, 10240);
	UserMgr.m_pool.Output(szUserPool, 10240);
	GETSERVERMGR->Output(szServer);

	sprintf(output, 
		" GateServer monitor: User:%d UKey:%d\n"
        " ======================================================\n"
        " memory pool used:\n"
        "  %s"
		"  %s"
		" ======================================================\n"
        " %s",
		UserMgr.Count(), UserMgr.GetUserKeyCount(), 
		szPackPool, szUserPool, 
		szServer);
}

bool Begin(int param_id, int param_port, int param_extport)
{
	char g_szExePath[512] = { 0 };
	GetExePath( g_szExePath, 512 );

	//启动MainServer
	char szServerName[64] = "GateServer";
	if( param_id > 0 ) sprintf(szServerName, "%s%d", szServerName, param_id);
	if( !MainServer.Startup(szServerName) )
		return false;

	//初始化启动参数
	char szConfile[256]= { 0 };
	sprintf(szConfile,"%ssconf.lua", g_szExePath);
	if( !LuaEngine.LoadLuaFile( szConfile ) )
	{
		Log.Error("[GateServer] Load sconf.lua Error");
		return false;
	}

	//读取启动参数
	const char* centralip = LuaEngine.GetLuaVariableString( "CentralServer_ip","Sconf" );
	int centralid		= LuaEngine.GetLuaVariableNumber( "CentralServer_id",	"Sconf" );
	int centralport		= LuaEngine.GetLuaVariableNumber( "CentralServer_port","Sconf" );
	const char* myip	= LuaEngine.GetLuaVariableString( "GateServer_ip",		"Sconf" );
	int myid			= LuaEngine.GetLuaVariableNumber( "GateServer_id",		"Sconf" );
	int myport			= LuaEngine.GetLuaVariableNumber( "GateServer_port",	"Sconf" );
	int extport			= LuaEngine.GetLuaVariableNumber( "GateServer_Client_port","Sconf" );
	const char* extip	= LuaEngine.GetLuaVariableString( "GateServer_inetip",	"Sconf" );
	int worldID         = LuaEngine.GetLuaVariableNumber( "WorldID",            "Sconf" );
	int connmax			= LuaEngine.GetLuaVariableNumber( "connect_count_max",	"GateServer" );
	int packsize		= LuaEngine.GetLuaVariableNumber( "packet_pool_size",	"GateServer" );
	int recvsize		= LuaEngine.GetLuaVariableNumber( "recv_buff_size",		"GateServer" );
	int sendsize		= LuaEngine.GetLuaVariableNumber( "send_buff_size",		"GateServer" );
	int iocpconnmax		= LuaEngine.GetLuaVariableNumber( "gateway_connect_max","GateServer" );
	int iocppacksize	= LuaEngine.GetLuaVariableNumber( "gateway_queue_max",	"GateServer" );
	int iocprecvsize	= LuaEngine.GetLuaVariableNumber( "gateway_recv_size",	"GateServer" );
	int iocpsendsize	= LuaEngine.GetLuaVariableNumber( "gateway_send_size",	"GateServer" );
	int usercnt 		= LuaEngine.GetLuaVariableNumber( "user_count_max",		"GateServer" );
	int playercnt		= LuaEngine.GetLuaVariableNumber( "player_count_max",	"GateServer" );
	const char* udPath	= LuaEngine.GetLuaVariableString( "MonitorPath",		"Key" );
	int hearttimeout	= LuaEngine.GetLuaVariableNumber( "user_heart_timeout",	"GateServer" );
	int keytimeout		= LuaEngine.GetLuaVariableNumber( "user_key_timeout",	"GateServer" );
	int packlimit		= LuaEngine.GetLuaVariableNumber( "user_pack_limit",	"GateServer" );

	//初始化
	myid = param_id > 0 ? param_id : myid;
	myport = param_id > 0 ? param_port : myport;
	extport = param_id > 0 ? param_extport : extport;
	char mpath[1024] = {0};
	sprintf(mpath, "%s//FPS_%d.sock", udPath, myid);
	MainServer.Init(worldID, CServerMgr::Svr_GateWay, myid, myport, myip, extport, extip, mpath);

	if( !UserMgr.Initialize("user", usercnt) )
		return false;

	UserMgr.InitConfig( keytimeout, hearttimeout, packlimit );

	if( !g_PacketPool.Init("Packet", packsize) )
		return false;

	CNetwork* servernet = (CNetwork *)MainServer.createPlugin(CMainServer::Plugin_Net4Server);
	if (!servernet->startup(CNet::NET_IO_SELECT, myport, connmax, sendsize, recvsize, packsize)) {
		Log.Error("[CMainServer] create Plugin_Net4Server failed");
		return false;
	}
	
	CNetwork* clientnet = (CNetwork *)MainServer.createPlugin(CMainServer::Plugin_Net4Client);
	if (!clientnet->startup(CNet::NET_IO_EPOLL, extport, iocpconnmax, iocpsendsize, iocprecvsize, iocppacksize)) {
		Log.Error("[CMainServer] create Plugin_Net4Client failed");
		return false;
	}

	CServerMgr* servermgr = (CServerMgr *)MainServer.createPlugin(CMainServer::Plugin_ServerMgr);
	if (!servermgr->startup(CServerMgr::Svr_Central, centralid, centralport, centralip, NULL, NULL, worldID)) {
		Log.Error("[CMainServer] create Plugin_ServerMgr failed");
		return false;
	}

#ifdef __linux__
	char spath[1024] = {0};
	sprintf(spath, "%s//Server_%d.sock", udPath, myid);
	NEW CMonitor(spath, &StatusOutput);
#endif

	return true;
}

void OnMsg(PACKET_COMMAND* pack)
{
	VPROF("OnMsg");
	if( !pack )
		return;

	// from net
	switch(pack->Type())
	{
		case Message::MSG_SERVER_NET_CLOSE:
		case Message::MSG_SERVER_NET_ACCEPT:
			UserMgr.OnMsg( pack );
			break;
		default:
			break;
	}

	CServerObj* pServer = GETSERVERMGR->GetServer(pack->GetNetID());
	if( pServer )
	{
		if (Message::MSG_SERVER_BEGIN >= pack->Type() || Message::MSG_SERVER_END <= pack->Type())
		{
			Log.Error("[GateServer] Recv Wrong Message From Server, Type:%d, Sock:%d, Server:%d", pack->Type(), pack->GetNetID(), pServer->m_type);
			return;
		}

		switch( pack->Type() )
		{
		case Message::MSG_USER_PRLOGIN_REQUEST:
		case Message::MSG_PLAYER_LOGIN_REQUEST:
		case Message::MSG_PLAYER_LOAD_COUNT:
		case Message::MSG_COMMON_ERROR:
		case Message::MSG_USER_DISPLACE:
			UserMgr.OnMsg( pack );
			break;
		case Message::MSG_SERVER_SYNCSERVER:
		case Message::MSG_SERVER_NET_CONNECT:
			GETSERVERMGR->OnMsg(pack);
			break;	
		default:
			SOCKET s = UserMgr.GetNetIDByPID(pack->GetTrans());
			GETCLIENTNET->sendMsg(s, pack);
			Log.Debug("[GateServer] Transmit From:%d To Client pid:"INT64_FMT" sock:%d packet:%d size:%d", pack->GetNetID(), pack->GetTrans(), s, pack->Type(), pack->Size());
			break;
		}

		return;
	}

	CUser* pUser = UserMgr.GetObj( pack->GetNetID() );
	if( pUser )
	{
		if (Message::MSG_CLIENT_BEGIN >= pack->Type() || Message::MSG_CLIENT_END <= pack->Type())
		{
			Log.Error("[GateServer] Recv Wrong Message From Client, Type:%d, Sock:%d, User:"INT64_FMT, pack->Type(), pack->GetNetID(), pUser->m_id);
			return;
		}

		//验证消息来源，客户端发来的第一条登陆消息就不验证了
		if (pack->Type() != Message::MSG_REQUEST_USER_LOGIN && pack->GetTrans() != pUser->m_id)
		{
			Log.Error("[GateServer] Message Source Error, Msg:"INT64_FMT", Type:%d, User:"INT64_FMT, pack->GetTrans(), pack->Type(), pUser->m_id);
			return;
		}

		//user发包频率限制
		if( !UserMgr.UserPacketLimit(pUser) )
			return;

		//设置转发对象
		pack->SetTrans( pUser->m_LogonPlayer );

		switch( pack->Type() )
		{
		case Message::MSG_REQUEST_NET_TEST:
			GETCLIENTNET->sendMsg(pUser->m_ClientSock, pack);
		    break;
		case Message::MSG_REQUEST_USER_HEART:
		case Message::MSG_REQUEST_USER_LOGIN:
		case Message::MSG_REQUEST_USER_LOGOUT:
		case Message::MSG_REQUEST_PLAYER_CREATE:
			UserMgr.OnMsg( pack );
			break;
		//向DataServer转发的消息
		/*case :
			Log.Debug("[GateServer] Transmit To DataServer packet:%d size:%d", pack->Type(), pack->Size());
			GETSERVERNET->sendMsg( GETSERVERMGR->getDataSock(), pack );
			break;*/
		//默认向GameServer转发
		default:
			Log.Debug("[GateServer] Transmit To GameServer packet:%d size:%d", pack->Type(), pack->Size());
			GETSERVERNET->sendMsg( pUser->m_GameSock, pack );
			break;
		}

		return;
	}

	//从后端连接后首次发来的消息
	switch( pack->Type() )
	{
	case Message::MSG_SERVER_REGISTER:
		GETSERVERMGR->OnMsg(pack);
		return;
	default:
		break;
	}
}

void MsgLogic()
{
	VPROF("MsgLogic");

	PACKET_COMMAND* pack = NULL;

	int count = 0;
	while ((pack = GETSERVERNET->getHeadPacket()) && count++ <= 10000)
	{
		OnMsg(pack);
		
		g_PacketPool.Free( pack );
	}
	
	count = 0;
	while ((pack = GETCLIENTNET->getHeadPacket()) && count++ <= 1000)
	{
		OnMsg(pack);

		g_PacketPool.Free(pack);
	}
}

void StatusLogic()
{
	Message::SyncGateLoad msg;
	msg.set_count( UserMgr.Count() );

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE( pack, msg, Message::MSG_SERVER_SYNCGATELOAD );
	GETSERVERNET->sendMsg(GETSERVERMGR->getLoginSock(), &pack);
}

void Logic()
{
	VProfCurrentProfile().Pause();
	VProfCurrentProfile().Server_OutputReport();
	VProfCurrentProfile().Resume();
	VProfCurrentProfile().MarkFrame();

	TMV nowtime = timeGetTime();

	MsgLogic();
	UserMgr.OnLogic();
	GETSERVERMGR->OnLogic();

	//30秒同步一次负载
	if( nowtime - g_StatusLogicTime >= 30000 )
	{
		g_StatusLogicTime = nowtime;

		StatusLogic();
	}
}

void Output()
{
	VPROF("Output");

#ifdef _WIN32
	//设置控制台标题
	char title[128] = {0};
	sprintf(title, "GateServer  User:%d Key:%d", UserMgr.Count(), UserMgr.GetUserKeyCount());
	SetConsoleTitle(title);
#endif
}

void End()
{
	Log.Notice("End ..");;
	Log.Shutdown();

#ifdef __linux__
	sleep(5);
#else
	Sleep(5000);
#endif
}

#ifdef _WIN32
int _tmain(int argc, _TCHAR* argv[])
#else 
int main(int argc, char* argv[])
#endif
{
	int id = 0, port = 0, extp = 0;
	if( argc == 4 )
	{
		id = atoi(argv[1]);
		port = atoi(argv[2]);
		extp = atoi(argv[3]);
	}

	if( !Begin(id, port, extp) )
		return -1;

	DWORD time = 0;
	while(true)
	{
#if !defined(_DEBUG) && defined(WIN32)
		__try
		{
#endif
			if (MainServer.getServerState() == EStateStopping)
				break;
			Logic();		

			if( timeGetTime() - time > 1000 )
			{
				time = timeGetTime();

				Output();
			}

#if !defined(_DEBUG) && defined(WIN32)
		}
		__except (HandleException(GetExceptionInformation(), "CentralServers"))
		{
			// We don't actually do anything inside the handler. All of the
			// work is done by HandleException()
		}
#endif

#ifdef _WIN32
		Sleep(1);
#else
#if defined(__linux__) && defined(DEBUG)
		usleep(1000);
#endif
#endif
	}

	End();

	return 0;
}
