#pragma once

#include "shared.h"
#include "Net.h"
#include "stllist.h"


class CRobotNet : public CNet, public Singleton< CRobotNet >
{
public:
	CRobotNet()		{};
	~CRobotNet()	{};

	bool shutdown(SOCKET sock);
	int	 sendMsg(int64 uid, SOCKET s, PACKET_COMMAND* pack);

	bool handlePacket(PACKET_COMMAND * pCmd);
	PACKET_COMMAND*	getHeadPacket();

private:
	Mutex						m_PackLock;
	CStlList<PACKET_COMMAND*>	m_PacketList;

};

#define RobotNet CRobotNet::getSingleton()
