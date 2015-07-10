// DataServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MainServer.h"
#include "CommandMgr.h"
#include "exception.h"
#include "LoginModule.h"
#include "DebugModule.h"
#include "LuaEngine.h"
#include "PathFunc.h"
#include "User.h"
#include "PlayerMgr.h"
#include "RoleTemplate.h"
#include "PlayerMgr.h"
#include "UserMgr.h"
#include "vprof.h"
#include "NameText.h"
#include "TimerModule.h"
#include "DataModule.h"
#include "NoticeModule.h"
#include "LuaFuncDefine.h"
#ifdef __linux__
#include "ServerMgr.h"
#include "DBResult.h"
#include "linux_type.h"
#include "linux_time.h"
#include "monitor.h"
#endif


createFileSingleton(CLog);
createFileSingleton(CLuaEngine);
createFileSingleton(CServerMgr);
createFileSingleton(CMainServer);
createFileSingleton(CDBResult);
createFileSingleton(CCommandMgr);
createFileSingleton(CLoginModule);
createFileSingleton(CEventPool);
createFileSingleton(CPlayerMgr);
createFileSingleton(CUserMgr);
createFileSingleton(CRoleTemplateMgr);
createFileSingleton(CDebugModule);
createFileSingleton(CNameTextMgr);
createFileSingleton(CTimerModule);
createFileSingleton(CNoticeModule);
createFileSingleton(CDataModule);


CObjectMemoryPool<PACKET_COMMAND>	g_PacketPool;
char g_szExePath[512];


void StatusOutput(char* output)
{
    char szPackPool[10240] = {0};
	char szUserPool[10240] = {0};
	char szPlayerPool[10240] = {0};
	char szServer[10240] = {0};

	g_PacketPool.Output(szPackPool, 10240);
	UserMgr.m_pool.Output(szUserPool, 10240);
	PlayerMgr.m_pool.Output(szPlayerPool, 10240);
	ServerMgr.Output(szServer);

	sprintf(output, 
		" GameServer monitor: User:%d Player:%d\n"
        " ======================================================\n"
        " memory pool used:\n"
        "  %s"
		"  %s"
		"  %s"
		" ======================================================\n"
        " %s",
		UserMgr.Count(), PlayerMgr.Count(), 
		szPackPool, szUserPool, szPlayerPool,
		szServer);
}

void onReloadData()
{

}

bool onLoadScript()
{
	//加载脚本函数和脚本文件
	LuaEngine.RegUserFunc(user_funcs);
	char file[256]= { 0 };
	sprintf(file,"%sscripts//load.lua", g_szExePath);
	if( !LuaEngine.LoadLuaFile(file) )
	{
		Log.Error("[GameServer] Load Script File Failed:%s", file);
		return false;
	}
	Log.Notice("[GameServer] onLoadScript");
	return true;
}

bool Begin()
{
	GetExePath( g_szExePath, 512 );

	//启动MainServer
	if( !MainServer.Startup("GameServer") )
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
	const char* centralip = LuaEngine.GetLuaVariableString( "CentralServer_ip","Sconf" );
	int centralid		= LuaEngine.GetLuaVariableNumber( "CentralServer_id",	"Sconf" );
	int centralport		= LuaEngine.GetLuaVariableNumber( "CentralServer_port","Sconf" );
	const char* myip	= LuaEngine.GetLuaVariableString( "GameServer_ip",		"Sconf" );
	int myid			= LuaEngine.GetLuaVariableNumber( "GameServer_id",		"Sconf" );
	int myport			= LuaEngine.GetLuaVariableNumber( "GameServer_port",	"Sconf" );
	int worldID         = LuaEngine.GetLuaVariableNumber( "WorldID",            "Sconf" );
	int connmax			= LuaEngine.GetLuaVariableNumber( "connect_count_max",	"GameServer" );
	int packsize		= LuaEngine.GetLuaVariableNumber( "packet_pool_size",	"GameServer" );
	int recvsize		= LuaEngine.GetLuaVariableNumber( "recv_buff_size",		"GameServer" );
	int sendsize		= LuaEngine.GetLuaVariableNumber( "send_buff_size",		"GameServer" );
	int usercnt 		= LuaEngine.GetLuaVariableNumber( "user_count_max",		"GameServer" );
	int playercnt		= LuaEngine.GetLuaVariableNumber( "player_count_max",	"GameServer" );
	int itemcnt			= LuaEngine.GetLuaVariableNumber( "item_count_max",		"GameServer" );
	int herocnt         = LuaEngine.GetLuaVariableNumber( "hero_count_max",     "GameServer" );
	const char* udPath	= LuaEngine.GetLuaVariableString( "MonitorPath",		"Key" );

	//开服时间
	const char* strOpenTime = LuaEngine.GetLuaVariableString("ServerOpenTime", "Key");
	//g_firstServerTime = StringToDatetime(strOpenTime);

	//加载lua脚本
	if (!onLoadScript())
		return false;

	if( !UserMgr.Initialize("user", playercnt) )
		return false;
	if( !PlayerMgr.Initialize("player", playercnt) )
		return false;
	if( !EventPool.Create(1000) )
		return false;

	DataModule.initObjProxy("xml//player.xml");
	DataModule.initObjProxy("xml//item.xml");
	//DataModule.initObjProxy("xml//hero.xml");

	DataModule.Initialize("objproxy", 100);

	if( !g_PacketPool.Init("Packet", packsize) )
		return false;

	MainServer.SetPacketSize(packsize);

	//加载数据文件
	char roleFile[256]= { 0 };
	sprintf(roleFile,"%s/data/role.csv", g_szExePath);
	if( !RoleTemplateMgr.LoadCSVData(roleFile) )
		return false;
	char nameFile[256] = {0};
	sprintf(nameFile,"%s/data/blacklist.csv", g_szExePath);
	if( !NameTextMgr.LoadCSVData(nameFile) )
		return false;

	//初始化
	char mpath[1024] = {0};
	sprintf(mpath, "%s//FPS_%d.sock", udPath, myid);
	MainServer.Init(worldID, Svr_Game, myid, myport, myip, 0, NULL, mpath);

	if( !MainServer.StartupServerNet(connmax, sendsize, recvsize, packsize) )
		return false;

	if( !ServerMgr.CreateServer(Svr_Central, centralid, centralport, centralip, NULL, NULL, worldID, true) )
		return false;

	//执行脚本
	if( !LuaEngine.RunLuaFunction("Startup", "Server") )
		return false;

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

	if( PlayerMgr.OnMsg(pack) )
		return;

	if( LoginModule.OnMsg(pack) )
		return;

	if( DataModule.onMessage(pack) )
		return;

	if( ServerMgr.OnMsg(pack) )
		return;

	if (DebugModule.OnMsg(pack)) 
		return;

	CPlayer* player = PlayerMgr.GetObj( pack->GetTrans() );
	if( player && player->OnMsg( pack ) )
		return;

	Log.Debug("OnMsg no module %d", pack->Type());

	return;
}

void MsgLogic()
{
	VPROF("MsgLogic");
	//Log.Debug("MsgLogic begin ");
	PACKET_COMMAND* pack = NULL;
	int count = 0;
	while( (pack = MainServer.GetHeadPacket()) && count++ <= 1000 )
	{
		OnMsg(pack);

		g_PacketPool.Free( pack );
	}
	//Log.Debug("MsgLogic end");
}

void Logic()
{
	VProfCurrentProfile().Pause();
	VProfCurrentProfile().Server_OutputReport();
	VProfCurrentProfile().Resume();
	VProfCurrentProfile().MarkFrame();

	MsgLogic();

	PlayerMgr.OnLogic();

	TimerModule.OnLogic();

	ServerMgr.OnLogic();

	CommandMgr.OnLogic();
}

void Output()
{
#if _WIN32
	//设置控制台标题
	char title[128] = {0};
	sprintf(title, "GameServer  Player:%d", PlayerMgr.Count(), );
	SetConsoleTitle(title);

	system("cls");
#endif
}

void End()
{
	Log.Notice("End ..");
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
			else if (MainServer.getServerState() == EStateReloadData)
			{
				onReloadData();
				MainServer.setServerState(EStateRunning);
			}
			else if (MainServer.getServerState() == EStateReloadScript)
			{
				onLoadScript();
				MainServer.setServerState(EStateRunning);
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

		//控制在每秒20帧
#ifdef _WIN32
		Sleep(50);
#else
#ifdef __linux__
		usleep(50000);
#endif
#endif
	}

	End();

	return 0;
}

