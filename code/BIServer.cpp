// BIServer.cpp : 定义控制台应用程序的入口点。
//

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
#include <windows.h>
#include <tchar.h>
#endif
#include <stdio.h>
#include "MainServer.h"
#include "LuaEngine.h"
#include "PathFunc.h"
#include "exception.h"
#include "Singleton.h"
#include "AnalysisModule.h"
#ifdef __linux__
#include <unistd.h>
#include "linux_time.h"
#include "vprof.h"
#endif


createFileSingleton(CLog);
createFileSingleton(CLuaEngine);
createFileSingleton(CMainServer);
createFileSingleton(CServerMgr);
createFileSingleton(CAnalysisModule);


CObjectMemoryPool<PACKET_COMMAND>	g_PacketPool;
extern CObjectMemoryPool<OperObj>	g_MongoOperPool;


void StatusOutput(char* output)
{
    char szPackPool[10240] = {0};
	char szMongoPool[10240] = {0};
	char szServer[10240] = {0};

	g_PacketPool.Output(szPackPool, 10240);
	g_MongoOperPool.Output(szMongoPool, 10240);
	GETSERVERMGR->Output(szServer);

	sprintf(output, 
		" BIServer monitor: Player:%d\n"
        " ======================================================\n"
        " memory pool used:\n"
		"  %s"
		"  %s"
		" ======================================================\n"
        " %s",
		AnalysisModule.GetOnlinePlayer(), 
		szPackPool, szMongoPool, 
		szServer);
}

bool Begin()
{
	char g_szExePath[512] = { 0 };
	GetExePath( g_szExePath, 512 );

	//启动MainServer
	if( !MainServer.Startup("BIServer") )
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
	const char* myip	= LuaEngine.GetLuaVariableString( "BIServer_ip",		"Sconf" );
	int myid			= LuaEngine.GetLuaVariableNumber( "BIServer_id",		"Sconf" );
	int myport			= LuaEngine.GetLuaVariableNumber( "BIServer_port",		"Sconf" );
	const char* eventdbip		= LuaEngine.GetLuaVariableString( "db_event_ip",	"Sconf" );
	const char* eventdbname		= LuaEngine.GetLuaVariableString( "db_event_name",	"Sconf" );
	const char* eventdbport     = LuaEngine.GetLuaVariableString( "db_event_port",	"Sconf" );
	int worldID         = LuaEngine.GetLuaVariableNumber( "WorldID",            "Sconf" );
	int connmax			= LuaEngine.GetLuaVariableNumber( "connect_count_max",	"BIServer" );
	int packsize		= LuaEngine.GetLuaVariableNumber( "packet_pool_size",	"BIServer" );
	int recvsize		= LuaEngine.GetLuaVariableNumber( "recv_buff_size",		"BIServer" );
	int sendsize		= LuaEngine.GetLuaVariableNumber( "send_buff_size",		"BIServer" );
	int dboperator		= LuaEngine.GetLuaVariableNumber( "db_operator_max",	"BIServer" );
	const char* udPath	= LuaEngine.GetLuaVariableString( "MonitorPath",		"Key" );

	//初始化
	char mpath[1024] = {0};
	sprintf(mpath, "%s//FPS_%d.sock", udPath, myid);
	MainServer.Init(0, CServerMgr::Svr_DataAnalysis, myid, myport, myip, 0, NULL, mpath);

	if( !g_PacketPool.Init("Packet", packsize) )
		return false;

	if (!g_MongoOperPool.Init("MongoOper", dboperator))
		return false;

	CMongoDB* db = (CMongoDB *)MainServer.createPlugin(CMainServer::Plugin_Mongodb);
	if (!db->startup(eventdbip, eventdbport, eventdbname)) {
		Log.Error("[CMainServer] create plugin CMongoDB failed");
		return false;
	}

	CNetwork* servernet = (CNetwork *)MainServer.createPlugin(CMainServer::Plugin_Net4Server);
	if (!servernet->startup(CNet::NET_IO_SELECT, myport, connmax, sendsize, recvsize, packsize)) {
		Log.Error("[CMainServer] create Plugin_Net4Server failed");
		return false;
	}

	CServerMgr* servermgr = (CServerMgr *)MainServer.createPlugin(CMainServer::Plugin_ServerMgr);
	if (!servermgr->startup(CServerMgr::Svr_Central, centralid, centralport, centralip, NULL, NULL, worldID)) {
		Log.Error("[CMainServer] create plugin CServerMgr failed");
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

	if( AnalysisModule.OnMsg(pack) )
		return;

	if (GETSERVERMGR->OnMsg(pack))
		return;
}

void MsgLogic()
{
	PACKET_COMMAND* pack = NULL;
	while ((pack = GETSERVERNET->getHeadPacket()))
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

	GETSERVERMGR->OnLogic();
}

void Output()
{
#if _WIN32
	//设置控制台标题
	char title[128] = {0};
	sprintf(title, "BIServer");
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
