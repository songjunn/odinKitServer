#include "MainServer.h"
#include "random.h"
#include "console.h"
#include "LuaEngine.h"
#include "ServerMgr.h"
#include "NetClient.h"
#ifdef __linux__
#include "udsvr.h"
#include "SignalHandler.h"
#include "mongo_interface.h"
#endif

void SignalThread(void *param)
{
#ifdef __linux__
	int sig;
	sigset_t waitset, oldset;

	sigemptyset(&waitset);
	sigaddset(&waitset, SIGUSR1);
	sigaddset(&waitset, SIGUSR2);
	sigaddset(&waitset, SIGRTMIN);

	while (true) {
		int ret = sigwait(&waitset, &sig);
		if (ret < 0) {
			Log.Error("sigwait() failed errno=%d", errno);
			continue;
		}
		Log.Notice("receive signal %d", sig);
		MainServer.sigHandle(sig);
	}
#endif
}

bool CMainServer::StartupSigThread()
{
#ifdef __linux__
	sigset_t bset, oset;

    sigemptyset(&bset);
    sigaddset(&bset, SIGUSR1);
    sigaddset(&bset, SIGUSR2);
    sigaddset(&bset, SIGRTMIN);
    if (pthread_sigmask(SIG_BLOCK, &bset, &oset) != 0)
    	Log.Error("Set pthread mask failed");
	ThreadLib::Create( SignalThread, this );
#endif
	return false;
}

CMainServer::CMainServer()
{
	m_pServerNet = NULL;
	m_pClientNet = NULL;
	m_mongoClient = NULL;
	//m_mysqlClient = NULL;
	m_ServerState = EStateRunning;
}

CMainServer::~CMainServer()
{
  SAFE_DELETE(m_pServerNet);
  SAFE_DELETE(m_pClientNet);
  SAFE_DELETE(m_mongoClient);
  //SAFE_DELETE(m_mysqlClient);
}

bool CMainServer::Startup(const char* title)
{
#ifdef _WIN
#ifndef _DEBUG
	//禁用控制台窗口的关闭按钮
	DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_BYCOMMAND);
    DrawMenuBar(GetConsoleWindow());
#endif
	
	ConsoleSetSize(300, 100);

	//设置控制台标题
	SetConsoleTitle(title);

	//设置系统时钟间隔1ms
	timeBeginPeriod(1);
#endif

#ifdef __linux__
	//unsigRegister();
	StartupSigThread();
#endif

	//设置随机种子
	RandomSeed(time(NULL));

	//启动性能监视器
	SetVProfCurrentProfile(new CVProfile);
	VProfCurrentProfile().Start();

	//启动日志系统
#ifdef DEBUG
	Log.Startup(title, LOG_LEVEL_DEBUG);
#else
	Log.Startup(title, LOG_LEVEL_DEBUG);
#endif

	//初始化lua引擎
	if( !LuaEngine.Init() )
	{
		Log.Error("初始化lua引擎失败！");
		return false;
	}

	return true;
}

void CMainServer::Init(int world, int type, int id, int port, const char* szip, int extport, const char* extip, const char* udPath)
{
	m_worldID = world;
	m_type = type;
	m_nID = id;
	m_nPort = port;
	strncpy(m_szIP, szip, 32);
	if( extip )
	{
		m_extPort = extport;
		strncpy(m_extIP, extip, 32);
	}

#ifdef __linux__
	if( udPath )
		udsvr.StartUp(udPath);
#endif
}

void CMainServer::MsgLogic()
{
	PACKET_COMMAND* pack = NULL;
	while( pack = GetHeadPacket() )
	{
		ServerMgr.OnMsg(pack);
	}
}

PACKET_COMMAND*	 CMainServer::GetHeadPacket()
{
	VPROF("GetHeadPacket");

	return m_PacketList.Pop();
}

/*bool CMainServer::StartupMysqlDBClient(const char* dbname, const char* dbip, const char* usr, const char* pwd, bool updataProcess, bool selectProcess, int objcnt)
{
	if( m_mysqlClient )
		return false;
  
	m_mysqlClient = NEW CDBCache;
	if( !m_mysqlClient )
		return false;

	return m_mysqlClient->ConnectDB(dbname, dbip, usr, pwd, updataProcess, selectProcess, objcnt);
}

void CMainServer::ShutdownMysqlDBClient()
{

}*/

bool CMainServer::StartupMongoDBClient(std::string host, std::string port, std::string dbname)
{
#ifdef __linux__
	if( m_mongoClient )
		return false;
  
	m_mongoClient = NEW CMongoClient;
	if( !m_mongoClient )
		return false;

	if( !m_mongoClient->Connect(host, port, dbname) )
    {
		SAFE_DELETE(m_mongoClient);
		return false;
	}
#endif
	return true;
}

void CMainServer::ShutdownMongoDBClient()
{
#ifdef __linux__
	if( m_mongoClient )
		m_mongoClient->Shutdown();
#endif
}

bool CMainServer::StartupServerNet(/*int port,*/ int connectmax, int sendbuffsize, int recvbuffsize, int packsize)
{
	if( m_pServerNet )
		return false;

	m_pServerNet = NEW CServerNet;
	if( !m_pServerNet )
		return false;

	if( !m_pServerNet->Startup(NET_IO_SELECT, m_nPort, connectmax, sendbuffsize, recvbuffsize, packsize) )
	{
		SAFE_DELETE(m_pServerNet);
		return false;
	}

	return true;
}

bool CMainServer::StartupClientNet(int port, int connectmax, int sendbuffsize, int recvbuffsize, int packsize)
{
	if( m_pClientNet )
		return false;

	m_pClientNet = NEW CClientNet;
	if( !m_pClientNet )
		return false;

#ifdef _WIN
	if( !m_pClientNet->Startup(NET_IO_IOCP, port, connectmax, sendbuffsize, recvbuffsize, packsize) )
#else
	if( !m_pClientNet->Startup(NET_IO_EPOLL, port, connectmax, sendbuffsize, recvbuffsize, packsize) )
#endif
	{
		SAFE_DELETE(m_pClientNet);
		return false;
	}

	return true;
}

SOCKET CMainServer::Connect(const char * ip, int port)
{
	if( m_pServerNet )
		return m_pServerNet->Connect(ip, port);
	return INVALID_SOCKET;
}

SOCKET CMainServer::ConnectAsync(const char * ip, int port)
{
	if( m_pServerNet )
		return m_pServerNet->ConnectAsync(ip, port);
	return INVALID_SOCKET;
}

bool CMainServer::ShutdownServer(SOCKET sock)
{
	if( m_pServerNet )
		return m_pServerNet->Shutdown(sock);
	return false;
}

bool CMainServer::ShutdownClient(SOCKET sock)
{
	if( m_pClientNet )
		return m_pClientNet->Shutdown(sock);
	return false;
}

void CMainServer::ShutdownNet()
{
	if (m_pClientNet)
		m_pClientNet->Terminate();
	if (m_pServerNet)
		m_pServerNet->Terminate();
}

int	CMainServer::SendMsgToServer(SOCKET s, PACKET_COMMAND* pack)
{
	if( m_pServerNet )
		return m_pServerNet->Send(s, (char*)pack->Data(), pack->Size());
	return 0;
}

int	CMainServer::SendMsgToServer(SOCKET s, char* buf, int size)
{
	if( m_pServerNet )
		return m_pServerNet->Send(s, buf, size);
	return 0;
}

int	CMainServer::SendMsgToClient(SOCKET s, PACKET_COMMAND* pack)
{
	if( m_pClientNet )
		return m_pClientNet->Send(s, (char*)pack->Data(), pack->Size());
	return 0;
}

int	CMainServer::SendMsgToClient(SOCKET s, char* buf, int size)
{
	if( m_pClientNet )
		return m_pClientNet->Send(s, buf, size);
	return 0;
}

void CMainServer::SetPacketSize(int size)
{
	m_PacketList.Init(size);
}

bool CMainServer::AddPacket(PACKET_COMMAND * pack)
{
	return m_PacketList.Push(pack);
}

void CMainServer::FreePacket(PACKET_COMMAND * pack)
{
	
}
void CMainServer::sigHandle(int sig)
{
#ifdef __linux__
	if (sig == SIGUSR1) {
		if (MainServer.getServerState() == EStateRunning)
			MainServer.setServerState(EStateStopping);
	} else if (sig == SIGUSR2){
		if (MainServer.getServerState() == EStateRunning)
			MainServer.setServerState(EStateReloadScript);
	} else if (sig == SIGRTMIN){
		if (MainServer.getServerState() == EStateRunning)
			MainServer.setServerState(EStateReloadData);
	}
#endif
}

