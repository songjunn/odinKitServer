#include "LoginServer.h"
#include "LuaEngine.h"
#include "PathFunc.h"
#include "Log.h"
#ifdef __linux__
#include <unistd.h>
#include "linux_time.h"
#endif

createFileSingleton(CLog);
createFileSingleton(CLuaEngine);
createFileSingleton(CLoginServer);

CObjectMemoryPool<PACKET_COMMAND>	g_PacketPool;

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

	CHttpServe* httpd = (CHttpServe *)this->createPlugin(CBaseServer::Plugin_HttpServe);
	if (!httpd->startup(1313, httpserver_ev_handler, 3)) {
		Log.Error("[CLoginServer] create Plugin_HttpServe failed");
		return false;
	}

    return true;
}

void CLoginServer::onShutdown()
{
    CBaseServer::onShutdown();
}
