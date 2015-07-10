#pragma once
#include "ServerMgr.h"

class CCentralServerMgr : public CServerMgr
{
public:
	bool	OnLogic();

protected:
	bool	_HandlePacket_RegistServer(PACKET_COMMAND* pack);
	bool	_OnAddServer(CServerObj* pServer);

};

#define CentralServerMgr CCentralServerMgr::getSingleton()
