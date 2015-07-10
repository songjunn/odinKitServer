#include "ServerMgr.h"
#include "Net.h"
#include "MessageRegistServer.pb.h"
#include "MessageSyncServer.pb.h"
#include "MessageSyncGateLoad.pb.h"

#ifdef __linux__
#include "linux_time.h"
#include "PacketDefine.h"
#include "MainServer.h"
#endif

CServerMgr::CServerMgr()
{
	m_DataSock = INVALID_SOCKET;
	m_LoginSock = INVALID_SOCKET;

	SetDefLessFunc(m_SocketMap);
}

CServerMgr::~CServerMgr()
{

}

CServerObj* CServerMgr::CreateServer(int type, int id, int port, const char* szip, int extport, const char* extip, int world, bool host, SOCKET sock)
{
	CServerObj* pObj = NEW CServerObj;
	if( !pObj )
		return NULL;

	pObj->m_type	= type;
	pObj->m_nID		= id;
	pObj->m_nPort	= port;
	pObj->m_worldID = world;
	pObj->m_bHost	= host;
	pObj->m_Socket	= sock;
	strncpy(pObj->m_szIP, szip, 32);
	if( extip )
	{
		pObj->m_extPort	= extport;
		strncpy(pObj->m_extIP, extip, 32);
	}

	if( INVALID_SOCKET == sock && !_Regist(pObj) )
	{
		delete pObj;
		return NULL;
	}

	pObj->m_bBreak = false;

	m_ServerList.AddToTail(pObj);

	m_SocketLock.LOCK();
	m_SocketMap.Insert(pObj->m_Socket, pObj);
	m_SocketLock.UNLOCK();

	switch( pObj->m_type )
	{
	case Svr_Data:	m_DataSock = pObj->m_Socket;	break;
	case Svr_Login:	m_LoginSock = pObj->m_Socket;	break;
	case Svr_DataAnalysis:	m_BISock = pObj->m_Socket;	break;
	case Svr_Payment : m_PaymentSock = pObj->m_Socket;	break;
	default:	break;
	}

	Log.Notice("[ServerMgr] Create Server %s:%d World:%d ID:%d Sock:%d", pObj->m_szIP, pObj->m_nPort, pObj->m_worldID, pObj->m_nID, pObj->m_Socket);

	return pObj;
}

void CServerMgr::BreakServer(SOCKET s)
{
	CServerObj* pObj = NULL;
	m_SocketLock.LOCK();
	int idx = m_SocketMap.Find(s);
	if(m_SocketMap.IsValidIndex(idx))
	{
		pObj = m_SocketMap.Element(idx);
		m_SocketMap.RemoveAt(idx);
	}
	m_SocketLock.UNLOCK();

	if(pObj)
	{
		pObj->m_bBreak = true;
		pObj->m_LostTime = timeGetTime();
	}
}

CServerObj* CServerMgr::GetServer(SOCKET s)
{
	CServerObj* p = NULL;
	m_SocketLock.LOCK();
	p = m_SocketMap.GetElement(s);
	m_SocketLock.UNLOCK();
	return p;
}

CServerObj*	CServerMgr::GetServerById(int id)
{
	CServerObj* p = NULL;
	FOR_EACH_LL( m_ServerList, index )
	{
		p = m_ServerList[index];
		if( p && p->m_nID == id )
			break;
	}
	return p;
}

bool CServerMgr::OnLogic()
{
	VPROF("CServerMgr::OnLogic");

	int tmp;
	for(int index = m_ServerList.Head(); m_ServerList.IsValidIndex(tmp=index); )
    {
		index = m_ServerList.Next(index);

		CServerObj* pObj = m_ServerList[tmp];
		if( !pObj )
		{
			m_ServerList.Remove(tmp);
			continue;
		}

		if( pObj->m_bBreak )
		{
			if( !pObj->m_bHost )
			{
				_DeleteServer(pObj);
				m_ServerList.Remove(tmp);
			}
			else if( !pObj->m_bWaiting )
			{
				long curtime = timeGetTime();
				if( curtime - pObj->m_LostTime < 30000 )
				{
					_RegistAsync(pObj);
				}
				else
				{
					_DeleteServer(pObj);
					m_ServerList.Remove(tmp);
				}
			}
		}
    }

	return true;
}

void CServerMgr::OnPrint()
{
	printf("Connected Servers:\n");
	
	FOR_EACH_LL( m_ServerList, index )
    {
		CServerObj* pObj = m_ServerList[index];
		if( pObj )
		{
			printf("%d %s:%d\n", pObj->m_nID, pObj->m_szIP, pObj->m_nPort);
		}
	}
}

void CServerMgr::Output(char* output)
{
	sprintf(output, "Connected Servers:\n");

	FOR_EACH_LL( m_ServerList, index )
    {
		CServerObj* pObj = m_ServerList[index];
		if( pObj )
		{
			char str[1024] = {0};
			sprintf(str, "  %d %s:%d %d\n", pObj->m_nID, pObj->m_szIP, pObj->m_nPort, pObj->m_Socket);
			strcat(output, str);
		}
	}
}

bool CServerMgr::OnMsg(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	switch(pack->Type())
	{
	case S2C_REQUEST_REGISTER_SERVER:	_HandlePacket_RegistServer(pack);	break;
	case C2S_NOTIFY_SYNC_SERVER:		_HandlePacket_ConnectServer(pack);	break;
	case A2L_NOTIFY_SYNC_GATELOAD:		_HandlePacket_SyncGateLoad(pack);	break;
	default:	return false;
	}

	return true;
}

bool CServerMgr::_HandlePacket_RegistServer(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::RegistServer msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	CreateServer(msg.type(), msg.id(), msg.port(), msg.ip().c_str(), msg.extport(), msg.extip().c_str(), msg.world(), false, pack->GetNetID());

	return true;
}

bool CServerMgr::_HandlePacket_ConnectServer(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::SyncServer msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	CreateServer(msg.type(), msg.id(), msg.port(), msg.ip().c_str(), msg.extport(), msg.extip().c_str(), msg.world(), true);

	return true;
}

bool CServerMgr::_HandlePacket_SyncGateLoad(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::SyncGateLoad msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	_SetGateLoadStatus( pack->GetNetID(), msg.count() );

	return true;
}

void CServerMgr::_DeleteServer(CServerObj* pObj)
{
	Log.Notice("[ServerMgr] Delete Server %s:%d World:%d ID:%d Sock:%d", pObj->m_szIP, pObj->m_nPort, pObj->m_worldID, pObj->m_nID, pObj->m_Socket);

	delete pObj;
	pObj = NULL;
}

void CServerMgr::_SetGateLoadStatus(SOCKET sock, int num)
{
	CServerObj* pServer = GetServer( sock );
	if( pServer )
		pServer->m_UserCount = num;
}

CServerObj* CServerMgr::GetLowerGate(int world)
{
	CServerObj* pLowerGate = NULL;

	FOR_EACH_LL( m_ServerList, index )
	{
		CServerObj* pServer = m_ServerList[index];
		if( !pServer || pServer->m_bBreak || pServer->m_type != Svr_GateWay || pServer->m_worldID != world )
			continue;

		if( !pLowerGate || pLowerGate->m_UserCount > pServer->m_UserCount )
		{
			pLowerGate = pServer;
		}
	}

	if( pLowerGate )
		pLowerGate->m_UserCount++;

	return pLowerGate;
}

CServerObj* CServerMgr::GetLowerGame()
{
	CServerObj* pLowerGame = NULL;

	FOR_EACH_LL( m_ServerList, index )
	{
		CServerObj* pServer = m_ServerList[index];
		if( !pServer || pServer->m_bBreak || pServer->m_type != Svr_Game )
			continue;

		if( !pLowerGame || pLowerGame->m_UserCount > pServer->m_UserCount )
		{
			pLowerGame = pServer;
		}
	}

	if( pLowerGame )
		pLowerGame->m_UserCount++;

	return pLowerGame;
}

bool CServerMgr::_Regist(CServerObj* pObj)
{
	if( !pObj || !pObj->m_bBreak )
		return false;

	pObj->m_Socket = MainServer.Connect(pObj->m_szIP, pObj->m_nPort);
	if( pObj->m_Socket == INVALID_SOCKET )
	{
		Log.Error("[ServerMgr] Connect Server(%s:%d) Failed", pObj->m_szIP, pObj->m_nPort);
		return false;
	}

	Log.Notice("[ServerMgr] Connect Server(%s:%d) success, socket=%d", pObj->m_szIP, pObj->m_nPort, pObj->m_Socket);

	Message::RegistServer msg;
	msg.set_id( MainServer.ID() );
	msg.set_type( MainServer.Type() );
	msg.set_port( MainServer.Port() );
	msg.set_ip( MainServer.IP() );
	msg.set_extport( MainServer.ExtPort() );
	msg.set_extip( MainServer.ExtIP() );
	msg.set_world( MainServer.World());

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE( pack, msg, S2C_REQUEST_REGISTER_SERVER );
	MainServer.SendMsgToServer(pObj->m_Socket, &pack);

	//pObj->m_bBreak = false;`

	return true;
}

bool CServerMgr::_RegistAsync(CServerObj* pObj)
{
	if( !pObj || !pObj->m_bBreak )
		return false;

	SOCKET sock = MainServer.ConnectAsync(pObj->m_szIP, pObj->m_nPort);
	if( sock == INVALID_SOCKET )
	{
		Log.Error("[ServerMgr] Async Connect Server(%s:%d) Failed", pObj->m_szIP, pObj->m_nPort);
		return FALSE;
	}

	m_SocketLock.LOCK();
	m_SocketMap.Insert(sock, pObj) ;
	m_SocketLock.UNLOCK();

	pObj->m_Socket = sock;
	pObj->m_bWaiting = true;

	Log.Notice("[ServerMgr] Async Connecting Server(%s:%d), socket=%d", pObj->m_szIP, pObj->m_nPort, sock);

	return true;
}

bool CServerMgr::RegistAsyncReturn(SOCKET sock, int error)
{
	m_SocketLock.LOCK();
	CServerObj* pObj = m_SocketMap.GetElement(sock);
	m_SocketLock.UNLOCK();

	if( !pObj || !pObj->m_bBreak )
		return false;

	if( error == 0 )
	{
		Message::RegistServer msg;
		msg.set_id( MainServer.ID() );
		msg.set_type( MainServer.Type() );
		msg.set_port( MainServer.Port() );
		msg.set_ip( MainServer.IP() );
		msg.set_world( MainServer.World());

		PACKET_COMMAND pack;
		PROTOBUF_CMD_PACKAGE( pack, msg, S2C_REQUEST_REGISTER_SERVER );
		MainServer.SendMsgToServer(pObj->m_Socket, &pack);

		pObj->m_bBreak = false;
		pObj->m_bWaiting = false;

		Log.Notice("[ServerMgr] Async Connect Server(%s:%d) success, socket=%d", pObj->m_szIP, pObj->m_nPort, pObj->m_Socket);
	}
	else
	{
		m_SocketLock.LOCK();
		m_SocketMap.Remove(sock);
		m_SocketLock.UNLOCK();

		pObj->m_bWaiting = false;

		Log.Notice("[ServerMgr] Async Connect Server(%s:%d) failed, socket=%d", pObj->m_szIP, pObj->m_nPort, pObj->m_Socket);
	}

	return true;
}
