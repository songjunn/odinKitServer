#include "LoginNet.h"
#include "MainServer.h"
#include "UserMgr.h"
#include "Log.h"
#include "MessageNetControl.pb.h"
#include "PacketDefine.h"

extern CObjectMemoryPool<PACKET_COMMAND>	g_PacketPool;

bool CLoginNet::Startup(int port, int connectmax, int sendbuffsize, int recvbuffsize, int packsize)
{
#ifdef _WIN
	return CNet::Startup(NET_IO_IOCP, port, connectmax, sendbuffsize, recvbuffsize, packsize);
#else
	return CNet::Startup(NET_IO_EPOLL, port, connectmax, sendbuffsize, recvbuffsize, packsize);
#endif
}

int CLoginNet::SendMsg(SOCKET sock, PACKET_COMMAND* pack)
{
	if( sock == INVALID_SOCKET || !pack )
		return -1;
	return CNet::Send(sock, (char*)pack->Data(), pack->Size());
}

bool CLoginNet::Accept(SOCKET sock, const char* ip)
{
	_ControlAccept(sock);

	return true;
}

void CLoginNet::Break(SOCKET sock)
{
	_ControlClose(sock);
	CNet::Break(sock);
}

bool CLoginNet::HandlePacket(PACKET_COMMAND * pCmd)
{
	return MainServer.AddPacket(pCmd);
}

void CLoginNet::_ControlClose(SOCKET sock)
{
	PACKET_COMMAND *pCmd = g_PacketPool.Alloc();
	if( !pCmd )
	{
		Log.Error("g_PacketPool.Alloc() failed");
		return ;
	}
	Message::NetControl tMsg;
	tMsg.set_sock(sock);
	PROTOBUF_CMD_PACKAGE( (*pCmd), tMsg, N2S_NOTIFY_CONTROL_CLOSE);
	HandlePacket(pCmd);
}
void CLoginNet::_ControlAccept(SOCKET sock)
{
	PACKET_COMMAND *pCmd = g_PacketPool.Alloc();
	if( !pCmd )
	{
		Log.Error("g_PacketPool.Alloc() failed");
		return ;
	}
	Message::NetControl tMsg;
	tMsg.set_sock(sock);
	PROTOBUF_CMD_PACKAGE( (*pCmd), tMsg, N2S_NOTIFY_CONTROL_ACCEPT);
	HandlePacket(pCmd);
}

