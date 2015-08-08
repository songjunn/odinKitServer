#include "GameServer.h"
#include "LoginModule.h"
#include "DebugModule.h"
#include "LuaEngine.h"
#include "PathFunc.h"
#include "User.h"
#include "PlayerMgr.h"
#include "RoleTemplate.h"
#include "PlayerMgr.h"
#include "UserMgr.h"
#include "NameText.h"
#include "TimerModule.h"
#include "DataModule.h"
#include "NoticeModule.h"
#include "LuaFuncDefine.h"
#ifdef __linux__
#include "linux_type.h"
#include "linux_time.h"
#endif

createFileSingleton(CLog);
createFileSingleton(CLuaEngine);
createFileSingleton(CGameServer);
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

CGameServer::CGameServer()
{
	setType(CBaseServer::Linker_Server_Game);
}

CGameServer::~CGameServer()
{
}

bool CGameServer::onStartup()
{
	CBaseServer::onStartup();

	//初始化启动参数
	GetExePath(g_szExePath, 512);
	char szConfile[256] = { 0 };
	sprintf(szConfile, "%ssconf.lua", g_szExePath);
	if (!LuaEngine.LoadLuaFile(szConfile))
	{
		Log.Error("[CGameServer] Load sconf.lua Error");
		return false;
	}

	//读取启动参数
	const char* centralip = LuaEngine.GetLuaVariableString("CentralServer_ip", "Sconf");
	int centralid = LuaEngine.GetLuaVariableNumber("CentralServer_id", "Sconf");
	int centralport = LuaEngine.GetLuaVariableNumber("CentralServer_port", "Sconf");
	const char* myip = LuaEngine.GetLuaVariableString("GameServer_ip", "Sconf");
	int myid = LuaEngine.GetLuaVariableNumber("GameServer_id", "Sconf");
	int myport = LuaEngine.GetLuaVariableNumber("GameServer_port", "Sconf");
	int worldID = LuaEngine.GetLuaVariableNumber("WorldID", "Sconf");
	int connmax = LuaEngine.GetLuaVariableNumber("connect_count_max", "GameServer");
	int packsize = LuaEngine.GetLuaVariableNumber("packet_pool_size", "GameServer");
	int recvsize = LuaEngine.GetLuaVariableNumber("recv_buff_size", "GameServer");
	int sendsize = LuaEngine.GetLuaVariableNumber("send_buff_size", "GameServer");
	int usercnt = LuaEngine.GetLuaVariableNumber("user_count_max", "GameServer");
	int playercnt = LuaEngine.GetLuaVariableNumber("player_count_max", "GameServer");
	int itemcnt = LuaEngine.GetLuaVariableNumber("item_count_max", "GameServer");
	int herocnt = LuaEngine.GetLuaVariableNumber("hero_count_max", "GameServer");
	const char* udPath = LuaEngine.GetLuaVariableString("MonitorPath", "Key");

	//开服时间
	const char* strOpenTime = LuaEngine.GetLuaVariableString("ServerOpenTime", "Key");
	//g_firstServerTime = StringToDatetime(strOpenTime);

	//加载lua脚本
	if (!onLoadScript())
		return false;

	if (!UserMgr.Initialize("user", playercnt))
		return false;
	if (!PlayerMgr.Initialize("player", playercnt))
		return false;
	if (!EventPool.Create(1000))
		return false;

	DataModule.onLoadConfig("xml//player.xml");
	DataModule.onLoadConfig("xml//item.xml");
	//DataModule.onLoadConfig("xml//hero.xml");

	DataModule.Initialize("objproxy", 100);

	if (!g_PacketPool.Init("Packet", packsize))
		return false;

	//加载数据文件
	char roleFile[256] = { 0 };
	sprintf(roleFile, "%s/data/role.csv", g_szExePath);
	if (!RoleTemplateMgr.LoadCSVData(roleFile))
		return false;
	char nameFile[256] = { 0 };
	sprintf(nameFile, "%s/data/blacklist.csv", g_szExePath);
	if (!NameTextMgr.LoadCSVData(nameFile))
		return false;

	//初始化
	char mpath[1024] = { 0 };
	sprintf(mpath, "%s//FPS_%d.sock", udPath, myid);
	this->initSelf(worldID, CBaseServer::Linker_Server_Game, myid, myport, myip, 0, NULL, mpath);

	CNetwork* servernet = (CNetwork *)this->createPlugin(CBaseServer::Plugin_Net4Server);
	if (!servernet->startup(CNet::NET_IO_SELECT, myport, connmax, sendsize, recvsize, packsize)) {
		Log.Error("[CGameServer] create Plugin_Net4Server failed");
		return false;
	}

	if (!this->createLinker(CBaseServer::Linker_Server_Central, centralid, centralport, centralip, 0, NULL, worldID, true)) {
		Log.Error("[CGameServer] create Central Server failed");
		return false;
	}

	char spath[1024] = { 0 };
	sprintf(spath, "%s//Server_%d.sock", udPath, myid);
	CMonitor* monitor = (CMonitor *)this->createPlugin(CBaseServer::Plugin_Monitor);
	if (!monitor->startup(spath)) {
		Log.Error("[CGameServer] create Plugin_Monitor failed");
		return false;
	}

	return true;
}

bool CGameServer::onMessage(PACKET_COMMAND* pack)
{
	VPROF("CGameServer::onMessage");

	if (!pack) {
		return false;
	}

	if (PlayerMgr.OnMsg(pack))
		return true;

	if (LoginModule.OnMsg(pack))
		return true;

	if (DataModule.onMessage(pack))
		return true;

	if (CBaseServer::onMessage(pack))
		return true;

	if (DebugModule.OnMsg(pack))
		return true;

	CPlayer* player = PlayerMgr.GetObj(pack->GetTrans());
	if (player && player->OnMsg(pack))
		return true;

	Log.Debug("OnMsg no module %d", pack->Type());

	return false;
}

bool CGameServer::onLogic()
{
	CBaseServer::onLogic();

	PlayerMgr.OnLogic();

	TimerModule.OnLogic();

	return true;
}

void CGameServer::onPrint(char* output)
{
	char szPackPool[10240] = { 0 };
	char szUserPool[10240] = { 0 };
	char szPlayerPool[10240] = { 0 };
	char szServer[10240] = { 0 };

	g_PacketPool.Output(szPackPool, 10240);
	UserMgr.m_pool.Output(szUserPool, 10240);
	PlayerMgr.m_pool.Output(szPlayerPool, 10240);
	CBaseServer::onPrint(szServer);

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

void CGameServer::onShutdown()
{
	CBaseServer::onShutdown();
}
bool CGameServer::onLoadScript()
{
	//加载脚本函数和脚本文件
	LuaEngine.RegUserFunc(user_funcs);
	char file[256] = { 0 };
	sprintf(file, "%sscripts//load.lua", g_szExePath);
	if (!LuaEngine.LoadLuaFile(file))
	{
		Log.Error("[CGameServer] Load Script File Failed:%s", file);
		return false;
	}
	Log.Notice("[CGameServer] onLoadScript");
	return true;
}
