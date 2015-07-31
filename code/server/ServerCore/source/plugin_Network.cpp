#include "plugin_Network.h"
#include "server.h"
#include "memorypool.h"
#include "MessageTypeDefine.pb.h"
#include "MessageServer.pb.h"

extern CObjectMemoryPool<PACKET_COMMAND> g_PacketPool;

CNetwork::CNetwork()
{
}

CNetwork::~CNetwork()
{
}

bool CNetwork::startup(int type, int port, int connectmax, int sendbuffsize, int recvbuffsize, int packsize)
{
	if (!m_server->getPacketQueue().Init(packsize)) {
		return false;
	}

	m_type = type;

	return CNet::startup(type, port, connectmax, sendbuffsize, recvbuffsize, packsize);
}

SOCKET CNetwork::connect(const char * ip, int port)
{
	return CNet::connect(ip, port);
}

SOCKET CNetwork::connectAsync(const char * ip, int port)
{
	return CNet::connectAsync(ip, port);
}

bool CNetwork::shutdown(SOCKET sock)
{
	return CNet::shutdown(sock);
}

int CNetwork::sendMsg(SOCKET sock, PACKET_COMMAND* pack)
{
	if (sock == INVALID_SOCKET || !pack)
		return -1;
	return CNet::send(sock, (char*)pack->Data(), pack->Size());
}

bool CNetwork::accept(SOCKET sock, const char* ip)
{
	_acceptReturn(sock);
	return true;
}

void CNetwork::close(SOCKET sock)
{
	_closeReturn(sock);
	CNet::close(sock);
}

bool CNetwork::handlePacket(PACKET_COMMAND * pCmd)
{
	return m_server->getPacketQueue().Push(pCmd);
}

void CNetwork::_closeReturn(SOCKET sock)
{
	PACKET_COMMAND *pCmd = g_PacketPool.Alloc();
	if (pCmd) {
		Message::NetControl tMsg;
		tMsg.set_sock(sock);
		PROTOBUF_CMD_PACKAGE((*pCmd), tMsg, Message::MSG_SERVER_NET_CLOSE);
		handlePacket(pCmd);
	}
}

void CNetwork::_acceptReturn(SOCKET sock)
{
	PACKET_COMMAND *pCmd = g_PacketPool.Alloc();
	if (pCmd) {
		Message::NetControl tMsg;
		tMsg.set_sock(sock);
		PROTOBUF_CMD_PACKAGE((*pCmd), tMsg, Message::MSG_SERVER_NET_ACCEPT);
		handlePacket(pCmd);
	}
}

void CNetwork::_connectReturn(SOCKET sock, int error)
{
	PACKET_COMMAND *pCmd = g_PacketPool.Alloc();
	if (pCmd) {
		Message::NetControl tMsg;
		tMsg.set_sock(sock);
		tMsg.set_error(error);
		PROTOBUF_CMD_PACKAGE((*pCmd), tMsg, Message::MSG_SERVER_NET_CONNECT);
		handlePacket(pCmd);
	}
}
