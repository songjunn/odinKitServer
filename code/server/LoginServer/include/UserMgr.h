#ifndef LOGINSERVER_USERMGR_H
#define LOGINSERVER_USERMGR_H

#include "commdata.h"
#include "Net.h"
#include "ObjMgr.h"

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
	OpUserID	m_opid;
	GuestID		m_guestid;
	std::string m_device;
	TMV			m_HeartTime;
	std::string m_ticket;
	int			m_client;
	std::string m_guid;
	std::string m_accessToken;
};

class CUserMgr : public CObjMgr< CUser, SOCKET >, public Singleton< CUserMgr >
{
public:
	CUserMgr();
	~CUserMgr();

	bool	OnMsg(PACKET_COMMAND* pack);
	
	void	UserHeartLogic();

	bool	LoadFactId(int worldID);
	void	SetUserTimeout(TMV t);
	static void	SendErrorMsg(CUser* user, int errid);

protected:
	bool	_HandlePacket_UserCheck(PACKET_COMMAND* pack);
	bool	_HandlePacket_GuestCheck(PACKET_COMMAND* pack);
	bool 	_HandlePacket_NetAccept(PACKET_COMMAND* pack);
	bool	_HandlePacket_NetClose(PACKET_COMMAND* pack);

	bool	_CheckSuccess(CUser* pUser);
	void	_Shutdown(CUser* pUser);

	bool	_CheckGuest(CUser* pUser, bool& exit);
	bool	_CreateGuest(CUser* pUser);
	bool	_MakeKeys(int64& key);

	inline GuestID	_MakeGuestID()	{return ++m_GuestIdMax;}

	static void httpCheckUserThread(void *pParam);
	static string generatePostField(CUser *pUser);
	static size_t recvBackData(void *buffer, size_t nsize, size_t nmemb, void *userp);
	void   sendSWChecker(CUser *pUser);

public:
	static char paysrv_addr[32];
	static int	paysrv_port;

private:
	GuestID	m_GuestIdMax;
	TMV		m_HeartTimeout;
	
};

#define UserMgr CUserMgr::getSingleton()

#endif	//LOGINSERVER_USERMGR_H
