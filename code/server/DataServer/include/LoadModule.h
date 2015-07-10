#ifndef _LOADMODULE_H_
#define _LOADMODULE_H_

#include "platform.h"
#include "Singleton.h"
#include "utllinkedlist.h"


struct CLoadObj
{
	int64 id;
	std::string key;
	std::string type;
	int sock;
};

class PACKET_COMMAND;
class CLoadModule : public Singleton< CLoadModule >
{
public:
	CLoadModule()	{}
	~CLoadModule()	{}

	bool	onMessage(PACKET_COMMAND* pack);
	void	onLogic();

protected:
	bool	_handlePacket_LoadWorldData(PACKET_COMMAND* pack);
	bool	_handlePacket_LoadPlayerCount(PACKET_COMMAND* pack);
	bool	_handlePakcet_LoadObjData(PACKET_COMMAND* pack);
	bool	_handlePacket_CheckNameRepeat(PACKET_COMMAND* pack);

protected:
	CUtlLinkedList<CLoadObj*> m_LoadList;

};

#define LoadModule CLoadModule::getSingleton()

#endif	//_LOADMODULE_H_
