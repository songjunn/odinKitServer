#pragma once
#include <string.h>
#include "IBaseObj.h"


class CEvent;
class PACKET_COMMAND;
class CRole : public IBaseObj
{
public:
	CRole() {}
	virtual ~CRole() {}

	void	Init();

	virtual void	Copy(const CRole& role);

	virtual	void	OnEvent(CEvent* ev)				{return;}

	inline	char*	GetName()						{return m_name;}
	inline	void	SetName(const char* value)		{strncpy(m_name, value, OBJ_NAME_LEN);}

	inline	bool	IsPlayer()						{return m_RoleType == Role_Type_Player;}
	inline	bool	IsHero()						{return m_RoleType == Role_Type_Hero;}
	inline	bool	IsMonster()						{return m_RoleType == Role_Type_Monster;}

public:
	int			m_RoleType;			//角色类型：玩家，英雄，怪物

protected:
	char		m_name[OBJ_NAME_LEN];

};
