// DataServer.cpp : 定义控制台应用程序的入口点。
//

#include "MainServer.h"
#include "CommandMgr.h"
#include "exception.h"
#include "LuaEngine.h"
#include "PathFunc.h"
#ifdef __linux__
#include "DBResult.h"
#include "linux_time.h"
#include "monitor.h"
#endif
#include "commdata.h"
#include "ServerMgr.h"
#include "DataModule.h"
#include "LoadModule.h"
#include "utlsymbol.h"


createFileSingleton(CLog);
createFileSingleton(CLuaEngine);
createFileSingleton(CMainServer);
createFileSingleton(CServerMgr);
//createFileSingleton(CDBResult);
createFileSingleton(CCommandMgr);
createFileSingleton(CDataModule);
createFileSingleton(CLoadModule);

CObjectMemoryPool<PACKET_COMMAND>	g_PacketPool;
extern CObjectMemoryPool<OperObj>	g_MongoOperPool;


void StatusOutput(char* output)
{
    char szPackPool[10240] = {0};
	char szMongoPool[10240] = {0};
	char szServer[10240] = {0};

	g_PacketPool.Output(szPackPool, 10240);
	g_MongoOperPool.Output(szMongoPool, 10240);
	ServerMgr.Output(szServer);

	sprintf(output, 
		" DataServer monitor: \n"
        " ======================================================\n"
        " memory pool used:\n"
        "  %s"
		"  %s"
		" ======================================================\n"
        " %s",
		szPackPool, szMongoPool,
		szServer);
}

bool Begin()
{
	char g_szExePath[512] = { 0 };
	GetExePath( g_szExePath, 512 );

	//启动MainServer
	if( !MainServer.Startup("DataServer") )
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
	const char* centralip = LuaEngine.GetLuaVariableString( "CentralServer_ip", "Sconf" );
	int centralid		= LuaEngine.GetLuaVariableNumber( "CentralServer_id",	"Sconf" );
	int centralport		= LuaEngine.GetLuaVariableNumber( "CentralServer_port", "Sconf" );
	const char* myip	= LuaEngine.GetLuaVariableString( "DataServer_ip",		"Sconf" );
	int myid			= LuaEngine.GetLuaVariableNumber( "DataServer_id",		"Sconf" );
	int myport			= LuaEngine.GetLuaVariableNumber( "DataServer_port",	"Sconf" );
	const char* gamedbip= LuaEngine.GetLuaVariableString( "db_game_ip",	        "Sconf" );
	const char* gamedbname = LuaEngine.GetLuaVariableString( "db_game_name",    "Sconf" );
    const char* gamedbport = LuaEngine.GetLuaVariableString( "db_game_port",	"Sconf" );
	const char* eventdbip  = LuaEngine.GetLuaVariableString( "db_event_ip",     "Sconf" );
	const char* eventdbname= LuaEngine.GetLuaVariableString( "db_event_name",   "Sconf" );
	const char* eventdbport= LuaEngine.GetLuaVariableString( "db_event_port",	"Sconf" );
	int worldID         = LuaEngine.GetLuaVariableNumber( "WorldID",            "Sconf" );
	int connmax			= LuaEngine.GetLuaVariableNumber( "connect_count_max",	"DataServer" );
	int packsize		= LuaEngine.GetLuaVariableNumber( "packet_pool_size",	"DataServer" );
	int recvsize		= LuaEngine.GetLuaVariableNumber( "recv_buff_size",		"DataServer" );
	int sendsize		= LuaEngine.GetLuaVariableNumber( "send_buff_size",		"DataServer" );
	int usercnt 		= LuaEngine.GetLuaVariableNumber( "user_count_max",		"DataServer" );
	int playercnt		= LuaEngine.GetLuaVariableNumber( "player_count_max",	"DataServer" );
	int herocnt         = LuaEngine.GetLuaVariableNumber( "hero_count_max",     "DataServer" );
	int itemcnt			= LuaEngine.GetLuaVariableNumber( "item_count_max",		"DataServer" );
	int saveTime        = LuaEngine.GetLuaVariableNumber( "save_logic_interval","DataServer" );
	int orderSaveTime   = LuaEngine.GetLuaVariableNumber( "save_logic_interval","DataServer" );
	int dboperator		= LuaEngine.GetLuaVariableNumber( "db_operator_max",	"DataServer" );
	const char* udPath	= LuaEngine.GetLuaVariableString( "MonitorPath",		"Key" );

	DataModule.Initialize("DataObj", playercnt);

	if( !g_PacketPool.Init("Packet", packsize) )
		return false;

	if( !g_MongoOperPool.Init("MongoOper", dboperator) )
		return false;

	MainServer.SetPacketSize(packsize);

	//初始化
	char mpath[1024] = {0};
	sprintf(mpath, "%s//FPS_%d.sock", udPath, myid);
	MainServer.Init(worldID, Svr_Data, myid, myport, myip, 0, NULL, mpath);

	CMongoDB* db = (CMongoDB *) MainServer.createPlugin(CMainServer::Plugin_Mongodb);
	if (!db->startup(gamedbip, gamedbport, gamedbname)) {
		return false;
	}

	if( !MainServer.StartupServerNet(connmax, sendsize, recvsize, packsize) )
		return false;

	if( !ServerMgr.CreateServer(Svr_Central, centralid, centralport, centralip, NULL, NULL, worldID, true) )
		return false;

	//g_LoadAllName();

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

	if( LoadModule.onMessage(pack) )
		return;

	if( DataModule.onMessage(pack) )
		return;

	if( ServerMgr.OnMsg(pack) )
		return;

	Log.Debug("OnMsg no module %d", pack->Type());

	return;
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

	TMV nowtime = timeGetTime();

	MsgLogic();

	LoadModule.onLogic();

	DataModule.onSave();

	ServerMgr.OnLogic();

	CommandMgr.OnLogic();
}

void Output()
{
#if _WIN32
	//设置控制台标题
	char title[128] = {0};
	sprintf(title, "DataServer  User:%d", UserMgr.Count());
	SetConsoleTitle(title);

	system("cls");
#endif
}

void End()
{
	Log.Notice("End ..");
	DataModule.onSave();
	MainServer.ShutdownNet();

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

