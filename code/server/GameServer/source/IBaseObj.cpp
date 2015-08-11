#include "IBaseObj.h"

void IBaseObj::Init()
{
	m_ObjID = 0;
	m_type = 0;
	m_templateId = 0;
	memset(m_name, 0, OBJ_NAME_LEN);
}

void IBaseObj::Copy(const IBaseObj& obj)
{
	m_ObjID = obj.m_ObjID;
	m_type = obj.m_type;
	m_templateId = obj.m_templateId;
	strncpy(m_name, obj.m_name, OBJ_NAME_LEN);
}

int	IBaseObj::GetFieldInt(int i)
{
	int* field = _FindFieldInt(i);
	if( field )
		return *field;
	else
		return _GetXmlFieldInt(i);
}

void IBaseObj::SetFieldInt(int i, int value, bool client)
{
	int* field = _FindFieldInt(i);
	if( field )
		*field = value;
	else
		_SetXmlFieldInt(i, value);

	if( client )
		SyncFieldIntToClient(i);

	_ChangeRelatedField(i, client);
}

int64 IBaseObj::GetFieldI64(int i)
{
	int64* field = _FindFieldI64(i);
	if( field )
		return *field;
	else
		return _GetXmlFieldI64(i);
}

void IBaseObj::SetFieldI64(int i, int64 value, bool client)
{
	int64* field = _FindFieldI64(i);
	if( field )
		*field = value;
	else
		_SetXmlFieldI64(i, value);

	if( client )
		SyncFieldI64ToClient(i);

	_ChangeRelatedField(i, client);
}

void IBaseObj::ChangeFieldInt(int i, int value, bool client)
{
	if( value == 0 )
		return;

	int* field = _FindFieldInt(i);
	if( field )
	{
		*field += value;
	}
	else
	{
		int v = _GetXmlFieldInt(i);
		_SetXmlFieldInt(i, v + value);
	}

	if( client )
		SyncFieldIntToClient(i);

	_ChangeRelatedField(i, client);
}

void IBaseObj::ChangeFieldI64(int i, int64 value, bool client)
{
	if( value == 0 )
		return;

	int64* field = _FindFieldI64(i);
	if( field )
	{
		*field += value;
	}
	else
	{
		int64 v = _GetXmlFieldI64(i);
		_SetXmlFieldI64(i, v + value);
	}

	if( client )
		SyncFieldI64ToClient(i);

	_ChangeRelatedField(i, client);
}
