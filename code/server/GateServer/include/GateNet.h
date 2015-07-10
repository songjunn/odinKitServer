#pragma once
#include "SharedInc.h"
#include "Net.h"


class CGateNet : public CNet, public Singleton< CGateNet >
{
public:
	CGateNet()	{};
	~CGateNet()	{};

	virtual bool	Startup(int port, int connectmax, int sendbuffsize, int recvbuffsize, int packsize);
	virtual int		SendMsg(SOCKET sock, PACKET_COMMAND* pack);
	virtual bool	Accept(SOCKET sock, const char* ip);
	virtual void	Break(SOCKET sock);
	virtual bool	HandlePacket(PACKET_COMMAND * pCmd);
private:
	void _ControlClose(SOCKET sock);
	void _ControlAccept(SOCKET sock);
};

#define GateNet CGateNet::getSingleton()
