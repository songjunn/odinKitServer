#include "Role.h"


void CRole::Init()
{
	IBaseObj::Init();

	memset(m_name, 0, OBJ_NAME_LEN);
	m_RoleType = 0;
}

void CRole::Copy(const CRole& role)
{
	m_ObjID = role.m_ObjID;
	m_RoleType = role.m_RoleType;		
	m_templateId = role.m_templateId;
	strncpy(m_name, role.m_name, OBJ_NAME_LEN);
}
