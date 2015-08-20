#pragma once
#include "shared.h"
#include "Net.h"
#include "commdata.h"
#include "utlmap.h"

class CPlayer;
class CLoginModule : public Singleton< CLoginModule >
{
public:
	CLoginModule();
	~CLoginModule();

	bool	OnMsg(PACKET_COMMAND* pack);

	void	eventPlayerLoadover(PersonID id);

	bool	OnPlayerLogin(CPlayer* player);
	bool	OnPlayerLogout(PersonID id);

protected:
	bool	_HandlePacket_UserLogin(PACKET_COMMAND* pack);
	bool	_HandlePacket_PlayerLogout(PACKET_COMMAND* pack);
	bool	_HandlePacket_PlayerCount(PACKET_COMMAND* pack);
	bool	_HandlePacket_PlayerCreate(PACKET_COMMAND* pack);
	bool	_HandlePacket_PlayerOnCreate(PACKET_COMMAND* pack);
	bool	_HandlePacket_LoadWorldData(PACKET_COMMAND* pack);

	bool	_OnPlayerSync(CPlayer* player);

protected:
	CUtlMap<PersonID, PersonID>		m_LoginMap;

};

#define LoginModule CLoginModule::getSingleton()
