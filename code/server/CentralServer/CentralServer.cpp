#include "CentralServer.h"
#include "exception.h"
#include "LuaEngine.h"
#include "PathFunc.h"
#ifdef __linux__
#include "linux_time.h"
#endif

createFileSingleton(CLog);
createFileSingleton(CLuaEngine);
createFileSingleton(CCentralServer);

CObjectMemoryPool<PACKET_COMMAND>	g_PacketPool;

CCentralServer::CCentralServer()
{
	setType(CBaseServer::Linker_Server_Central);
}

CCentralServer::~CCentralServer()
{
}

bool CCentralServer::onStartup()
{
	CBaseServer::onStartup();

	//初始化启动参数
	char g_szExePath[512] = { 0 };
	GetExePath(g_szExePath, 512);
	char szConfile[256] = { 0 };
	sprintf(szConfile, "%ssconf.lua", g_szExePath);
	if (!LuaEngine.LoadLuaFile(szConfile))
	{
		Log.Error("[CDataServer] Load sconf.lua Error");
		return false;
	}

	//读取启动参数
	const char* myip = LuaEngine.GetLuaVariableString("CentralServer_ip", "Sconf");
	int myid = LuaEngine.GetLuaVariableNumber("CentralServer_id", "Sconf");
	int myport = LuaEngine.GetLuaVariableNumber("CentralServer_port", "Sconf");
	int worldID = LuaEngine.GetLuaVariableNumber("WorldID", "Sconf");
	int connmax = LuaEngine.GetLuaVariableNumber("connect_count_max", "CentralServer");
	int packsize = LuaEngine.GetLuaVariableNumber("packet_pool_size", "CentralServer");
	int recvsize = LuaEngine.GetLuaVariableNumber("recv_buff_size", "CentralServer");
	int sendsize = LuaEngine.GetLuaVariableNumber("send_buff_size", "CentralServer");
	const char* udPath = LuaEngine.GetLuaVariableString("MonitorPath", "Key");

	if (!g_PacketPool.Init("Packet", packsize))
		return false;

	//初始化
	char mpath[1024] = { 0 };
	sprintf(mpath, "%s//FPS_%d.sock", udPath, myid);
	this->initSelf(worldID, CBaseServer::Linker_Server_Central, myid, myport, myip, 0, NULL, mpath);

	CNetwork* servernet = (CNetwork *)this->createPlugin(CBaseServer::Plugin_Net4Server);
	if (!servernet->startup(CNet::NET_IO_SELECT, myport, connmax, sendsize, recvsize, packsize)) {
		Log.Error("[CDataServer] create Plugin_Net4Server failed");
		return false;
	}

	char spath[1024] = { 0 };
	sprintf(spath, "%s//Server_%d.sock", udPath, myid);
	CMonitor* monitor = (CMonitor *)this->createPlugin(CBaseServer::Plugin_Monitor);
	if (!monitor->startup(spath)) {
		Log.Error("[CDataServer] create Plugin_Monitor failed");
		return false;
	}

	return true;
}

bool CCentralServer::onMessage(PACKET_COMMAND* pack)
{
	VPROF("CCentralServer::onMessage");

	if (!pack) {
		return false;
	}

	if (CBaseServer::onMessage(pack))
		return true;

	Log.Debug("OnMsg no module %d", pack->Type());

	return false;
}

bool CCentralServer::onLogic()
{
	CBaseServer::onLogic();

	return true;
}

void CCentralServer::onPrint(char* output)
{
	char szPackPool[10240] = { 0 };
	char szServer[10240] = { 0 };

	g_PacketPool.Output(szPackPool, 10240);
	CBaseServer::onPrint(szServer);

	sprintf(output,
		" CentralServer monitor: \n"
		" ======================================================\n"
		" memory pool used:\n"
		"  %s"
		" ======================================================\n"
		" %s",
		szPackPool, szServer);
}

void CCentralServer::onShutdown()
{
	CBaseServer::onShutdown();
}
