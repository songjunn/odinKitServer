#include "IBaseObj.h"

void IBaseObj::Init()
{
	m_templateId = 0;
	m_ObjID = 0;
}

int	IBaseObj::GetFieldInt(int i)
{
	int* field = _FindFieldInt(i);
	if( !field )
		return -1;
	return *field;
}

void IBaseObj::SetFieldInt(int i, int value, bool client, bool data)
{
	int* field = _FindFieldInt(i);
	if( !field )
		return;
	*field = value;

	SyncFieldInt(i, client, data);

	_ChangeRelatedField(i, client, data);
}

int64 IBaseObj::GetFieldI64(int i)
{
	int64* field = _FindFieldI64(i);
	if( !field )
		return -1;
	return *field;
}

void IBaseObj::SetFieldI64(int i, int64 value, bool client, bool data)
{
	int64* field = _FindFieldI64(i);
	if( !field )
		return;
	*field = value;

	SyncFieldI64(i, client, data);

	_ChangeRelatedField(i, client, data);
}

void IBaseObj::ChangeFieldInt(int i, int value, bool client, bool data)
{
	if( value == 0 )
		return;
	int* field = _FindFieldInt(i);
	if( !field )
		return;
	*field += value;
	//*field = *field >= 0 ? *field : 0;

	SyncFieldInt(i, client, data);

	_ChangeRelatedField(i, client, data);
}

void IBaseObj::ChangeFieldI64(int i, int64 value, bool client, bool data)
{
	if( value == 0 )
		return;
	int64* field = _FindFieldI64(i);
	if( !field )
		return;
	*field += value;
	*field = *field >= 0 ? *field : 0;

	SyncFieldI64(i, client, data);

	_ChangeRelatedField(i, client, data);
}
