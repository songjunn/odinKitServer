// GateServer.cpp : 定义控制台应用程序的入口点。
//

#include "MainServer.h"
#include "UserMgr.h"
#include "LuaEngine.h"
#include "PathFunc.h"
#include "exception.h"
#include "WorldConfig.h"
#ifdef __linux__
#include <unistd.h>
#include "linux_time.h"
#include "vprof.h"
#endif
#include "MessageTypeDefine.pb.h"
#include "MessageServer.pb.h"


createFileSingleton(CLog);
createFileSingleton(CLuaEngine);
createFileSingleton(CMainServer);
createFileSingleton(CServerMgr);
createFileSingleton(CUserMgr);
createFileSingleton(CWorldConfig);

CObjectMemoryPool<PACKET_COMMAND>	g_PacketPool;
extern CObjectMemoryPool<OperObj>	g_MongoOperPool;


void StatusOutput(char* output)
{
    char szPackPool[10240] = {0};
	char szMongoPool[10240] = {0};
	char szUserPool[10240] = {0};
	char szServer[10240] = {0};

	g_PacketPool.Output(szPackPool, 10240);
	g_MongoOperPool.Output(szMongoPool, 10240);
	UserMgr.m_pool.Output(szUserPool, 10240);
	GETSERVERMGR->Output(szServer);

	sprintf(output, 
	    " LoginServer monitor: User:%d\n"
        " ======================================================\n"
        " memory pool used:\n"
        "  %s"
		"  %s"
		"  %s"
		" ======================================================\n"
        " %s",
		UserMgr.Count(),
		szPackPool, szMongoPool, szUserPool, 
		szServer);
}

bool Begin()
{
	char g_szExePath[512] = { 0 };
	GetExePath( g_szExePath, 512 );

	//启动MainServer
	if( !MainServer.Startup("LoginServer") )
		return false;

	//初始化启动参数
	char szConfile[256]= { 0 };
	sprintf(szConfile,"%ssconf.lua", g_szExePath);
	if( !LuaEngine.LoadLuaFile( szConfile ) )
	{
		Log.Error("加载sconf.lua失败！");
		return false;
	}

	//读取启动参数
	const char* centralip = LuaEngine.GetLuaVariableString( "CentralServer_ip",	"Sconf" );
	int centralid		= LuaEngine.GetLuaVariableNumber( "CentralServer_id",	"Sconf" );
	int centralport		= LuaEngine.GetLuaVariableNumber( "CentralServer_port",	"Sconf" );
	const char* myip	= LuaEngine.GetLuaVariableString( "LoginServer_ip",		"Sconf" );
	int myid			= LuaEngine.GetLuaVariableNumber( "LoginServer_id",		"Sconf" );
	int myport			= LuaEngine.GetLuaVariableNumber( "LoginServer_port",	"Sconf" );
	const char* gamedbip		= LuaEngine.GetLuaVariableString( "db_game_ip",	"Sconf" );
	const char* gamedbname		= LuaEngine.GetLuaVariableString( "db_game_name",	"Sconf" );
	const char* gamedbport      = LuaEngine.GetLuaVariableString( "db_game_port",	"Sconf" );
	int worldID         = LuaEngine.GetLuaVariableNumber( "WorldID",            "Sconf" );
	int connmax			= LuaEngine.GetLuaVariableNumber( "connect_count_max",	"LoginServer" );
	int packsize		= LuaEngine.GetLuaVariableNumber( "packet_pool_size",	"LoginServer" );
	int recvsize		= LuaEngine.GetLuaVariableNumber( "recv_buff_size",		"LoginServer" );
	int sendsize		= LuaEngine.GetLuaVariableNumber( "send_buff_size",		"LoginServer" );
	int clientport		= LuaEngine.GetLuaVariableNumber( "LoginServer_Client_port","Sconf" );
	int clientconnmax	= LuaEngine.GetLuaVariableNumber( "gateway_connect_max","LoginServer" );
	int clientpacksize	= LuaEngine.GetLuaVariableNumber( "gateway_queue_max",	"LoginServer" );
	int clientrecvsize	= LuaEngine.GetLuaVariableNumber( "gateway_recv_size",	"LoginServer" );
	int clientsendsize	= LuaEngine.GetLuaVariableNumber( "gateway_send_size",	"LoginServer" );
	int usercnt 		= LuaEngine.GetLuaVariableNumber( "user_count_max",		"LoginServer" );
	int hearttimeout	= LuaEngine.GetLuaVariableNumber( "user_heart_timeout",	"LoginServer" );
	int dboperator		= LuaEngine.GetLuaVariableNumber( "db_operator_max",	"LoginServer" );
	const char* udPath	= LuaEngine.GetLuaVariableString( "MonitorPath",		"Key" );

	//paymentserver address and port
	const char *paySvr = LuaEngine.GetLuaVariableString("PaymentServer_inetip", "Sconf");
	if (!paySvr || !paySvr[0] || strlen(paySvr) >= 32) {
		return false;
	}
	strcpy(CUserMgr::paysrv_addr, paySvr);
	CUserMgr::paysrv_port = LuaEngine.GetLuaVariableNumber("PaymentServer_Client_port", "Sconf");
	if (CUserMgr::paysrv_port < 1) {
		return false;
	}

	//初始化
	char mpath[1024] = {0};
	sprintf(mpath, "%s//FPS_%d.sock", udPath, myid);
	MainServer.Init(0, CServerMgr::Svr_Login, myid, myport, myip, 0, NULL, mpath);

	if( !UserMgr.Initialize("user", usercnt) )
		return false;

	if( !g_PacketPool.Init("Packet", packsize) )
		return false;

	if( !g_MongoOperPool.Init("MongoOper", dboperator) )
		return false;

	CNetwork* servernet = (CNetwork *)MainServer.createPlugin(CMainServer::Plugin_Net4Server);
	if (!servernet->startup(CNet::NET_IO_SELECT, myport, connmax, sendsize, recvsize, packsize)) {
		Log.Error("[CMainServer] create Plugin_Net4Server failed");
		return false;
	}

	CNetwork* clientnet = (CNetwork *)MainServer.createPlugin(CMainServer::Plugin_Net4Client);
	if (!clientnet->startup(CNet::NET_IO_EPOLL, clientport, clientconnmax, clientsendsize, clientrecvsize, clientpacksize)) {
		Log.Error("[CMainServer] create Plugin_Net4Client failed");
		return false;
	}

	//取消单login对多服的架构，有需要再说
	////加载区服信息
	//char worldFile[256]= { 0 };
	//sprintf(worldFile,"%s/worldconfig.csv", g_szExePath);
	//if( !WorldConfig.LoadCSVData(worldFile) )
	//	return false;
	//WorldConfig.ConnectAllWorld();

	CServerMgr* servermgr = (CServerMgr *)MainServer.createPlugin(CMainServer::Plugin_ServerMgr);
	if (!servermgr->startup(CServerMgr::Svr_Central, centralid, centralport, centralip, NULL, NULL, worldID)) {
		Log.Error("[CMainServer] create plugin CServerMgr failed");
		return false;
	}

	CMongoDB* db = (CMongoDB *)MainServer.createPlugin(CMainServer::Plugin_Mongodb);
	if (!db->startup(gamedbip, gamedbport, gamedbname)) {
		return false;
	}

	UserMgr.LoadFactId(worldID);
	UserMgr.SetUserTimeout( hearttimeout);

#ifdef __linux__
	char spath[1024] = {0};
	sprintf(spath, "%s//Server_%d.sock", udPath, myid);
	NEW CMonitor(spath, &StatusOutput);
#endif

	return true;
}

void OnMsg(PACKET_COMMAND* pack)
{
	if( !pack )
		return;

	switch( pack->Type() )
	{
	//从客户端发来的消息
	case Message::MSG_REQUEST_USER_CHECK:
	case Message::MSG_REQUEST_GUEST_CHECK:
	case Message::MSG_SERVER_NET_ACCEPT:
	case Message::MSG_SERVER_NET_CLOSE:
		UserMgr.OnMsg( pack );
		return;
	//服务端首次发来的消息
	case Message::MSG_SERVER_REGISTER:
		GETSERVERMGR->OnMsg(pack);
		return;
	default:
		break;
	}

	//从服务端发来的消息
	CServerObj* pServer = GETSERVERMGR->GetServer(pack->GetNetID());
	if( pServer )
	{
		if (Message::MSG_SERVER_BEGIN >= pack->Type() || Message::MSG_SERVER_END <= pack->Type())
		{
			Log.Error("[LoginServer] Recv Error Message From Server, type:%d, sock:%d", pack->Type(), pack->GetNetID());
			return;
		}

		switch( pack->Type() )
		{
		case Message::MSG_SERVER_SYNCGATELOAD:
		case Message::MSG_SERVER_SYNCSERVER:
		case Message::MSG_SERVER_NET_CONNECT:
			GETSERVERMGR->OnMsg(pack);
			break;
		default:
			break;
		}

		return;
	}

}

void MsgLogic()
{
	PACKET_COMMAND* pack = NULL;
	while ((pack = GETSERVERNET->getHeadPacket()))
	{
		OnMsg(pack);

		g_PacketPool.Free( pack );
	}
	while ((pack = GETCLIENTNET->getHeadPacket()))
	{
		OnMsg(pack);

		g_PacketPool.Free(pack);
	}
}

void Logic()
{
	VProfCurrentProfile().Pause();
	VProfCurrentProfile().Server_OutputReport();
	VProfCurrentProfile().Resume();
	VProfCurrentProfile().MarkFrame();

	MsgLogic();

	UserMgr.UserHeartLogic();

	GETSERVERMGR->OnLogic();
}

void Output()
{
#if _WIN32
	//设置控制台标题
	char title[128] = {0};
	sprintf(title, "LoginServer  User:%d", UserMgr.Count());
	SetConsoleTitle(title);
#endif
}

void End()
{
	Log.Notice("End ..");
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

	if( !Begin() )
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

			if( timeGetTime() - time > 2000 )
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
		Sleep(10);
#else
#ifdef __linux__
		usleep(10000);
#endif
#endif
	}

	End();

	return 0;
}
