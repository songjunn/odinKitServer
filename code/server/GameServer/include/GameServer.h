#ifndef _GAMESERVER_H_
#define _GAMESERVER_H_

#include "server.h"
#include "Singleton.h"

class CGameServer : public CBaseServer, public Singleton<CGameServer>
{
public:
	CGameServer();
	~CGameServer();

	virtual bool onStartup();
	virtual bool onLogic();
	virtual void onShutdown();
	virtual bool onMessage(PACKET_COMMAND* pack);
	virtual void onPrint(char* output);
	virtual bool onLoadScript();
};

#define GameServer CGameServer::getSingleton()

#endif //_GAMESERVER_H_
