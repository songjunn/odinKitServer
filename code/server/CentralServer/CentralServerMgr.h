#pragma once
#include "Singleton.h"
#include "MainServer.h"

class CCentralServerMgr : public CServerMgr, public Singleton< CCentralServerMgr >
{
public:
	bool	OnLogic();

protected:
	bool	_HandlePacket_RegistServer(PACKET_COMMAND* pack);
	bool	_OnAddServer(CServerObj* pServer);

};

#define CentralServerMgr CCentralServerMgr::getSingleton()
