#ifndef SERVERCORE_MAINSERVER_H
#define SERVERCORE_MAINSERVER_H

#include "Singleton.h"
#include "linux_type.h"
#include "Packet.h"
#include "plugin_Mongodb.h"
#include "plugin_HttpServe.h"
#include "plugin_ServerMgr.h"
#include "plugin_Network.h"


enum EServerState
{
	EStateRunning = 0,
	EStateStopping ,
	EStateLoading,
	EStateReloadScript,
	EStateReloadData
};

#define GETSERVERMGR	((CServerMgr *)MainServer.getPlugin(CMainServer::Plugin_ServerMgr))
#define GETSERVERNET	((CNetwork *)MainServer.getPlugin(CMainServer::Plugin_Net4Server))
#define GETCLIENTNET	((CNetwork *)MainServer.getPlugin(CMainServer::Plugin_Net4Client))
#define GETMONGODB		((CMongoDB *)MainServer.getPlugin(CMainServer::Plugin_Mongodb))

class CPlugin;
class CMainServer : public Singleton< CMainServer >
{
public:
	//≤Âº˛÷÷¿‡
	enum Plugin_Type {
		Plugin_ServerMgr = 0,
		Plugin_Net4Server,
		Plugin_Net4Client,
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

	bool	StartupSigThread();

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
	CPlugin* m_plugins[Plugin_End];

};

#define MainServer CMainServer::getSingleton()

#endif	//SERVERCORE_MAINSERVER_H
