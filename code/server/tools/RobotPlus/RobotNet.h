#pragma once

#include "shared.h"
#include "Net.h"
#include "stllist.h"


class CRobotNet : public CNet, public Singleton< CRobotNet >
{
public:
	CRobotNet()		{};
	~CRobotNet()	{};

	void Break(SOCKET sock);
	int	 SendMsg(int64 uid, SOCKET s, PACKET_COMMAND* pack);

	bool HandlePacket(PACKET_COMMAND * pCmd);
	PACKET_COMMAND*	GetHeadPacket();

private:
	Mutex						m_PackLock;
	CStlList<PACKET_COMMAND*>	m_PacketList;

};

#define RobotNet CRobotNet::getSingleton()
