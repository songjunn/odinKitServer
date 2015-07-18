#ifndef _DATAMODULE_H_
#define _DATAMODULE_H_

#include "platform.h"
#include "Singleton.h"
#include "ObjMgr.h"
#include "metadata.h"


class CDataObj : public CMetadata
{
public:
	int m_save;
	bool m_online;
	uint64 m_offtime;
};


class PACKET_COMMAND;
class CDataModule : public CObjMgr< CDataObj, int64 >, public Singleton< CDataModule >
{
	enum SaveType {
		SAVE_NONE = 0,
		SAVE_INSERT,
		SAVE_UPDATE,
		SAVE_DELETE
	};

public:
	CDataModule()	{}
	~CDataModule()	{}

	void onSave();
	bool onMessage(PACKET_COMMAND* pack);

	CDataObj* create(std::string type, int64 id);

	CDataObj* loadBson(std::string type, mongo::BSONObj& bson, int64 id);
	CDataObj* loadDb(std::string type, std::string key, int64 id);
	bool loadDb(std::string type);
	void saveDb(CDataObj* obj, std::string key);
	void updateDb(CDataObj* obj, std::string key);
	void updateDb(int64 id, std::string key);

	void syncObj(CDataObj* obj, int sock);
	void syncObj(CDataObj* obj, std::string key, int sock);
	void syncObj(std::string type, int sock);
	void syncObjSeparate(CDataObj* obj, int sock);
	void syncObjMap(CDataObj* obj, rapidjson::Value& json, std::string key, int64 mapkey, int sock);
	void syncObjFinish(int sock, std::string type, int64 id = 0);

protected:
	void _setSaveType(CDataObj* obj, int type);

};

#define DataModule CDataModule::getSingleton()

#endif	//_DATAMODULE_H_
