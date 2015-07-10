#include "Net.h"
#include "Packet.h"
#include "IOSelect.h"
#include "memorypool.h"
#ifdef _WIN
#include "IOCP.h"
#else
#include "IOEpoll.h"
#include "NetMonitor.h"
#include "limits.h"
#endif


extern CObjectMemoryPool<PACKET_COMMAND>	g_PacketPool;


CNet::CNet()
{
}
	
CNet::~CNet()
{
}

bool CNet::Startup(int type, int port, int connectmax, int sendbuffsize, int recvbuffsize, int packsize)
{
	/*if( !g_PacketPool.Init("", packsize) )
		return false;*/

	switch(type)
	{
	case NET_IO_SELECT:
		{
			m_Net = NEW CIOSelect(this);
		}
		break;
#ifdef _WIN
	case NET_IO_IOCP:
		{
			m_Net = NEW CIOCP(this);
		}
		break;
#endif
#ifdef __linux__
	case NET_IO_EPOLL:
		{
			m_Net = NEW CIOEpoll(this);
		}
		break;
#endif
	default:
		return false;
	}
	if( !m_Net || !m_Net->Startup(port, connectmax, sendbuffsize, recvbuffsize) )
		return false;

	_startMonitor("./monitor/", port);

	return true;
}

void CNet::Terminate()
{
	m_Net->Terminate();
}

int CNet::Send(SOCKET sock, char * data, int size)
{
	if( !m_Net )
		return false;

	return m_Net->Send( sock, data, size );
}

bool CNet::Recv(SOCKET sock, char * data, int size)
{
	if( size <= 0 || !data )
	{
		Log.Error("[CNet] Error:%s:%d", __FILE__, __LINE__);
		return false;
	}

	bool bOldPacket = false;
	bool bFinish = false;

	PACKET_COMMAND * pCmd = GetPacketBuff(sock);
	if( pCmd )
		bOldPacket = true;

	int lsize = 0;
	UINT nReadPtr = 0;
	while( (lsize = size - nReadPtr) > 0 )
	{
		if( !pCmd )
		{
			//开始构建一个新的数据包
			pCmd = g_PacketPool.Alloc();
			if( !pCmd )
			{
				Log.Error("[CNet] Error:%s:%d, g_PacketPool.Alloc() failed", __FILE__, __LINE__);
				return false;
			}

			bFinish = false;
		}
		pCmd->SetNetID(sock);

		int wsize = 0;
		if( pCmd->GetHeadLeftSize() > 0 )	//包头未满，把包头写满
		{
			wsize = pCmd->GetHeadLeftSize() < lsize ? pCmd->GetHeadLeftSize() : lsize;
		}
		else if( pCmd->GetLeftSize() > 0 )	//包数据未满，把整个包写满
		{
			wsize = pCmd->GetLeftSize() < lsize ? pCmd->GetLeftSize() : lsize;
		}

		pCmd->Copy(data + nReadPtr, wsize);
		nReadPtr += wsize;
		
		if( pCmd->GetLeftSize() == 0 )		//已摘出一个完整包
		{
			//数据校验
			if( !pCmd->crcCheck() )
			{
				Log.Error("[CNet] crcCheck() sock=%d size=%d lsize=%d nReadPtr=%d failed pCmd=%p bOldPacket=%d, %s", 
						sock, size, lsize, nReadPtr, pCmd, bOldPacket, pCmd->toFormat());
				pCmd->init();
				return false;
			}
			else
			{
				//设置其它参数
				pCmd->SetNetID(sock);

				//存入链表
				HandlePacket(pCmd);
				updateRecvPacket(1);

				//清空缓存
				if( bOldPacket )
				{
					RemovePacketBuff(sock);
					bOldPacket = false;
				}

				pCmd = NULL;
				bFinish = true;
			}
		} 
		else if (pCmd->GetLeftSize() < 0) 
		{
			Log.Error("[CNet] (pCmd->GetLeftSize() < 0 sock=%d pCmd=%p bOldPacket=%d %s",
					sock, pCmd, bOldPacket, pCmd->toFormat());
			pCmd->init();
			return false;
	   }
	}

	//当前数据包没有构建完整，缓存下来，等待下次网络数据
	if( !bFinish )
	{
		InsertPacketBuff( sock, pCmd );
	}
	
	return true;
}

void CNet::Break(SOCKET sock)
{
	PACKET_COMMAND * pCmd = RemovePacketBuff(sock);
	if( pCmd )
		g_PacketPool.Free( pCmd );
}

bool CNet::Shutdown(SOCKET sock)
{
	if( !m_Net )
		return false;

	Break(sock);

	return m_Net->Shutdown(sock);
}

void CNet::PrintLog()
{
	/*int del = timeGetTime() - time;
	if( del )
		Log.Notice("data:%d, time:%d, avg:%d bytes per second", size, del, size/del);*/
}

bool CNet::Accept(SOCKET sock, const char * ip)
{
	return true;
}

SOCKET CNet::Connect(const char * ip, int port)
{
	return m_Net->Connect(ip, port);
}

SOCKET CNet::ConnectAsync(const char * ip, int port)
{
	return m_Net->ConnectAsync(ip, port);
}

bool CNet::ConnectReturn(SOCKET sock, int error)
{
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
PACKET_COMMAND * CNet::GetPacketBuff(SOCKET sock)
{
	PACKET_COMMAND * pCmd = NULL;
	m_PacketLock.LOCK();
	pCmd = m_PacketList.Find(sock);
	m_PacketLock.UNLOCK();
	return pCmd;
}

bool CNet::InsertPacketBuff(SOCKET sock, PACKET_COMMAND * pCmd)
{
	if( sock == INVALID_SOCKET || !pCmd )
		return false;

	bool ret = false;
	m_PacketLock.LOCK();
	ret = m_PacketList.Insert(sock, pCmd);
	updatePacketBuffNum(m_PacketList.Count());
	m_PacketLock.UNLOCK();
	return true;
}

PACKET_COMMAND * CNet::RemovePacketBuff(SOCKET sock)
{
	PACKET_COMMAND * pCmd = NULL;
	m_PacketLock.LOCK();
	pCmd = m_PacketList.Remove(sock);
	updatePacketBuffNum(m_PacketList.Count());
	m_PacketLock.UNLOCK();
	return pCmd;
}

void CNet::_startMonitor(const char * path, int port)
{
#ifdef __linux__
	CNetMonitorTData *pMonitor = new CNetMonitorTData();
	char sock_path[PATH_MAX] = {0};

	sprintf(sock_path, "%s/Net_%d.sock", path, port);
	pMonitor->init(sock_path);
	regist(&(pMonitor->monitor));

	ThreadLib::Create(NetMonitorThread, pMonitor);
#endif

}
