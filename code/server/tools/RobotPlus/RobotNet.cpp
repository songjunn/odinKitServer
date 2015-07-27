#include "RobotNet.h"
#include "Packet.h"


bool CRobotNet::shutdown(SOCKET sock)
{
	return CNet::shutdown(sock);
}

int CRobotNet::sendMsg(int64 uid, SOCKET s, PACKET_COMMAND* pack)
{
	pack->SetTrans(uid);

	return CNet::send(s, (char*)pack->Data(), pack->Size());
}

bool CRobotNet::handlePacket(PACKET_COMMAND * pack)
{
	m_PackLock.LOCK();
	m_PacketList.AddToTail(pack);
	m_PackLock.UNLOCK();

	return true;
}

PACKET_COMMAND*	 CRobotNet::getHeadPacket()
{
	PACKET_COMMAND* pack = NULL;
	m_PackLock.LOCK();
	if( m_PacketList.Count() > 0 )
	{
		pack = m_PacketList.Head();
		m_PacketList.RemoveFromHead();
	}
	m_PackLock.UNLOCK();
	return pack;
}
