#include "NetServer.h"
#include "MainServer.h"
#include "ServerMgr.h"


CServerNet::CServerNet()
{
}

CServerNet::~CServerNet()
{
}

void CServerNet::Break(SOCKET sock)
{
	CNet::Break(sock);

	ServerMgr.BreakServer(sock);
}

bool CServerNet::ConnectReturn(SOCKET sock, int error)
{
	return ServerMgr.RegistAsyncReturn(sock, error);
}

bool CServerNet::HandlePacket(PACKET_COMMAND * pCmd)
{
	return MainServer.AddPacket(pCmd);
}
