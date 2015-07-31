#ifndef _BISERVER_H_
#define _BISERVER_H_

#include "server.h"
#include "Singleton.h"

class CBIServer : public CBaseServer, public Singleton<CBIServer>
{
public:
	CBIServer();
	~CBIServer();

	virtual bool onStartup();
	virtual bool onLogic();
	virtual void onShutdown();
	virtual bool onMessage(PACKET_COMMAND* pack);
	virtual void onPrint(char* output);
};

#define BIServer CBIServer::getSingleton()

#endif //_BISERVER_H_
