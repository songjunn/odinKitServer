#ifndef _PLUGIN_SERVERMGR_H_
#define _PLUGIN_SERVERMGR_H_

#include "plugin.h"
#include "Lock.h"
#include "linux_type.h"
#include "Packet.h"
#include "utlmap.h"
#include "utllinkedlist.h"

struct CServerObj
{
	SOCKET	m_Socket;
	bool	m_bBreak;
	bool	m_bWaiting;
	int		m_type;
	int		m_nID;
	char	m_szIP[32];
	int		m_nPort;
	bool	m_bHost;
	long	m_LostTime;
	int		m_UserCount;
	char	m_extIP[32];
	int		m_extPort;
	int		m_worldID;

	CServerObj()
	{
		m_Socket = INVALID_SOCKET;
		m_bBreak = true;
		m_bWaiting = false;
		m_type = -1;
		m_nID = -1;
		m_szIP[0] = '\0';
		m_nPort = -1;
		m_bHost = false;
		m_LostTime = -1;
		m_UserCount = 0;
		m_extIP[0] = '\0';
		m_extPort = -1;
		m_worldID = -1;
	}
};

class CServerMgr : public CPlugin
{
public:
	enum ServerType {
		Svr_Central = 1,	//中央服务器
		Svr_Data,			//数据服务器
		Svr_World,			//世界服务器
		Svr_Login,			//登陆服务器
		Svr_Game,			//逻辑服务器
		Svr_GateWay,		//网关服务器
		Svr_DataAnalysis,	//数据分析服务器
		Svr_Payment,
	};

public:
	CServerMgr();
	~CServerMgr();

	virtual bool	OnMsg(PACKET_COMMAND* pack);
	virtual bool	OnLogic();
	virtual void	OnPrint();
	virtual void	Output(char* output);

	bool	startup(int type, int id, int port, const char* szip, int extport, const char* extip, int world);

	virtual CServerObj*	CreateServer(int type, int id, int port, const char* szip, int extport, const char* extip, int world, bool host, SOCKET sock=INVALID_SOCKET);
	void	BreakServer(SOCKET s);
	void	Living(CServerObj* pObj);

	CServerObj*	GetServer(SOCKET s);
	CServerObj*	GetServerById(int id);
	CServerObj*	GetLowerGate(int world);
	CServerObj*	GetLowerGame();

	inline SOCKET getDataSock() {return m_DataSock;}
	inline SOCKET getLoginSock() {return m_LoginSock;}
	inline SOCKET getBISock() {return m_BISock;}
	inline SOCKET getPaymentSock() {return m_PaymentSock;}

protected:
	bool	_Regist(CServerObj* pObj);
	bool	_RegistAsync(CServerObj* pObj);
	bool	_RegistAsyncReturn(SOCKET sock, int error = 0);
	void	_DeleteServer(CServerObj* pObj);

	void	_SetGateLoadStatus(SOCKET sock, int num);

	virtual bool	_HandlePacket_RegistServer(PACKET_COMMAND* pack);
	virtual bool	_HandlePacket_ConnectServer(PACKET_COMMAND* pack);
	virtual bool	_HandlePacket_SyncGateLoad(PACKET_COMMAND* pack);
	virtual bool    _HandlePacket_RegistAsyncReturn(PACKET_COMMAND* pack);

protected:
	SOCKET	m_DataSock;
	SOCKET	m_LoginSock;
	SOCKET	m_BISock;
	SOCKET	m_PaymentSock;

	Mutex	m_SocketLock;

	CUtlMap<SOCKET, CServerObj*>	m_SocketMap;
	CUtlLinkedList<CServerObj*>		m_ServerList;

};

#endif	//_PLUGIN_SERVERMGR_H_
