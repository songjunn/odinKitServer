#ifndef _GATESERVER_H_
#define _GATESERVER_H_

#include "server.h"
#include "Singleton.h"

class CGateServer : public CBaseServer, public Singleton<CGateServer>
{
public:
	CGateServer();
	~CGateServer();

	virtual bool onStartup();
	virtual bool onLogic();
	virtual void onShutdown();
	virtual bool onMessage(PACKET_COMMAND* pack);
	virtual void onPrint(char* output);

	void StatusLogic();
};

#define GateServer CGateServer::getSingletonPtr()

#endif //_GATESERVER_H_
