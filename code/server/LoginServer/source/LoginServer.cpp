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
    if (!httpd->startup(1313, httpserver_ev_handler)) {
        Log.Error("[CLoginServer] create Plugin_HttpServe failed");
        return false;
    }

    return true;
}

void CLoginServer::onShutdown()
{
    CBaseServer::onShutdown();
}
