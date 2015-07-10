#ifndef SHARED_NET_H
#define SHARED_NET_H

#include "NetHeader.h"
#include "stlmap.h"
#include "Lock.h"
#include "NetObservable.h"


enum NET_IO_TYPE
{
	NET_IO_SELECT = 1,
	NET_IO_IOCP,
	NET_IO_KQUEUE,
	NET_IO_EPOLL,
};

class PACKET_COMMAND;
class CSocketNet;
class CNet: public CNetObservable
{
public:
	CNet();
	~CNet();

	virtual bool	Startup(int type, int port, int connectmax, int sendbuffsize, int recvbuffsize, int packsize);
	virtual void	Terminate();
	virtual bool	Accept(SOCKET sock, const char * ip);
	virtual int		Send(SOCKET sock, char * data, int size);
	virtual bool	Recv(SOCKET sock, char * data, int size);
	virtual void	Break(SOCKET sock);
	virtual bool	Shutdown(SOCKET sock);
	virtual SOCKET	Connect(const char * ip, int port);
	virtual SOCKET	ConnectAsync(const char * ip, int port);
	virtual bool	ConnectReturn(SOCKET sock, int error=0);

	virtual bool	HandlePacket(PACKET_COMMAND * pCmd)		{return true;}
	virtual void	PrintLog();
	void _startMonitor(const char * path, int port);

private:
	PACKET_COMMAND * GetPacketBuff(SOCKET sock);
	PACKET_COMMAND * RemovePacketBuff(SOCKET sock);
	bool InsertPacketBuff(SOCKET sock, PACKET_COMMAND * pCmd);

private:
	Mutex								m_PacketLock;
	CStlMap<SOCKET, PACKET_COMMAND*>	m_PacketList;	//没有解析完整的数据包

public:
	CSocketNet *	m_Net;

};

#endif //SHARED_NET_H
