#include "server.h"
#include "random.h"
#include "console.h"
#include "exception.h"
#include "LuaEngine.h"
#ifdef __linux__
#include "udsvr.h"
#include "SignalHandler.h"
#endif
#include "MessageTypeDefine.pb.h"
#include "MessageServer.pb.h"

static const char* svrname[CBaseServer::Linker_Server_End] = { "Null", "CentralServer", "DataServer", "WorldServer", "LoginServer", "GameServer", "GateServer", "BIServer", "PaymentServer" };

CBaseServer::CBaseServer()
{
	m_ServerState = EStateRunning;

	SetDefLessFunc(m_linkerMap);
}

CBaseServer::~CBaseServer()
{
}

bool CBaseServer::run(int frame)
{
	if (!onStartup()) {
		return false;
	}

	int sleeptime = frame > 0 ? 1000/frame : 1;

	//DWORD time = 0;
	while (true)
	{
#if !defined(_DEBUG) && defined(WIN32)
		__try
		{
#endif
			if (this->getServerState() == EStateStopping) {
				break;
			}
			else if (this->getServerState() == EStateReloadData) {
				onLoadData();
				this->setServerState(EStateRunning);
			} else if (this->getServerState() == EStateReloadScript) {
				onLoadScript();
				this->setServerState(EStateRunning);
			}

			onLogic();

			/*if (timeGetTime() - time > 1000)
			{
				time = timeGetTime();

				onPrint();
			}*/

#if !defined(_DEBUG) && defined(WIN32)
		}
		__except (HandleException(GetExceptionInformation(), "BaseServers"))
		{
			// We don't actually do anything inside the handler. All of the
			// work is done by HandleException()
		}
#endif

#ifdef _WIN32
		Sleep(sleeptime);
#else
#if defined(__linux__)
		usleep(sleeptime*1000);
#endif
#endif
	}

	onShutdown();

	return true;
}

bool CBaseServer::onStartup()
{
#ifdef _WIN
#ifndef _DEBUG
	//禁用控制台窗口的关闭按钮
	DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_BYCOMMAND);
    DrawMenuBar(GetConsoleWindow());
#endif
	
	ConsoleSetSize(300, 100);

	//设置控制台标题
	SetConsoleTitle(svrname[m_self.m_type]);

	//设置系统时钟间隔1ms
	timeBeginPeriod(1);
#endif

#ifdef __linux__
	startupSigThread();
#endif

	//设置随机种子
	RandomSeed(time(NULL));

	//启动性能监视器
	SetVProfCurrentProfile(new CVProfile);
	VProfCurrentProfile().Start();

	//启动日志系统
#ifdef DEBUG
	Log.Startup(svrname[m_self.m_type], LOG_LEVEL_DEBUG);
#else
	Log.Startup(svrname[m_self.m_type], LOG_LEVEL_DEBUG);
#endif

	//初始化lua引擎
	if (!LuaEngine.Init()) {
		Log.Error("[CBaseServer] init lua engine failed");
		return false;
	}

	return true;
}

bool CBaseServer::onLogic()
{
	VProfCurrentProfile().Pause();
	VProfCurrentProfile().Server_OutputReport();
	VProfCurrentProfile().Resume();
	VProfCurrentProfile().MarkFrame();

	loop_message();
	loop_linkers();

	return true;
}

void CBaseServer::onPrint(char* output)
{
	printf("Connected Servers:\n");

	FOR_EACH_LL(m_linkerList, index)
	{
		CLinker* pObj = m_linkerList[index];
		if (pObj)
		{
			printf("%d %s:%d\n", pObj->m_nID, pObj->m_szIP, pObj->m_nPort);
		}
	}
}

bool CBaseServer::onMessage(PACKET_COMMAND* pack)
{
	if (!pack)
		return false;

	switch (pack->Type())
	{
	case Message::MSG_SERVER_SYNCGATELOAD:	_handlePacket_SyncLoadNumber(pack);	break;
	case Message::MSG_SERVER_NET_CLOSE:		_handlePacket_NetClose(pack);		break;
	case Message::MSG_SERVER_NET_ACCEPT:	_handlePacket_NetAccept(pack);		break;
	case Message::MSG_SERVER_REGISTER:		_handlePacket_RegistServer(pack);	break;
	case Message::MSG_SERVER_SYNCSERVER:	_handlePacket_ConnectServer(pack);	break;
	case Message::MSG_SERVER_NET_CONNECT:	_handlePacket_RegistAsyncReturn(pack); break;
	default:	return false;
	}

	return true;
}

void CBaseServer::onShutdown()
{
	Log.Notice("End ..");;
	Log.Shutdown();

#ifdef __linux__
	sleep(5);
#else
	Sleep(5000);
#endif
}

void CBaseServer::setType(int type)
{
	m_self.m_type = type;
}

void CBaseServer::initSelf(int world, int type, int id, int port, const char* szip, int extport, const char* extip, const char* udPath)
{
	m_self.m_worldID = world;
	m_self.m_type = type;
	m_self.m_nID = id;
	m_self.m_nPort = port;
	strncpy(m_self.m_szIP, szip, 32);
	if( extip ) {
		m_self.m_extPort = extport;
		strncpy(m_self.m_extIP, extip, 32);
	}

#ifdef __linux__
	if( udPath )
		udsvr.StartUp(udPath);
#endif
}

CPlugin* CBaseServer::createPlugin(int plugin)
{
	switch (plugin) {
		case Plugin_Net4Server:	m_plugins[Plugin_Net4Server] = NEW CNetwork; break;
		case Plugin_Net4Client:	m_plugins[Plugin_Net4Client] = NEW CNetwork; break;
		case Plugin_Mongodb:	m_plugins[Plugin_Mongodb] = NEW CMongoDB; break;
		case Plugin_HttpServe:	m_plugins[Plugin_HttpServe] = NEW CHttpServe; break;
		case Plugin_Monitor:	m_plugins[Plugin_Monitor] = NEW CMonitor; break;
		default: return NULL;
	}
	m_plugins[plugin]->setServer(this);

	return m_plugins[plugin];
}

void CBaseServer::sigHandle(int sig)
{
#ifdef __linux__
	if (sig == SIGUSR1) {
		if (getServerState() == EStateRunning)
			setServerState(EStateStopping);
	} else if (sig == SIGUSR2){
		if (getServerState() == EStateRunning)
			setServerState(EStateReloadScript);
	} else if (sig == SIGRTMIN){
		if (getServerState() == EStateRunning)
			setServerState(EStateReloadData);
	}
#endif
}

void CBaseServer::SignalThread(void *param)
{
#ifdef __linux__
	CBaseServer* pthis = (CBaseServer*)param;

	int sig;
	sigset_t waitset;

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
		pthis->sigHandle(sig);
	}
#endif
}

bool CBaseServer::startupSigThread()
{
#ifdef __linux__
	sigset_t bset, oset;

	sigemptyset(&bset);
	sigaddset(&bset, SIGUSR1);
	sigaddset(&bset, SIGUSR2);
	sigaddset(&bset, SIGRTMIN);
	if (pthread_sigmask(SIG_BLOCK, &bset, &oset) != 0)
		Log.Error("Set pthread mask failed");
	ThreadLib::Create(SignalThread, this);
#endif
	return false;
}

CLinker* CBaseServer::createLinker(int type, int id, int port, const char* szip, int extport, const char* extip, int world, bool host, SOCKET sock)
{
	CLinker* linker = NEW CLinker;
	if (!linker)
		return NULL;

	return createLinker(linker, type, id, port, szip, extport, extip, world, host, sock);
}

CLinker* CBaseServer::createLinker(CLinker* linker, int type, int id, int port, const char* szip, int extport, const char* extip, int world, bool host, SOCKET sock)
{
	if (!linker)
		return NULL;

	linker->m_type = type;
	linker->m_nID = id;
	linker->m_nPort = port;
	linker->m_worldID = world;
	linker->m_bHost = host;
	linker->m_Socket = sock;
	strncpy(linker->m_szIP, szip, 32);
	if (extip)
	{
		linker->m_extPort = extport;
		strncpy(linker->m_extIP, extip, 32);
	}

	if (INVALID_SOCKET == linker->m_Socket)
	{
		if (!regist(linker))
		{
			delete linker;
			return NULL;
		}
		addLinker(linker);
	}

	_onAddLinker(linker);

	Log.Notice("[CBaseServer] Create Server %s:%d World:%d ID:%d Sock:%d", linker->m_szIP, linker->m_nPort, linker->m_worldID, linker->m_nID, linker->m_Socket);

	return linker;
}

bool CBaseServer::addLinker(CLinker* linker)
{
	m_linkerList.AddToTail(linker);
	m_linkerMap.Insert(linker->m_Socket, linker);

	return true;
}

void CBaseServer::breakLinker(SOCKET s)
{
	CLinker* pObj = NULL;
	int idx = m_linkerMap.Find(s);
	if (m_linkerMap.IsValidIndex(idx))
	{
		pObj = m_linkerMap.Element(idx);
		m_linkerMap.RemoveAt(idx);
	}

	if (pObj)
	{
		pObj->m_bBreak = true;
		pObj->m_LostTime = timeGetTime();
	}

	Log.Notice("[CBaseServer] Break Linker Sock:%d", s);
}

CLinker* CBaseServer::getLinker(SOCKET s)
{
	return m_linkerMap.GetElement(s);
}

CLinker* CBaseServer::getServer(SOCKET s)
{
	CLinker* linker = m_linkerMap.GetElement(s);
	if (linker && isServer(linker->m_type)) {
		return linker;
	}
	return NULL;
}

CLinker* CBaseServer::getServerById(int id)
{
	CLinker* p = NULL;
	FOR_EACH_LL(m_linkerList, index)
	{
		p = m_linkerList[index];
		if (p && p->m_nID == id)
			break;
	}
	return p;
}

CLinker* CBaseServer::getServerByType(int type)
{
	FOR_EACH_LL(m_linkerList, index)
	{
		CLinker* p = m_linkerList[index];
		if (p && p->m_type == type)
			return p;
	}
	return NULL;
}

SOCKET CBaseServer::getServerSock(int type)
{
	FOR_EACH_LL(m_linkerList, index)
	{
		CLinker* p = m_linkerList[index];
		if (p && p->m_type == type)
			return p->m_Socket;
	}
	return INVALID_SOCKET;
}

bool CBaseServer::loop_message()
{
	VPROF("loop_message");

	int count = 0;
	PACKET_COMMAND* pack = NULL;

	while ((pack = getHeadPacket()) && count++ <= 10000)
	{
		onMessage(pack);

		SAFE_DELETE(pack);
	}

	return true;
}

bool CBaseServer::loop_linkers()
{
	VPROF("loop_linkers");

	int tmp;
	for (int index = m_linkerList.Head(); m_linkerList.IsValidIndex(tmp = index);)
	{
		index = m_linkerList.Next(index);

		CLinker* pObj = m_linkerList[tmp];
		if (!pObj)
		{
			m_linkerList.Remove(tmp);
			continue;
		}

		if (pObj->m_type > 0 && pObj->m_type < Linker_Server_End)
		{
			if (pObj->m_bBreak)
			{
				if (!pObj->m_bHost)
				{
					deleteLinker(pObj);
					m_linkerList.Remove(tmp);
				}
				else if (!pObj->m_bWaiting)
				{
					long curtime = timeGetTime();
					if (curtime - pObj->m_LostTime < 30000)
					{
						registAsync(pObj);
					}
					else
					{
						deleteLinker(pObj);
						m_linkerList.Remove(tmp);
					}
				}
			}
		}
		else
		{
			if (pObj->m_bBreak)
			{
				deleteLinker(pObj);
				m_linkerList.Remove(tmp);
			}
		}
	}

	return true;
}

bool CBaseServer::_handlePacket_NetAccept(PACKET_COMMAND* pack)
{
	if (!pack)
		return false;

	Message::NetControl msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	CLinker* linker = NEW CLinker;
	if (linker) {
		linker->m_Socket = msg.sock();
		linker->m_bBreak = false;
		addLinker(linker);
	}

	return true;
}

bool CBaseServer::_handlePacket_NetClose(PACKET_COMMAND* pack)
{
	if (!pack)
		return false;

	Message::NetControl msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	breakLinker(msg.sock());

	return true;
}

bool CBaseServer::_handlePacket_RegistServer(PACKET_COMMAND* pack)
{
	if (!pack)
		return false;

	Message::RegistServer msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	CLinker* linker = getLinker(pack->GetNetID());
	if (linker) {
		createLinker(linker, msg.type(), msg.id(), msg.port(), msg.ip().c_str(), msg.extport(), msg.extip().c_str(), msg.world(), false, pack->GetNetID());
	}

	return true;
}

bool CBaseServer::_handlePacket_ConnectServer(PACKET_COMMAND* pack)
{
	if (!pack)
		return false;

	Message::SyncServer msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	createLinker(msg.type(), msg.id(), msg.port(), msg.ip().c_str(), msg.extport(), msg.extip().c_str(), msg.world(), true);

	return true;
}

bool CBaseServer::_handlePacket_RegistAsyncReturn(PACKET_COMMAND* pack)
{
	if (!pack)
		return false;

	Message::NetControl msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	registAsyncReturn(msg.sock(), msg.error());

	return true;
}

bool CBaseServer::_handlePacket_SyncLoadNumber(PACKET_COMMAND* pack)
{
	if (!pack)
		return false;

	Message::SyncLoadNumber msg;
	PROTOBUF_CMD_PARSER(pack, msg);

	CLinker* server = getServer(pack->GetNetID());
	if (server) {
		server->m_count += msg.count();
	}

	return true;
}

void CBaseServer::deleteLinker(CLinker* pObj)
{
	Log.Notice("[CBaseServer] Delete Linker %s:%d World:%d ID:%d Sock:%d", pObj->m_szIP, pObj->m_nPort, pObj->m_worldID, pObj->m_nID, pObj->m_Socket);

	delete pObj;
	pObj = NULL;
}

bool CBaseServer::regist(CLinker* pObj)
{
	if (!pObj || !pObj->m_bBreak)
		return false;

	pObj->m_Socket = GETSERVERNET(this)->connect(pObj->m_szIP, pObj->m_nPort);
	if (pObj->m_Socket == INVALID_SOCKET)
	{
		Log.Error("[CBaseServer] Connect Server(%s:%d) Failed", pObj->m_szIP, pObj->m_nPort);
		return false;
	}

	Log.Notice("[CBaseServer] Connect Server(%s:%d) success, socket=%d", pObj->m_szIP, pObj->m_nPort, pObj->m_Socket);

	Message::RegistServer msg;
	msg.set_id(m_self.m_nID);
	msg.set_type(m_self.m_type);
	msg.set_port(m_self.m_nPort);
	msg.set_ip(m_self.m_szIP);
	msg.set_extport(m_self.m_extPort);
	msg.set_extip(m_self.m_extIP);
	msg.set_world(m_self.m_worldID);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_SERVER_REGISTER);
	GETSERVERNET(this)->sendMsg(pObj->m_Socket, &pack);

	pObj->m_bBreak = false;

	return true;
}

bool CBaseServer::registAsync(CLinker* pObj)
{
	if (!pObj || !pObj->m_bBreak)
		return false;

	SOCKET sock = GETSERVERNET(this)->connectAsync(pObj->m_szIP, pObj->m_nPort);
	if (sock == INVALID_SOCKET)
	{
		Log.Error("[CBaseServer] Async Connect Server(%s:%d) Failed", pObj->m_szIP, pObj->m_nPort);
		return FALSE;
	}

	m_linkerMap.Insert(sock, pObj);

	pObj->m_Socket = sock;
	pObj->m_bWaiting = true;

	Log.Notice("[CBaseServer] Async Connecting Server(%s:%d), socket=%d", pObj->m_szIP, pObj->m_nPort, sock);

	return true;
}

bool CBaseServer::registAsyncReturn(SOCKET sock, int error)
{
	CLinker* pObj = m_linkerMap.GetElement(sock);
	if (!pObj || !pObj->m_bBreak)
		return false;

	if (error == 0)
	{
		Message::RegistServer msg;
		msg.set_id(m_self.m_nID);
		msg.set_type(m_self.m_type);
		msg.set_port(m_self.m_nPort);
		msg.set_ip(m_self.m_szIP);
		msg.set_world(m_self.m_worldID);

		PACKET_COMMAND pack;
		PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_SERVER_REGISTER);
		GETSERVERNET(this)->sendMsg(pObj->m_Socket, &pack);

		pObj->m_bBreak = false;
		pObj->m_bWaiting = false;

		Log.Notice("[CBaseServer] Async Connect Server(%s:%d) success, socket=%d", pObj->m_szIP, pObj->m_nPort, pObj->m_Socket);
	}
	else
	{
		m_linkerMap.Remove(sock);

		pObj->m_bWaiting = false;

		Log.Notice("[CBaseServer] Async Connect Server(%s:%d) failed, socket=%d", pObj->m_szIP, pObj->m_nPort, pObj->m_Socket);
	}

	return true;
}

void CBaseServer::syncLoadNumber(int socket, int number)
{
	Message::SyncLoadNumber msg;
	msg.set_server(m_self.m_nID);
	msg.set_count(number);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_SERVER_SYNCGATELOAD);
	GETSERVERNET(this)->sendMsg(socket, &pack);
}
