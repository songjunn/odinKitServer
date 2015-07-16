#ifndef SERVERCORE_MAINSERVER_H
#define SERVERCORE_MAINSERVER_H

#include "Singleton.h"
#include "linux_type.h"
#include "Packet.h"
#include "NetServer.h"
#include "DBCache.h"
#include "utldoublequeue.h"
#include "plugin_Mongodb.h"
#include "plugin_HttpServe.h"


enum EServerState
{
	EStateRunning = 0,
	EStateStopping ,
	EStateLoading,
	EStateReloadScript,
	EStateReloadData
};

#define GETMONGODB	((CMongoDB *)MainServer.getPlugin(CMainServer::Plugin_Mongodb))

struct CServerObj;
class CPlugin;
class CMainServer : public Singleton< CMainServer >
{
public:
	//插件种类
	enum Plugin_Type {
		Plugin_NetUV = 0,
		Plugin_Mongodb,
		Plugin_HttpServe,

		Plugin_End,
	};

public:
	CMainServer();
	~CMainServer();

	bool	Startup(const char* title);
	void	Init(int world, int type, int id, int port, const char* szip, int extport=0, const char* extip=NULL, const char* udPath = NULL);

	CPlugin* createPlugin(int plugin);
	CPlugin* getPlugin(int plugin) { return m_plugins[plugin]; }

	bool	StartupServerNet(/*int port,*/ int connectmax, int sendbuffsize, int recvbuffsize, int packsize);
	bool	StartupClientNet(int port, int connectmax, int sendbuffsize, int recvbuffsize, int packsize);

	bool	StartupSigThread();

	void	MsgLogic();

	SOCKET	Connect(const char * ip, int port);
	SOCKET	ConnectAsync(const char * ip, int port);

	bool	ShutdownServer(SOCKET sock);
	bool	ShutdownClient(SOCKET sock);
	void	ShutdownNet();

	//通过select模型发送数据
	int		SendMsgToServer(SOCKET s, PACKET_COMMAND* pack);
	int		SendMsgToServer(SOCKET s, char* buf, int size);

	////通过iocp网络模型发送数据
	int		SendMsgToClient(SOCKET s, PACKET_COMMAND* pack);
	int		SendMsgToClient(SOCKET s, char* buf, int size);

	void	SetPacketSize(int size);
	bool	AddPacket(PACKET_COMMAND * pack);
	void	FreePacket(PACKET_COMMAND * pack);
	PACKET_COMMAND*		GetHeadPacket();

	inline	int	Type()	{return m_type;}
	inline	int	ID()	{return m_nID;}
	inline	int	Port()	{return m_nPort;}
	inline	char* IP()	{return m_szIP;}
	inline	int	ExtPort()	{return m_extPort;}
	inline	char* ExtIP()	{return m_extIP;}
	inline	int	World()	{return m_worldID;}

	void setServerState(EServerState state) { m_ServerState = state;}
	EServerState getServerState() { return m_ServerState; }
	void sigHandle(int sig);

private:
	int		m_type;
	int		m_nID;
	char	m_szIP[32];
	int		m_nPort;
	char	m_extIP[32];
	int		m_extPort;
	int		m_worldID;

	EServerState m_ServerState;

	CNet*	m_pServerNet;
	CNet*	m_pClientNet;

	CPlugin* m_plugins[Plugin_End];

	CDoubleQueue<PACKET_COMMAND> m_PacketList;
};

#define MainServer CMainServer::getSingleton()

#endif	//SERVERCORE_MAINSERVER_H
