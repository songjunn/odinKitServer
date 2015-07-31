#ifndef GATESERVER_USERMGR_H
#define GATESERVER_USERMGR_H

#include "commdata.h"
#include "Net.h"
#include "Packet.h"
#include "ObjMgr.h"
#include "ClxHlist.h"


struct UserKey
{
	UserID	m_id;
	TMV		m_time;
	int64	m_key;
};

struct CUser
{
	UserID		m_id;
	int			m_server;
	SOCKET		m_ClientSock;
	SOCKET		m_GameSock;
	PersonID	m_LogonPlayer;
	TMV			m_HeartTime;
	bool		m_CanCreate;
	int			m_PackCount;
	TMV			m_PackTime;
};

class CUserMgr : public CObjMgr< CUser, SOCKET >, public Singleton< CUserMgr >
{
public:
	CUserMgr();
	~CUserMgr();

	void	InitConfig(int keytime, int hearttime, int packlimit = 0);

	bool	OnMsg(PACKET_COMMAND* pack);
	bool	OnLogic();

	void	Exit(CUser* user);
	void	Displace(CUser* user);	//顶号
	void	RemoveUser(CUser* user, bool sync = true);
	bool	UserPacketLimit(CUser* user);

	void	SendHeartResponse(CUser* user);
	void	SendErrorMsg(SOCKET sock, int errid);

	inline CUser*	GetUserByUID(UserID uid)
	{
		CUser* user = NULL;
		m_UserLock.LOCK();
		user = m_UserList.Find(uid);
		m_UserLock.UNLOCK();
		return user;
	}

	inline SOCKET	GetNetIDByPID(PersonID pid)
	{
		CUser* user = m_PlayerList.Find(pid);
		if( user )
			return user->m_ClientSock;
		return INVALID_SOCKET;
	}

	inline int GetUserKeyCount() {return m_KeysList.Count();}

protected:
	void	_UserKeyLogic();
	void	_UserHeartLogic();

	bool	_HandlePacket_UserHeart(PACKET_COMMAND* pack);
	bool	_HandlePacket_UserLogin(PACKET_COMMAND* pack);
	bool	_HandlePacket_UserLogout(PACKET_COMMAND* pack);
	bool	_HandlePacket_UserDisplace(PACKET_COMMAND* pack);
	bool	_HandlePacket_UserPreLogin(PACKET_COMMAND* pack);
	bool	_HandlePacket_PlayerLogin(PACKET_COMMAND* pack);
	bool	_HandlePacket_PlayerCreate(PACKET_COMMAND* pack);
	bool	_HandlePacket_PlayerCount(PACKET_COMMAND* pack);
	bool	_HandlePacket_GameError(PACKET_COMMAND* pack);

	void	_CreateUserKey(UserID id, int64 key);
	bool	_CheckUserKey(UserID id, int64 key, SOCKET sock);
	
protected:
	int		m_KeyTimeout;		//连接密钥超时时间
	int		m_HeartTimeout;		//心跳超时时间.
	//int		m_PacketLimit;		//平局每秒的收包限制

	Mutex						m_UserLock;
	CStlMap<UserID, CUser*>		m_UserList;
	CStlMap<PersonID, CUser*>	m_PlayerList;
	ClxHList<UserID, UserKey*>	m_KeysList;

};

#define UserMgr CUserMgr::getSingleton()

#endif	//GATESERVER_USERMGR_H
