#ifndef SHARED_NETCLIENT_H
#define SHARED_NETCLIENT_H

#include "SharedInc.h"
#include "Net.h"

class CClientNet : public CNet
{
public:
	CClientNet();
	~CClientNet();

	virtual bool	HandlePacket(PACKET_COMMAND * pCmd);
};

#endif	//SHARED_NETCLIENT_H
