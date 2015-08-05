#include "GateServer.h"
#include "UserMgr.h"
#include "LuaEngine.h"
#include "PathFunc.h"
#ifdef __linux__
#include "linux_time.h"
#endif
#include "MessageTypeDefine.pb.h"
#include "MessageServer.pb.h"

createFileSingleton(CLog);
createFileSingleton(CLuaEngine);
createFileSingleton(CGateServer);
createFileSingleton(CUserMgr);

static TMV g_StatusLogicTime = 0;
CObjectMemoryPool<PACKET_COMMAND>	g_PacketPool;

CGateServer::CGateServer()
{
	setType(CBaseServer::Linker_Server_GateWay);
}

CGateServer::~CGateServer()
{
}

bool CGateServer::onStartup()
{
	CBaseServer::onStartup();

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

	if (!this->createLinker(CBaseServer::Linker_Server_Central, centralid, centralport, centralip, 0, NULL, worldID, true)) {
		Log.Error("[CGateServer] create Central Server failed");
		return false;
	}

	char spath[1024] = { 0 };
	sprintf(spath, "%s//Server_%d.sock", udPath, myid);
	CMonitor* monitor = (CMonitor *)this->createPlugin(CBaseServer::Plugin_Monitor);
	if (!monitor->startup(spath)) {
		Log.Error("[CGateServer] create Plugin_Monitor failed");
		return false;
	}

	return true;
}

bool CGateServer::onMessage(PACKET_COMMAND* pack)
{
	VPROF("CGateServer::onMessage");

	if (!pack) {
		return false;
	}

	switch (pack->Type())
	{
	// from net
	case Message::MSG_SERVER_NET_ACCEPT:
	case Message::MSG_SERVER_REGISTER:
		CBaseServer::onMessage(pack);
		return true;
	case Message::MSG_REQUEST_USER_LOGIN:
		UserMgr.OnMsg(pack);
		return true;
	case Message::MSG_SERVER_NET_CLOSE:
		CBaseServer::onMessage(pack);
		UserMgr.OnMsg(pack);
		return true;
	default:
		break;
	}

	CLinker* pServer = getServer(pack->GetNetID());
	if (pServer)
	{
		if (Message::MSG_SERVER_BEGIN >= pack->Type() || Message::MSG_SERVER_END <= pack->Type())
		{
			Log.Error("[GateServer] Recv Wrong Message From Server, Type:%d, Sock:%d, Server:%d", pack->Type(), pack->GetNetID(), pServer->m_type);
			return false;
		}

		switch (pack->Type())
		{
		case Message::MSG_USER_PRLOGIN_REQUEST:
		case Message::MSG_PLAYER_LOGIN_REQUEST:
		case Message::MSG_PLAYER_LOAD_COUNT:
		case Message::MSG_COMMON_ERROR:
		case Message::MSG_USER_DISPLACE:
			UserMgr.OnMsg(pack);
			break;
		case Message::MSG_SERVER_SYNCSERVER:
		case Message::MSG_SERVER_NET_CONNECT:
			CBaseServer::onMessage(pack);
			break;
		default:
			SOCKET s = UserMgr.GetNetIDByPID(pack->GetTrans());
			GETCLIENTNET(this)->sendMsg(s, pack);
			Log.Debug("[GateServer] Transmit From:%d To Client pid:"INT64_FMT" sock:%d packet:%d size:%d", pack->GetNetID(), pack->GetTrans(), s, pack->Type(), pack->Size());
			break;
		}

		return true;
	}

	CUser* pUser = UserMgr.GetObj(pack->GetNetID());
	if (pUser)
	{
		if (Message::MSG_CLIENT_BEGIN >= pack->Type() || Message::MSG_CLIENT_END <= pack->Type())
		{
			Log.Error("[GateServer] Recv Wrong Message From Client, Type:%d, Sock:%d, User:"INT64_FMT, pack->Type(), pack->GetNetID(), pUser->m_id);
			return false;
		}

		//验证消息来源
		if (pack->GetTrans() != pUser->m_id)
		{
			Log.Error("[GateServer] Message Source Error, Msg:"INT64_FMT", Type:%d, User:"INT64_FMT, pack->GetTrans(), pack->Type(), pUser->m_id);
			return false;
		}

		//user发包频率限制
		if (!UserMgr.UserPacketLimit(pUser))
			return false;

		//设置转发对象
		pack->SetTrans(pUser->m_LogonPlayer);

		switch (pack->Type())
		{
		case Message::MSG_REQUEST_NET_TEST:
			GETCLIENTNET(this)->sendMsg(pUser->m_ClientSock, pack);
			break;
		case Message::MSG_REQUEST_USER_HEART:
		case Message::MSG_REQUEST_USER_LOGOUT:
		case Message::MSG_REQUEST_PLAYER_CREATE:
			UserMgr.OnMsg(pack);
			break;
		default:	//默认向GameServer转发
			Log.Debug("[GateServer] Transmit To GameServer packet:%d size:%d", pack->Type(), pack->Size());
			GETSERVERNET(this)->sendMsg(pUser->m_GameSock, pack);
			break;
		}

		return true;
	}

	return false;
}

void CGateServer::StatusLogic()
{
	Message::SyncGateLoad msg;
	msg.set_count(UserMgr.Count());

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_SERVER_SYNCGATELOAD);
	GETSERVERNET(this)->sendMsg(getServerSock(CBaseServer::Linker_Server_Login), &pack);
}

bool CGateServer::onLogic()
{
	CBaseServer::onLogic();

	UserMgr.OnLogic();

	//30秒同步一次负载
	TMV nowtime = timeGetTime();
	if (nowtime - g_StatusLogicTime >= 30000)
	{
		g_StatusLogicTime = nowtime;

		StatusLogic();
	}

	return true;
}

void CGateServer::onPrint(char* output)
{
	char szPackPool[10240] = { 0 };
	char szUserPool[10240] = { 0 };
	char szServer[10240] = { 0 };

	g_PacketPool.Output(szPackPool, 10240);
	UserMgr.m_pool.Output(szUserPool, 10240);
	CBaseServer::onPrint(szServer);

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

void CGateServer::onShutdown()
{
	CBaseServer::onShutdown();
}

CLinker* CGateServer::getLowerGame()
{
	CLinker* pLowerGame = NULL;

	FOR_EACH_LL(getLinkerList(), index)
	{
		CLinker* pServer = getLinkerList()[index];
		if (!pServer || pServer->m_bBreak || pServer->m_type != CBaseServer::Linker_Server_Game)
			continue;

		if (!pLowerGame || pLowerGame->m_count > pServer->m_count)
		{
			pLowerGame = pServer;
		}
	}

	/*if (pLowerGame)
		pLowerGame->m_count++;*/

	return pLowerGame;
}
