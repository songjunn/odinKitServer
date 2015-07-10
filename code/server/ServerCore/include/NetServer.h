#ifndef SHARED_NETSELECT_H
#define SHARED_NETSELECT_H

#include "SharedInc.h"
#include "Net.h"

class CServerNet : public CNet
{
public:
	CServerNet();
	~CServerNet();

	void	Break(SOCKET sock);
	bool	ConnectReturn(SOCKET sock, int error=0);

	bool	HandlePacket(PACKET_COMMAND * pCmd);
};

#endif	//SHARED_NETSELECT_H
