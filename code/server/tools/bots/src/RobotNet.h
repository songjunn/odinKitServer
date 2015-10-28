#pragma once

#include "shared.h"
#include "Net.h"
#include "stllist.h"

class CRobotObj;
class CRobotNet : public CNet, public Singleton< CRobotNet >
{
public:
	CRobotNet()		{};
	~CRobotNet()	{};

	bool shutdown(SOCKET sock);
	int	 sendMsg(int64 uid, SOCKET s, PACKET_COMMAND* pack);
	bool sendHttpRequest(CRobotObj *robot);
	static size_t recvHttpResponse(void *buffer, size_t nsize, size_t nmemb, void *userp);

	bool handlePacket(PACKET_COMMAND * pCmd);
	PACKET_COMMAND*	getHeadPacket();

private:
	Mutex						m_PackLock;
	CStlList<PACKET_COMMAND*>	m_PacketList;

};

#define RobotNet CRobotNet::getSingleton()
