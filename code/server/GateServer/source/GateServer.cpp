#include "GateServer.h"

CGateServer::CGateServer()
{
	CBaseServer::CBaseServer(CBaseServer::Linker_Server_GateWay);
}

CGateServer::~CGateServer()
{
}

bool CGateServer::Init()
{
	//初始化启动参数
	char g_szExePath[512] = { 0 };
	GetExePath(g_szExePath, 512);
	char szConfile[256] = { 0 };
	sprintf(szConfile, "%ssconf.lua", g_szExePath);
	if (!LuaEngine.LoadLuaFile(szConfile))
	{
		Log.Error("[CGateServer] Load sconf.lua Error");
		return false;
	}

	//读取启动参数
	const char* centralip = LuaEngine.GetLuaVariableString("CentralServer_ip", "Sconf");
	int centralid = LuaEngine.GetLuaVariableNumber("CentralServer_id", "Sconf");
	int centralport = LuaEngine.GetLuaVariableNumber("CentralServer_port", "Sconf");
	const char* myip = LuaEngine.GetLuaVariableString("GateServer_ip", "Sconf");
	int myid = LuaEngine.GetLuaVariableNumber("GateServer_id", "Sconf");
	int myport = LuaEngine.GetLuaVariableNumber("GateServer_port", "Sconf");
	int extport = LuaEngine.GetLuaVariableNumber("GateServer_Client_port", "Sconf");
	const char* extip = LuaEngine.GetLuaVariableString("GateServer_inetip", "Sconf");
	int worldID = LuaEngine.GetLuaVariableNumber("WorldID", "Sconf");
	int connmax = LuaEngine.GetLuaVariableNumber("connect_count_max", "GateServer");
	int packsize = LuaEngine.GetLuaVariableNumber("packet_pool_size", "GateServer");
	int recvsize = LuaEngine.GetLuaVariableNumber("recv_buff_size", "GateServer");
	int sendsize = LuaEngine.GetLuaVariableNumber("send_buff_size", "GateServer");
	int iocpconnmax = LuaEngine.GetLuaVariableNumber("gateway_connect_max", "GateServer");
	int iocppacksize = LuaEngine.GetLuaVariableNumber("gateway_queue_max", "GateServer");
	int iocprecvsize = LuaEngine.GetLuaVariableNumber("gateway_recv_size", "GateServer");
	int iocpsendsize = LuaEngine.GetLuaVariableNumber("gateway_send_size", "GateServer");
	int usercnt = LuaEngine.GetLuaVariableNumber("user_count_max", "GateServer");
	int playercnt = LuaEngine.GetLuaVariableNumber("player_count_max", "GateServer");
	const char* udPath = LuaEngine.GetLuaVariableString("MonitorPath", "Key");
	int hearttimeout = LuaEngine.GetLuaVariableNumber("user_heart_timeout", "GateServer");
	int keytimeout = LuaEngine.GetLuaVariableNumber("user_key_timeout", "GateServer");
	int packlimit = LuaEngine.GetLuaVariableNumber("user_pack_limit", "GateServer");

	//初始化
	myid = param_id > 0 ? param_id : myid;
	myport = param_id > 0 ? param_port : myport;
	extport = param_id > 0 ? param_extport : extport;
	char mpath[1024] = { 0 };
	sprintf(mpath, "%s//FPS_%d.sock", udPath, myid);
	this->initSelf(worldID, CBaseServer::Linker_Server_GateWay, myid, myport, myip, extport, extip, mpath);

	if (!UserMgr.Initialize("user", usercnt))
		return false;

	UserMgr.InitConfig(keytimeout, hearttimeout, packlimit);

	if (!g_PacketPool.Init("Packet", packsize))
		return false;

	CNetwork* servernet = (CNetwork *)this->createPlugin(CBaseServer::Plugin_Net4Server);
	if (!servernet->startup(CNet::NET_IO_SELECT, myport, connmax, sendsize, recvsize, packsize)) {
		Log.Error("[CGateServer] create Plugin_Net4Server failed");
		return false;
	}

	CNetwork* clientnet = (CNetwork *)this->createPlugin(CBaseServer::Plugin_Net4Client);
	if (!clientnet->startup(CNet::NET_IO_EPOLL, extport, iocpconnmax, iocpsendsize, iocprecvsize, iocppacksize)) {
		Log.Error("[CGateServer] create Plugin_Net4Client failed");
		return false;
	}

	if (!this->createLinker(CBaseServer::Linker_Server_Central, centralid, centralport, centralip, NULL, NULL, worldID)) {
		Log.Error("[CGateServer] create Central Server failed");
		return false;
	}

#ifdef __linux__
	char spath[1024] = { 0 };
	sprintf(spath, "%s//Server_%d.sock", udPath, myid);
	NEW CMonitor(spath, &StatusOutput);
#endif

	return true;
}
