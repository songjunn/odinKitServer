#pragma once
#include <string>
#include <string.h>
#include "commdata.h"

class CEvent;
class CPlayer;
class PACKET_COMMAND;
class IBaseObj
{
public:
	IBaseObj() : m_ObjID(0), m_type(0), m_templateId(0) {}
	virtual ~IBaseObj() {}

	virtual void Init();
	virtual void Copy(const IBaseObj& obj);
	virtual	void OnEvent(CEvent* ev)	{ return; }

	int		GetFieldInt(int i);
	int64	GetFieldI64(int i);

	void	SetFieldInt(int i, int value, bool client = false, bool data = false);
	void	SetFieldI64(int i, int64 value, bool client = false, bool data = false);

	void	ChangeFieldInt(int i, int value, bool client = false, bool data = false);
	void	ChangeFieldI64(int i, int64 value, bool client = false, bool data = false);

	inline	int		GetTemplateID()			{return m_templateId;}
	inline  void	SetTemplateID(int id)	{m_templateId = id;}

	inline	int64	GetID()					{return m_ObjID;}
	inline  void	SetID(int64 id)			{m_ObjID = id;}

	inline	char*	GetName()					{ return m_name; }
	inline	void	SetName(const char* value)	{ strncpy(m_name, value, OBJ_NAME_LEN); }

	inline	bool	IsPlayer()	{ return m_type == Role_Type_Player; }
	inline	bool	IsHero()	{ return m_type == Role_Type_Hero; }
	inline	bool	IsMonster()	{ return m_type == Role_Type_Monster; }

	virtual void	SendClientMsg(PACKET_COMMAND* pack)	{return;}
	virtual	void	SendDataMsg(PACKET_COMMAND* pack)	{return;}
	virtual	void	SendObserveMsg(PACKET_COMMAND* pack, CPlayer* player)	{return;}

	virtual void	Serialize(std::string& jsonstr) { return; }
	virtual void	Deserialize(std::string jsonstr) { return; }

	virtual std::string GetFieldName(int i)		{ return ""; }
	virtual void	SyncFieldIntToData(int i)	{ return; }
	virtual void	SyncFieldI64ToData(int i)	{ return; }
	virtual void	SyncFieldIntToClient(int i, CPlayer* toPlayer = NULL)	{return;}
	virtual void	SyncFieldI64ToClient(int i, CPlayer* toPlayer = NULL)	{return;}

protected:
	virtual int*	_FindFieldInt(int i)	{return NULL;}
	virtual int64*	_FindFieldI64(int i)	{return NULL;}
	virtual void	_ChangeRelatedField(int i, bool client = false, bool data = false)	{ return; }

protected:
	int64	m_ObjID;
	int		m_type;
	int		m_templateId;
	char	m_name[OBJ_NAME_LEN];

};
