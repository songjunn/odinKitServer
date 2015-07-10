#include "mongo_interface.h"
#include "memorypool.h"
#include "Log.h"


CObjectMemoryPool<OperObj>	g_MongoOperPool;

bool GetBsonFieldInt(mongo::BSONObj obj, const std::string field, int& value)
{
	try
	{
	    value = obj[field.c_str()].Int();
		return true;
    }
	catch(mongo::DBException ex)
	{
	    Log.Error("[MongoDB] Exception:%d, %s, %s", ex.getCode(), ex.what(), field.c_str());
		return false;
	}
}

bool GetBsonFieldI64(mongo::BSONObj obj, const std::string field, int64& value)
{
	try
	{
	    value = obj[field.c_str()].Long();
		return true;
    }
	catch(mongo::DBException ex)
	{
	    Log.Error("[MongoDB] Exception:%d, %s, %s", ex.getCode(), ex.what(), field.c_str());
		return false;
	}
}

bool GetBsonFieldBool(mongo::BSONObj obj, const std::string field, bool& value)
{
	try
	{
	    value = obj[field.c_str()].Bool();
		return true;
	}
    catch(mongo::DBException ex)
	{
	    Log.Error("[MongoDB] Exception:%d, %s, %s", ex.getCode(), ex.what(), field.c_str());
		return false;
	}
}

bool GetBsonFieldString(mongo::BSONObj obj, const std::string field, std::string& value)
{
	 try
	{
	    value = obj[field.c_str()].String();
		return true;
	}
    catch(mongo::DBException ex)
	{
	    Log.Error("[MongoDB] Exception:%d, %s, %s", ex.getCode(), ex.what(), field.c_str());
		return false;
	}
}

bool GetBsonFieldArray(mongo::BSONObj obj, const std::string field, mongo::vector<mongo::BSONElement>& vec)
{
    try
	{
	    vec = obj[field.c_str()].Array();
		return true;
	}
	catch(mongo::DBException ex)
	{
	    Log.Error("[MongoDB] Exception:%d, %s, %s", ex.getCode(), ex.what(), field.c_str());
		return false;
	}
}

bool GetBsonFieldObj(mongo::BSONObj obj, const std::string field, mongo::BSONObj &bsonobj)
{
	try {
		bsonobj = obj[field.c_str()].Obj();
		return true;
	}
	catch (mongo::DBException ex) {
		Log.Error("[MongoDB] Exception:%d, %s, %s", ex.getCode(), ex.what(), field.c_str());
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//

CMongoClient::CMongoClient() : m_working(false), m_connect(false)
{
    bool auto_connect = true;
    double so_timeout = 3;

    m_conn = NEW mongo::DBClientConnection(auto_connect, 0, so_timeout);
}

CMongoClient::~CMongoClient()
{
    SAFE_DELETE(m_conn);
}

void CMongoClient::Shutdown()
{
	m_working = false;
	ThreadLib::WaitForFinish(m_threadID);
}

bool CMongoClient::Connect(std::string host, std::string port, std::string dbname)
{
	m_dbname = dbname;
	m_port = atoi(port.c_str());
	strncpy(m_host, host.c_str(), 32);

	std::string errmsg = "";
	char dbserver[64] = {0};
	sprintf(dbserver, "%s:%d", m_host, m_port);
    if( !m_conn->connect(dbserver, errmsg) )
    {
        Log.Error("[MongonDB] Connect %s:%d db:%s Error:%s", m_host, m_port, m_dbname.c_str(), errmsg.c_str());
        return false;
    }

    m_connect = true;
	m_working = true;

	m_threadID = ThreadLib::Create(_ExecOperation, this);

    Log.Notice("[MongonDB] Connect %s:%d db:%s Success", m_host, m_port, m_dbname.c_str());

    return true;
}

void CMongoClient::Execute(int opr_type, std::string opr_collection, mongo::Query opr_condition, mongo::BSONObj opr_bson)
{
    //OperObj* oper = NEW OperObj;
	OperObj* oper = g_MongoOperPool.Alloc();
    if( !oper )
        return;

    oper->opr_type = opr_type;
    oper->opr_collection = opr_collection;
	if( opr_type != Opr_Insert )
		oper->opr_condition = opr_condition;
	if( opr_type != Opr_Delete )
		oper->opr_bson = opr_bson;

    m_Locker.LOCK();
    m_ObjList.AddToTail(oper);
    m_Locker.UNLOCK();
}

bool CMongoClient::_Reconnect()
{
	std::string errmsg = "";
	char dbserver[64] = {0};
	sprintf(dbserver, "%s:%d", m_host, m_port);
    if( !m_conn->connect(dbserver, errmsg) )
    {
        Log.Error("[MongonDB] Connect %s:%d db:%s Error:%s", m_host, m_port, m_dbname.c_str(), errmsg.c_str());
        return false;
    }

    m_connect = true;

    Log.Notice("[MongonDB] Connect %s:%d db:%s Success", m_host, m_port, m_dbname.c_str());

	return true;
}

void CMongoClient::_Insert(const std::string collection, mongo::BSONObj obj)
{
    try
	{
	    m_conn->insert(m_dbname+"."+collection, obj);
	}
	catch(mongo::DBException ex)
	{
	    Log.Error("[MongoDB] Insert Failed:%s:%s, %s", m_dbname.c_str(), collection.c_str(), obj.toString().c_str());
	    Log.Error("[MongoDB] Exception:%d, %s", ex.getCode(), ex.what());
	}
}

void CMongoClient::_Delete(const std::string collection, mongo::Query condition)
{
    try
	{
	    m_conn->remove(m_dbname+"."+collection, condition);
	}
	catch(mongo::DBException ex)
	{
	    Log.Error("[MongoDB] Delete Failed:%s:%s, %s", m_dbname.c_str(), collection.c_str(), condition.toString().c_str());
	    Log.Error("[MongoDB] Exception:%d, %s", ex.getCode(), ex.what());
	}
}

void CMongoClient::_Update(const std::string collection, mongo::Query condition, mongo::BSONObj obj)
{
    try
	{
	    m_conn->update(m_dbname+"."+collection, condition, obj);
	}
	catch(mongo::DBException ex)
	{
	    Log.Error("[MongoDB] Update Failed:%s:%s, %s, %s", m_dbname.c_str(), collection.c_str(), condition.toString().c_str(), obj.toString().c_str());
	    Log.Error("[MongoDB] Exception:%d, %s", ex.getCode(), ex.what());
    }
}

void CMongoClient::Select(mongo::auto_ptr<mongo::DBClientCursor>& cursor, const std::string collection, mongo::Query condition)
{
    try
	{
	    cursor = m_conn->query(m_dbname+"."+collection, condition);
	}
    catch(mongo::DBException ex)
	{
	    Log.Error("[MongoDB] Query Failed:%s:%s, %s", m_dbname.c_str(), collection.c_str(), condition.toString().c_str());
		Log.Error("[MongoDB] Exception:%d, %s", ex.getCode(), ex.what());
	}
}

int CMongoClient::GetFieldInt(mongo::BSONObj obj, const std::string field)
{
    try
	{
	    return obj[field.c_str()].Int();
    }
	catch(mongo::DBException ex)
	{
	    Log.Error("[MongoDB] Exception:%d, %s, %s", ex.getCode(), ex.what(), field.c_str());
	}
	return -1;
}

int64 CMongoClient::GetFieldI64(mongo::BSONObj obj, const std::string field)
{
    try
	{
	    return obj[field.c_str()].Long();
	}
    catch(mongo::DBException ex)
	{
	    Log.Error("[MongoDB] Exception:%d, %s, %s", ex.getCode(), ex.what(), field.c_str());
	}
	return -1;
}

bool CMongoClient::GetFieldBool(mongo::BSONObj obj, const std::string field)
{
	try
	{
	    return obj[field.c_str()].Bool();
	}
    catch(mongo::DBException ex)
	{
	    Log.Error("[MongoDB] Exception:%d, %s, %s", ex.getCode(), ex.what(), field.c_str());
	}
	return false;
}

std::string CMongoClient::GetFieldString(mongo::BSONObj obj, const std::string field)
{
    try
	{
	    return obj[field.c_str()].String();
	}
    catch(mongo::DBException ex)
	{
	    Log.Error("[MongoDB] Exception:%d, %s, %s", ex.getCode(), ex.what(), field.c_str());
	}
    return NULL;
}

void CMongoClient::GetFieldArray(mongo::BSONObj obj, const std::string field, mongo::vector<mongo::BSONElement>& vec)
{
    try
	{
	    vec = obj[field.c_str()].Array();
	}
	catch(mongo::DBException ex)
	{
	    Log.Error("[MongoDB] Exception:%d, %s, %s", ex.getCode(), ex.what(), field.c_str());
	}
}

OperObj* CMongoClient::_GetHeadOpr()
{
    OperObj* opr = NULL;

    m_Locker.LOCK();
    int index = m_ObjList.Head();
    if(m_ObjList.IsValidIndex(index))
    {
        opr = m_ObjList.Element(index);
		m_ObjList.Remove(index);
    }
    m_Locker.UNLOCK();

    return opr;
}

void CMongoClient::_ExecuteOpr(OperObj* opr)
{
    switch(opr->opr_type)
	{
		case Opr_Update:
			{
				_Update(opr->opr_collection, opr->opr_condition, opr->opr_bson);
			}
			break;
		case Opr_Insert:
			{
				_Insert(opr->opr_collection, opr->opr_bson); 
			}
			break;
		/*case Opr_Query:
			{
				_Select(opr->opr_collection, opr->opr_condition);
			}
			break;*/
		case Opr_Delete:
			{
				_Delete(opr->opr_collection, opr->opr_condition);
			}
			break;
		default:
			break;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CMongoClient::_ExecOperation(void* param)
{
#if (!defined(_DEBUG)) && defined(WIN32)
    __try
#endif    {
        CMongoClient* pThis = (CMongoClient*)param;

		while(pThis->_IsWorking())
		{
			pThis->m_Eventer.Wait(1);

			if(!pThis->m_conn)
				return;

			if(!pThis->_IsConnected())
			{
				Log.Error("[MongonDB] DataBase connection error");

				pThis->_Reconnect();

				continue;
			}

			OperObj* opr = NULL;
			while(opr = pThis->_GetHeadOpr())
			{
				pThis->_ExecuteOpr(opr);

				//SAFE_DELETE(opr);
				g_MongoOperPool.Free(opr);
			}
		}
    }
#if (!defined(_DEBUG)) && defined(WIN32)
    __except (HandleException(GetExceptionInformation(), "_ExecOperation"))
    {

    }
#endif
    return;
}
