#ifndef LOGINSERVER_USERMGR_H
#define LOGINSERVER_USERMGR_H

#include "commdata.h"
#include "Net.h"
#include "ObjMgr.h"
#include "utllinkedlist.h"

#include "HttpServer.h"

#define	 AUTH_VAR_LEN			128
#define  AUTH_USER_ID			"userid"
#define  AUTH_ACCESS_TOKEN		"accesstoken"

#define  AUTO_ACCESS_LEFT		0x0000
#define  AUTO_ACCESS_RIGHT		0xffff

#define	 PLATFORM_PERIOD_MAX	10

enum CLIENT_PLATFORM
{
	CLIENT_PLATFORM_IOS		= 1,
	CLIENT_PLATFORM_ANDROID
};

struct CUser
{
	SOCKET		m_sock;
	int			m_server;
	UserID		m_id;
	TMV			m_HeartTime;
	int			m_client;
	std::string m_ticket;
	std::string m_guid;
	std::string m_accessToken;
	std::string m_refreshToken;
	bool		m_auto;

	CUser()
	{
		_Init();
	}

	~CUser()
	{
		_Init();

		m_ticket.clear();
		m_guid.clear();
		m_accessToken.clear();
		m_refreshToken.clear();
	}

	void _Init()
	{
		m_sock = INVALID_SOCKET;
		m_server = 0;
		m_id = 0;
		m_HeartTime = 0;
		m_client = 0;
		m_auto = false;
	}
};

class CUserMgr : public CObjMgr< CUser, UserID >, public Singleton< CUserMgr >
{
public:
	CUserMgr();
	~CUserMgr();

	bool	OnMsg(PACKET_COMMAND* pack);
	bool	OnGateAuth(struct mg_connection *conn);

	void	UserHeartLogic();

protected:
	bool	_HandlePacket_UserCheck(PACKET_COMMAND* pack);
	bool	_HandlePacket_GateAuth(PACKET_COMMAND* pack);

	bool	checkFromThirdPlatform(CUser *pUser);
	static  void httpCheckUserThread(void *pParam);
	static  string generatePostField(CUser *pUser);
	static  size_t recvBackData(void *buffer, size_t nsize, size_t nmemb, void *userp);
	
	void    sendSWChecker(CUser *pUser);
	void	SendErrorMsg(CUser* user, int errid);

	CUser	*_AddUser(UserID userid);
	CUser	*_GetUser(UserID userid);
	void	_DelUser(UserID userid);

private:
	Mutex	m_UserLock;

	CUtlLinkedList<UserID> m_UncheckedUserList;
};

#define UserMgr CUserMgr::getSingleton()

#endif	//LOGINSERVER_USERMGR_H
