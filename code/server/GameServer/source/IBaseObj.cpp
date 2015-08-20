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
	if (!field)
		return INVALID_VALUE;
	return *field;
}

void IBaseObj::SetFieldInt(int i, int value, bool client, bool data)
{
	int* field = _FindFieldInt(i);
	if (!field)
		return;
	*field = value;

	_ChangeRelatedField(i, client, data);

	if (client)
		SyncFieldIntToClient(i);
	if (data)
		SyncFieldIntToData(i);
}

int64 IBaseObj::GetFieldI64(int i)
{
	int64* field = _FindFieldI64(i);
	if (!field)
		return INVALID_VALUE;
	return *field;
}

void IBaseObj::SetFieldI64(int i, int64 value, bool client, bool data)
{
	int64* field = _FindFieldI64(i);
	if (!field)
		return;
	*field = value;

	_ChangeRelatedField(i, client, data);

	if (client)
		SyncFieldI64ToClient(i);
	if (data)
		SyncFieldI64ToData(i);
}

void IBaseObj::ChangeFieldInt(int i, int value, bool client, bool data)
{
	if (value == 0)
		return;

	int* field = _FindFieldInt(i);
	if (!field)
		return;
	*field += value;

	_ChangeRelatedField(i, client, data);

	if (client)
		SyncFieldIntToClient(i);
	if (data)
		SyncFieldIntToData(i);
}

void IBaseObj::ChangeFieldI64(int i, int64 value, bool client, bool data)
{
	if (value == 0)
		return;

	int64* field = _FindFieldI64(i);
	if (!field)
		return;
	*field += value;
	*field = *field >= 0 ? *field : 0;

	_ChangeRelatedField(i, client, data);

	if (client)
		SyncFieldI64ToClient(i);
	if (data)
		SyncFieldI64ToData(i);
}

