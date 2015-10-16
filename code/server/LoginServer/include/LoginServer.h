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
	virtual bool onLogic();
	virtual void onShutdown();
	virtual bool onMessage(PACKET_COMMAND* pack);
	virtual void onPrint(char* output);

};

#define LoginServer CLoginServer::getSingleton()

#endif //_LOGINSERVER_H_
