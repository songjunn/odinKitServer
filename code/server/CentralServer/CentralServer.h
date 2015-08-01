#ifndef _CENTRALSERVER_H_
#define _CENTRALSERVER_H_

#include "server.h"
#include "Singleton.h"

class CCentralServer : public CBaseServer, public Singleton<CCentralServer>
{
public:
	CCentralServer();
	~CCentralServer();

	virtual bool onStartup();
	virtual bool onLogic();
	virtual void onShutdown();
	virtual bool onMessage(PACKET_COMMAND* pack);
	virtual void onPrint(char* output);

	virtual bool loop_linkers();

	virtual bool _HandlePacket_RegistServer(PACKET_COMMAND* pack);
	virtual bool _OnAddServer(CLinker* pServer);
};

#define CentralServer CCentralServer::getSingleton()

#endif //_CENTRALSERVER_H_
