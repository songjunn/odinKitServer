#pragma once
#include "commdata.h"

class CPlayer;
class PACKET_COMMAND;
class IBaseObj
{
public:
	IBaseObj() : m_templateId(0), m_ObjID(0) {}
	virtual ~IBaseObj() {}

	void	Init();

	//属性管理接口
	int		GetFieldInt(int i);
	int64	GetFieldI64(int i);

	void	SetFieldInt(int i, int value, bool client=false, bool data=false);
	void	SetFieldI64(int i, int64 value, bool client=false, bool data=false);

	virtual void	ChangeFieldInt(int i, int value, bool client=false, bool data=false);
	void	ChangeFieldI64(int i, int64 value, bool client=false, bool data=false);

	inline	int		GetTemplateID()			{return m_templateId;}
	inline  void	SetTemplateID(int id)	{m_templateId = id;}

	inline	int64	GetID()					{return m_ObjID;}
	inline  void	SetID(int64 id)			{m_ObjID = id;}

	virtual void	SendClientMsg(PACKET_COMMAND* pack)	{return;}
	virtual	void	SendDataMsg(PACKET_COMMAND* pack)	{return;}
	virtual	void	SendObserveMsg(PACKET_COMMAND* pack, CPlayer* player)	{return;}

	virtual void	SyncFieldInt(int i, bool client = false, bool data = false, CPlayer* toPlayer = NULL)	{return;};
	virtual void	SyncFieldI64(int i, bool client = false, bool data = false, CPlayer* toPlayer = NULL)	{return;};

protected:
	virtual int*	_FindFieldInt(int i)			{return NULL;}
	virtual int64*	_FindFieldI64(int i)			{return NULL;}

	virtual void	_ChangeRelatedField(int i, bool client=false, bool data=false)	{return;}

protected:
	int		m_templateId;
	int64	m_ObjID;

};
