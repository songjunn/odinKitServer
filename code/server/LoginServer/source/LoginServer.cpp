#include "LoginServer.h"
#include "UserMgr.h"
#include "LuaEngine.h"
#include "PathFunc.h"
#ifdef __linux__
#include <unistd.h>
#include "linux_time.h"
#endif
#include "MessageTypeDefine.pb.h"
#include "MessageServer.pb.h"

createFileSingleton(CLog);
createFileSingleton(CLuaEngine);
createFileSingleton(CLoginServer);
createFileSingleton(CUserMgr);

CObjectMemoryPool<PACKET_COMMAND>	g_PacketPool;
extern CObjectMemoryPool<OperObj>	g_MongoOperPool;

static int httpserver_ev_handler(struct mg_connection *conn, enum mg_event ev) {	if (ev == MG_REQUEST) {		Log.Debug("[HttpServer]Handle Event:%d ip:%s", ev, conn->remote_ip);		if (true) {			mg_send_data(conn, "0", 1);		} else {			mg_send_data(conn, "1", 1);
		}		return MG_TRUE;	}	else if (ev == MG_AUTH) {		return MG_TRUE;	}	else {		return MG_FALSE;	}}

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
    if (!LuaEngine.LoadLuaFile(szConfile)) {
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

    if (!UserMgr.Initialize("user", usercnt)) {
	    return false;
    }

    if (!g_PacketPool.Init("Packet", packsize)) {
	    return false;
    }

    if (!g_MongoOperPool.Init("MongoOper", dboperator)) {
	    return false;
    }
	
    char spath[1024] = { 0 };
    sprintf(spath, "%s//Server_%d.sock", udPath, myid);
    CMonitor* monitor = (CMonitor *)this->createPlugin(CBaseServer::Plugin_Monitor);
    if (!monitor->startup(spath)) {
	    Log.Error("[CLoginServer] create Plugin_Monitor failed");
	    return false;
    }

	CHttpServe* httpd = (CHttpServe *)this->createPlugin(CBaseServer::Plugin_HttpServe);
	if (!httpd->startup(1313, httpserver_ev_handler, 3)) {
		Log.Error("[CLoginServer] create Plugin_HttpServe failed");
		return false;
	}

    CMongoDB* db = (CMongoDB *)this->createPlugin(CBaseServer::Plugin_Mongodb);
    if (!db->startup(gamedbip, gamedbport, gamedbname)) {
		Log.Error("[CLoginServer] create Plugin_Mongodb failed");
	    return false;
    }

    return true;
}

void CLoginServer::onShutdown()
{
    CBaseServer::onShutdown();
}
