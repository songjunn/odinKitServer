#include "NetClient.h"
#include "MainServer.h"
#include "ServerMgr.h"


CClientNet::CClientNet()
{
}

CClientNet::~CClientNet()
{
}

bool CClientNet::HandlePacket(PACKET_COMMAND * pCmd)
{
	return MainServer.AddPacket(pCmd);
}
