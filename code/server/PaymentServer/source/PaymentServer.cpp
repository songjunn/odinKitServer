#include "MainServer.h"
#include "ServerMgr.h"
#include "PathFunc.h"
#include "exception.h"
#include "Singleton.h"
#include "LuaEngine.h"
#include "PaymentVerifyModule.h"
#ifdef __linux__
#include <unistd.h>
#include "CommDef.h"
#include "PacketDefine.h"
#include "DBCache.h"
#include "monitor.h"
#include "DBResult.h"
#endif
//#include "HttpServer.h"
#include "GameWorldMgr.h"
#include "plugin_HttpServe.h"


createFileSingleton(CLog);
createFileSingleton(CLuaEngine);
createFileSingleton(CMainServer);
createFileSingleton(CServerMgr);
createFileSingleton(CDBResult);
createFileSingleton(CPaymentVerifyModule);
createFileSingleton(CGameWorldMgr);


CObjectMemoryPool<PACKET_COMMAND>	g_PacketPool;

static int httpserver_ev_handler(struct mg_connection *conn, enum mg_event ev) {
	if (ev == MG_REQUEST) {
		//mg_send_header(conn, "Content-Type", "text/plain");
		//mg_printf_data(conn, "This is a reply from server instance # %s", (char *)conn->server_param);
		if (PaymentVerifyModule.OnChargeFromSWServer(conn)) {
			mg_send_data(conn, "0", 1);
		}
		else {
			mg_send_data(conn, "1", 1);
		}

		return MG_TRUE;
	}
	else if (ev == MG_AUTH) {
		return MG_TRUE;
	}
	else {
		return MG_FALSE;
	}
}

void StatusOutput(char* output)
{

}

bool Begin()
{
	char g_szExePath[512] = { 0 };
	GetExePath( g_szExePath, 512 );

	//启动MainServer
	if( !MainServer.Startup("PaymentServer") )
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
	const char* myip	= LuaEngine.GetLuaVariableString( "PaymentServer_ip",		"Sconf" );
	int myid			= LuaEngine.GetLuaVariableNumber( "PaymentServer_id",		"Sconf" );
	int myport			= LuaEngine.GetLuaVariableNumber( "PaymentServer_port",		"Sconf" );
	int httpport		= LuaEngine.GetLuaVariableNumber( "PaymentServer_Client_port",		"Sconf" );
	int connmax			= LuaEngine.GetLuaVariableNumber( "connect_count_max",	"PaymentServer" );
	int packsize		= LuaEngine.GetLuaVariableNumber( "packet_pool_size",	"PaymentServer" );
	int recvsize		= LuaEngine.GetLuaVariableNumber( "recv_buff_size",		"PaymentServer" );
	int sendsize		= LuaEngine.GetLuaVariableNumber( "send_buff_size",		"PaymentServer" );
	const char* udPath	= LuaEngine.GetLuaVariableString( "MonitorPath",		"Key" );

	//初始化
	char mpath[1024] = {0};
	sprintf(mpath, "%s//FPS_%d.sock", udPath, myid);
	MainServer.Init(0, Svr_Payment, myid, myport, myip, 0, NULL, mpath);

	if( !g_PacketPool.Init("Packet", packsize) )
		return false;

	MainServer.SetPacketSize(packsize);

	if( !MainServer.StartupServerNet(connmax, sendsize, recvsize, packsize) )
		return false;

	/*char worldfile[256] = { 0 };
	sprintf(worldfile, "%s/data/world.csv", g_szExePath);
	if (!GameWorldMgr.LoadCSVData(worldfile))
		return false;*/

	if (!ServerMgr.CreateServer(Svr_Central, centralid, centralport, centralip, NULL, NULL, 0, true))
		return false;

	/*CHttpServer* httpServer = NEW CHttpServer();
	if (!httpServer->startup(httpport, httpserver_ev_handler, 3)) {
		return false;
	}*/
	CHttpServe* httpServe = (CHttpServe *)MainServer.createPlugin(CMainServer::Plugin_HttpServe);
	if (!httpServe->startup(httpport, httpserver_ev_handler)) {
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
	if( !pack )
		return;

	if( ServerMgr.OnMsg(pack) )
		return;

	if ( PaymentVerifyModule.OnMsg(pack)) {
		return;
	}
	Log.Debug("OnMsg no module %d", pack->Type());
}

void MsgLogic()
{
	PACKET_COMMAND* pack = NULL;
	while( (pack = MainServer.GetHeadPacket()) )
	{
		OnMsg(pack);

		g_PacketPool.Free( pack );
	}
}

void Logic()
{
	VProfCurrentProfile().Pause();
	VProfCurrentProfile().Server_OutputReport();
	VProfCurrentProfile().Resume();
	VProfCurrentProfile().MarkFrame();

	MsgLogic();

	ServerMgr.OnLogic();
}

void Output()
{
#if _WIN32
	//设置控制台标题
	char title[128] = {0};
	sprintf(title, "PaymentServer");
	SetConsoleTitle(title);
#endif
}

void End()
{
	Log.Notice("End ..");
	Log.Shutdown();

#ifdef __linux__
	sleep(5);
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
			if (MainServer.getServerState() == EStateStopping) {
				break;
			}
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
		Sleep(1);
#else
#ifdef __linux__
		usleep(1000);
#endif
#endif
	}

	End();

	return 0;
}
