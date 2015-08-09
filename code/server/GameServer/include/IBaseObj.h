#pragma once
#include <string>
#include "commdata.h"
#include "metadata.h"

class CPlayer;
class PACKET_COMMAND;
class IBaseObj
{
public:
	IBaseObj() : m_templateId(0), m_type(0), m_ObjID(0), m_name(""){}
	virtual ~IBaseObj() {}

	virtual void Init();
	virtual void Copy(const IBaseObj& obj);
	virtual	void OnEvent(CEvent* ev)	{ return; }

	int		GetFieldInt(int i);
	int64	GetFieldI64(int i);

	void	SetFieldInt(int i, int value, bool client=false);
	void	SetFieldI64(int i, int64 value, bool client=false);

	void	ChangeFieldInt(int i, int value, bool client=false);
	void	ChangeFieldI64(int i, int64 value, bool client=false);

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

	virtual void	SyncFieldToData()			{return;}
	virtual void	SyncFieldToData(std::string field)	{return;}

	virtual void	SyncFieldIntToClient(int i, CPlayer* toPlayer = NULL)	{return;}
	virtual void	SyncFieldI64ToClient(int i, CPlayer* toPlayer = NULL)	{return;}

protected:
	virtual int*	_FindFieldInt(int i)	{return NULL;}
	virtual int64*	_FindFieldI64(int i)	{return NULL;}

	virtual void	_SetXmlFieldInt(int i, int value)	{return;}
	virtual void	_SetXmlFieldI64(int i, int64 value)	{return;}

	virtual int		_GetXmlFieldInt(int i)	{return INVALID_VALUE;}
	virtual int64	_GetXmlFieldI64(int i)	{return INVALID_VALUE;}

	virtual void	_ChangeRelatedField(int i, bool client=false)	{return;}

protected:
	int64	m_ObjID;
	int		m_type;
	int		m_templateId;
	char	m_name[OBJ_NAME_LEN];

public:
	CMetadata* m_GameObj;

};
