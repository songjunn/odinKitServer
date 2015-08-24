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
	void syncFieldInt(IBaseObj* obj, std::string group, int i, int sock);
	void syncFieldI64(IBaseObj* obj, std::string group, int i, int sock);
	void syncFieldStr(IBaseObj* obj, std::string group, int i, int sock);
	void syncGroupAll(IBaseObj* obj, std::string group, std::string json, int sock);
	void syncAddMap(int64 id, IBaseObj* obj, std::string group, int sock);
	void syncDelMap(int64 id, IBaseObj* obj, std::string group, int sock);
	void syncSetMap(int64 id, IBaseObj* obj, std::string group, std::string field, int value, int sock);
	void syncSetMap(int64 id, IBaseObj* obj, std::string group, std::string field, int64 value, int sock);
	void syncSetMap(int64 id, IBaseObj* obj, std::string group, std::string field, std::string value, int sock);

};

#define DataModule CDataModule::getSingleton()

#endif	//_DATAMODULE_H_
