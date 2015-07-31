#include "LoginServer.h"
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
createFileSingleton(CLoginServer);
createFileSingleton(CUserMgr);
createFileSingleton(CWorldConfig);

CObjectMemoryPool<PACKET_COMMAND>	g_PacketPool;
extern CObjectMemoryPool<OperObj>	g_MongoOperPool;

CLoginServer::CLoginServer()
{
	setType(CBaseServer::Linker_Server_Login);
}

CLoginServer::~CLoginServer()
{
}

bool CLoginServer::onStartup()
{
	CBaseServer::onStartup();

	//初始化启动参数
	char g_szExePath[512] = { 0 };
	GetExePath(g_szExePath, 512);
	char szConfile[256] = { 0 };
	sprintf(szConfile, "%ssconf.lua", g_szExePath);
	if (!LuaEngine.LoadLuaFile(szConfile))
	{
		Log.Error("[CLoginServer] Load sconf.lua Error");
		return false;
	}

	//读取启动参数
	const char* centralip = LuaEngine.GetLuaVariableString("CentralServer_ip", "Sconf");
	int centralid = LuaEngine.GetLuaVariableNumber("CentralServer_id", "Sconf");
	int centralport = LuaEngine.GetLuaVariableNumber("CentralServer_port", "Sconf");
	const char* myip = LuaEngine.GetLuaVariableString("LoginServer_ip", "Sconf");
	int myid = LuaEngine.GetLuaVariableNumber("LoginServer_id", "Sconf");
	int myport = LuaEngine.GetLuaVariableNumber("LoginServer_port", "Sconf");
	const char* gamedbip = LuaEngine.GetLuaVariableString("db_game_ip", "Sconf");
	const char* gamedbname = LuaEngine.GetLuaVariableString("db_game_name", "Sconf");
	const char* gamedbport = LuaEngine.GetLuaVariableString("db_game_port", "Sconf");
	int worldID = LuaEngine.GetLuaVariableNumber("WorldID", "Sconf");
	int connmax = LuaEngine.GetLuaVariableNumber("connect_count_max", "LoginServer");
	int packsize = LuaEngine.GetLuaVariableNumber("packet_pool_size", "LoginServer");
	int recvsize = LuaEngine.GetLuaVariableNumber("recv_buff_size", "LoginServer");
	int sendsize = LuaEngine.GetLuaVariableNumber("send_buff_size", "LoginServer");
	int clientport = LuaEngine.GetLuaVariableNumber("LoginServer_Client_port", "Sconf");
	int clientconnmax = LuaEngine.GetLuaVariableNumber("gateway_connect_max", "LoginServer");
	int clientpacksize = LuaEngine.GetLuaVariableNumber("gateway_queue_max", "LoginServer");
	int clientrecvsize = LuaEngine.GetLuaVariableNumber("gateway_recv_size", "LoginServer");
	int clientsendsize = LuaEngine.GetLuaVariableNumber("gateway_send_size", "LoginServer");
	int usercnt = LuaEngine.GetLuaVariableNumber("user_count_max", "LoginServer");
	int hearttimeout = LuaEngine.GetLuaVariableNumber("user_heart_timeout", "LoginServer");
	int dboperator = LuaEngine.GetLuaVariableNumber("db_operator_max", "LoginServer");
	const char* udPath = LuaEngine.GetLuaVariableString("MonitorPath", "Key");

	//初始化
	char mpath[1024] = { 0 };
	sprintf(mpath, "%s//FPS_%d.sock", udPath, myid);
	this->initSelf(worldID, CBaseServer::Linker_Server_Login, myid, myport, myip, 0, NULL, mpath);

	if (!UserMgr.Initialize("user", usercnt))
		return false;

	if (!g_PacketPool.Init("Packet", packsize))
		return false;

	if (!g_MongoOperPool.Init("MongoOper", dboperator))
		return false;

	CNetwork* servernet = (CNetwork *)this->createPlugin(CBaseServer::Plugin_Net4Server);
	if (!servernet->startup(CNet::NET_IO_SELECT, myport, connmax, sendsize, recvsize, packsize)) {
		Log.Error("[CLoginServer] create Plugin_Net4Server failed");
		return false;
	}

	CNetwork* clientnet = (CNetwork *)this->createPlugin(CBaseServer::Plugin_Net4Client);
	if (!clientnet->startup(CNet::NET_IO_EPOLL, clientport, clientconnmax, clientsendsize, clientrecvsize, clientpacksize)) {
		Log.Error("[CLoginServer] create Plugin_Net4Client failed");
		return false;
	}

	if (!this->createLinker(CBaseServer::Linker_Server_Central, centralid, centralport, centralip, 0, NULL, worldID, true)) {
		Log.Error("[CLoginServer] create Central Server failed");
		return false;
	}

	char spath[1024] = { 0 };
	sprintf(spath, "%s//Server_%d.sock", udPath, myid);
	CMonitor* monitor = (CMonitor *)this->createPlugin(CBaseServer::Plugin_Monitor);
	if (!monitor->startup(spath)) {
		Log.Error("[CLoginServer] create Plugin_Monitor failed");
		return false;
	}

	CMongoDB* db = (CMongoDB *)this->createPlugin(CBaseServer::Plugin_Mongodb);
	if (!db->startup(gamedbip, gamedbport, gamedbname)) {
		return false;
	}

	UserMgr.LoadFactId(worldID);
	UserMgr.SetUserTimeout(hearttimeout);

	return true;
}

bool CLoginServer::onMessage(PACKET_COMMAND* pack)
{
	VPROF("CLoginServer::onMessage");

	if (!pack) {
		return false;
	}

	switch (pack->Type())
	{
	case Message::MSG_REQUEST_USER_CHECK:
	case Message::MSG_REQUEST_GUEST_CHECK:
		UserMgr.OnMsg(pack);
		return true;
	case Message::MSG_SERVER_NET_ACCEPT:
	case Message::MSG_SERVER_NET_CLOSE:
		CBaseServer::onMessage(pack);
		return true;
	default:
		break;
	}

	//从服务端发来的消息
	CLinker* pServer = getServer(pack->GetNetID());
	if (pServer)
	{
		if (Message::MSG_SERVER_BEGIN >= pack->Type() || Message::MSG_SERVER_END <= pack->Type())
		{
			Log.Error("[CLoginServer] Recv Error Message From Server, type:%d, sock:%d", pack->Type(), pack->GetNetID());
			return true;
		}

		switch (pack->Type())
		{
		case Message::MSG_SERVER_SYNCGATELOAD:
		case Message::MSG_SERVER_SYNCSERVER:
		case Message::MSG_SERVER_NET_CONNECT:
		case Message::MSG_SERVER_REGISTER:
			CBaseServer::onMessage(pack);
			break;
		default:
			break;
		}

		return true;
	}

	return false;
}

bool CLoginServer::onLogic()
{
	CBaseServer::onLogic();

	UserMgr.UserHeartLogic();

	return true;
}

void CLoginServer::onPrint(char* output)
{
	char szPackPool[10240] = { 0 };
	char szMongoPool[10240] = { 0 };
	char szUserPool[10240] = { 0 };
	char szServer[10240] = { 0 };

	g_PacketPool.Output(szPackPool, 10240);
	g_MongoOperPool.Output(szMongoPool, 10240);
	UserMgr.m_pool.Output(szUserPool, 10240);
	CBaseServer::onPrint(szServer);

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

void CLoginServer::onShutdown()
{
	CBaseServer::onShutdown();
}

CLinker* CLoginServer::getLowerGate(int world)
{
	CLinker* pLowerGate = NULL;

	FOR_EACH_LL(getLinkerList(), index)
	{
		CLinker* pServer = getLinkerList()[index];
		if (!pServer || pServer->m_bBreak || pServer->m_type != CBaseServer::Linker_Server_GateWay || pServer->m_worldID != world)
			continue;

		if (!pLowerGate || pLowerGate->m_count > pServer->m_count)
		{
			pLowerGate = pServer;
		}
	}

	if (pLowerGate)
		pLowerGate->m_count++;

	return pLowerGate;
}
