#ifndef _DATAMODULE_H_
#define _DATAMODULE_H_

#include "platform.h"
#include "Singleton.h"
#include <string>

class IBaseObj;
class PACKET_COMMAND;
class CDataModule : public Singleton< CDataModule >
{
public:
	CDataModule()	{}
	~CDataModule()	{}

	bool onMessage(PACKET_COMMAND* pack);

	void syncCreate(IBaseObj* obj, std::string type, int sock);
	void syncRemove(IBaseObj* obj, int sock);
	void syncFieldInt(IBaseObj* obj, const char* group, int i, int sock);
	void syncFieldI64(IBaseObj* obj, const char* group, int i, int sock);
	void syncFieldStr(IBaseObj* obj, const char* group, int i, int sock);
	void syncGroupAll(IBaseObj* obj, const char* group, const char* json, int sock);
	void syncAddMap(int64 id, int sock, const char* field, const char* jsonstr);
	void syncDelMap(int64 id, int sock, const char* field);
	void syncSetMap(int64 id, int sock, const char* field, const char* item, int value);
	void syncSetMap(int64 id, int sock, const char* field, const char* item, int64 value);
	void syncSetMap(int64 id, int sock, const char* field, const char* item, const char* value);

};

#define DataModule CDataModule::getSingleton()

#endif	//_DATAMODULE_H_
