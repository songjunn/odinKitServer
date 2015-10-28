#ifndef _LOGINSERVER_H_
#define _LOGINSERVER_H_

#include "server.h"
#include "Singleton.h"

class CLoginServer : public CBaseServer, public Singleton<CLoginServer>
{
public:
	CLoginServer();
	~CLoginServer();

	virtual bool onStartup();
	virtual void onShutdown();
	virtual bool onLogic() { return true; }
	virtual bool onMessage(PACKET_COMMAND* pack) { return ture; }
	virtual void onPrint(char* output) { return; }

};

#define LoginServer CLoginServer::getSingleton()

#endif //_LOGINSERVER_H_
