#ifndef SHARED_MONGO_INTERFACE_H
#define SHARED_MONGO_INTERFACE_H

#include <string>
#include "mongo/client/dbclient.h"
#include "utllinkedlist.h"
#include "Lock.h"
#include "ThreadLib.h"

enum Opr_Type		//定义数据库操作类型
{
	Opr_Update = 1,	//修改操作
	Opr_Insert,		//插入操作
	Opr_Query,		//查询操作
	Opr_Delete,		//删除操作
};

struct OperObj
{
	int		        opr_type;
    mongo::Query	opr_condition;
    mongo::BSONObj	opr_bson;
	std::string		opr_collection;
};

bool GetBsonFieldInt(mongo::BSONObj obj, const std::string field, int& value);
bool GetBsonFieldI64(mongo::BSONObj obj, const std::string field, int64& value);
bool GetBsonFieldBool(mongo::BSONObj obj, const std::string field, bool& value);
bool GetBsonFieldString(mongo::BSONObj obj, const std::string field, std::string& value);
bool GetBsonFieldArray(mongo::BSONObj obj, const std::string field, mongo::vector<mongo::BSONElement>& vec);
bool GetBsonFieldObj(mongo::BSONObj obj, const std::string field, mongo::BSONObj &bsonobj);

class CMongoClient
{
public:
    CMongoClient();
    ~CMongoClient();

	void Shutdown();
	bool Connect(std::string host, std::string port, std::string dbname);
	void Execute(int opr_type, std::string opr_collection, mongo::Query opr_condition, mongo::BSONObj opr_bson);
	void Select(mongo::auto_ptr<mongo::DBClientCursor>& cursor, const std::string collection, mongo::Query condition);
	
	int  GetFieldInt(mongo::BSONObj obj, const std::string field);
	int64 GetFieldI64(mongo::BSONObj obj, const std::string field);
	bool GetFieldBool(mongo::BSONObj obj, const std::string field);
	std::string GetFieldString(mongo::BSONObj obj, const std::string field);
	void GetFieldArray(mongo::BSONObj obj, const std::string field, mongo::vector<mongo::BSONElement>& vec);

protected:
	void _Insert(const std::string collection, mongo::BSONObj obj);
	void _Delete(const std::string collection, mongo::Query condition);
	void _Update(const std::string collection, mongo::Query condition, mongo::BSONObj obj);

	bool _Reconnect();
	void _DisConnect();

	void _ExecuteOpr(OperObj* opr);
	OperObj* _GetHeadOpr();
	int	_HandleError();

	inline bool	_IsWorking() {return m_working;}
	inline bool	_IsConnected() {return m_connect;}

	static void	_ExecOperation(void* param);

protected:
	ThreadLib::ThreadID m_threadID;
	bool m_working;
	bool m_connect;
	int  m_port;
	char m_host[32];
	std::string m_dbname;
	mongo::DBClientConnection*	m_conn;

	Eventer m_Eventer;
	Mutex	m_Locker;
	CUtlLinkedList<OperObj*> m_ObjList;

};

#endif	//SHARED_MONGO_INTERFACE_H
