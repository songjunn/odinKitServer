#ifndef _SERVER_H
#define _SERVER_H

#include "linux_type.h"
#include "utlmap.h"
#include "utllinkedlist.h"
#include "Packet.h"
#include "plugin_Mongodb.h"
#include "plugin_HttpServe.h"
#include "plugin_Network.h"

enum EServerState
{
	EStateRunning = 0,
	EStateStopping ,
	EStateLoading,
	EStateReloadScript,
	EStateReloadData
};

#define GETSERVERNET(Server)	((CNetwork *)(Server)->getPlugin(CBaseServer::Plugin_Net4Server))
#define GETCLIENTNET(Server)	((CNetwork *)(Server)->getPlugin(CBaseServer::Plugin_Net4Client))
#define GETMONGODB(Server)		((CMongoDB *)(Server)->getPlugin(CBaseServer::Plugin_Mongodb))
#define GETHTTPSERVE(Server)	((CHttpServe *)(Server)->getPlugin(CBaseServer::Plugin_HttpServe))

struct CLinker {
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

	CLinker() {
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

class CPlugin;
class CBaseServer
{
public:
	//连接类型
	enum LinkerType {
		Linker_Server_Central = 1,	//中央服务器
		Linker_Server_Data,			//数据服务器
		Linker_Server_World,		//世界服务器
		Linker_Server_Login,		//登陆服务器
		Linker_Server_Game,			//逻辑服务器
		Linker_Server_GateWay,		//网关服务器
		Linker_Server_DataAnalysis,	//数据分析服务器
		Linker_Server_Payment,
		Linker_Server_End,
		Linker_User,				//玩家
	};

	//插件种类
	enum Plugin_Type {
		Plugin_Net4Server = 0,
		Plugin_Net4Client,
		Plugin_Mongodb,
		Plugin_HttpServe,

		Plugin_End,
	};

public:
	CBaseServer(int type);
	virtual ~CBaseServer();

	bool startup();
	bool run();

	void initSelf(int world, int type, int id, int port, const char* szip, int extport = 0, const char* extip = NULL, const char* udPath = NULL);
	CLinker* createLinker(int type, int id, int port, const char* szip, int extport, const char* extip, int world, bool host, SOCKET sock = INVALID_SOCKET);

	CPlugin* createPlugin(int plugin);
	CPlugin* getPlugin(int plugin) { return m_plugins[plugin]; }

	virtual bool onInit() { return true; }
	virtual bool onMessage(PACKET_COMMAND* pack);
	virtual bool onLogic();
	virtual void onPrint();
	virtual void onShutdown();

	CLinker* getLinker(SOCKET s);
	CLinker* getServerById(int id);
	CLinker* getLowerGate(int world);
	CLinker* getLowerGame();
	SOCKET getServerSock(int type);

protected:
	void setServerState(EServerState state) { m_ServerState = state;}
	EServerState getServerState() { return m_ServerState; }
	void sigHandle(int sig);
	bool startupSigThread();
	static void SignalThread(void *param);

	bool addLinker(CLinker* linker);
	bool connectLinker(CLinker* linker);
	void breakLinker(SOCKET s);
	bool loop_linkers();

	bool regist(CLinker* pObj);
	bool registAsync(CLinker* pObj);
	bool registAsyncReturn(SOCKET sock, int error = 0);
	void deleteServer(CLinker* pObj);

	void setGateLoadStatus(SOCKET sock, int num);

	virtual bool _HandlePacket_NetAccept(PACKET_COMMAND* pack);
	virtual bool _HandlePacket_NetClose(PACKET_COMMAND* pack);
	virtual bool _HandlePacket_RegistServer(PACKET_COMMAND* pack);
	virtual bool _HandlePacket_ConnectServer(PACKET_COMMAND* pack);
	virtual bool _HandlePacket_SyncGateLoad(PACKET_COMMAND* pack);
	virtual bool _HandlePacket_RegistAsyncReturn(PACKET_COMMAND* pack);

private:
	CLinker m_self;
	EServerState m_ServerState;
	CPlugin* m_plugins[Plugin_End];

	Mutex m_linkerLock;
	CUtlMap<SOCKET, CLinker*> m_linkerMap;
	CUtlLinkedList<CLinker*> m_linkerList;

};

#endif	//_SERVER_H
