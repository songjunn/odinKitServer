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
	void syncGroupAll(IBaseObj* obj, const char* group, const char* json, int sock);
	void syncAddMap(int64 id, int sock, const char* field, int64 mapkey, const char* jsonstr);
	void syncSetMap(int64 id, int sock, const char* field, int64 mapkey, const char* jsonstr);
	void syncDelMap(int64 id, int sock, const char* field, int64 mapkey);

};

#define DataModule CDataModule::getSingleton()

#endif	//_DATAMODULE_H_
