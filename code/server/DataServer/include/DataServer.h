#ifndef _DATASERVER_H_
#define _DATASERVER_H_

#include "server.h"
#include "Singleton.h"

class CDataServer : public CBaseServer, public Singleton<CDataServer>
{
public:
	CDataServer();
	~CDataServer();

	virtual bool onStartup();
	virtual bool onLogic();
	virtual void onShutdown();
	virtual bool onMessage(PACKET_COMMAND* pack);
	virtual void onPrint(char* output);
};

#define DataServer CDataServer::getSingleton()

#endif //_DATASERVER_H_
