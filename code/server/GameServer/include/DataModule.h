#ifndef _DATAMODULE_H_
#define _DATAMODULE_H_

#include "platform.h"
#include "Singleton.h"
#include "tinyxml.h"   
#include "tinystr.h"
#include "ObjMgr.h"
#include "GameObj_Json.h"


class PACKET_COMMAND;
class CDataModule : public CObjMgr< CGameJsonObj, int64 >, public Singleton< CDataModule >
{
public:
	CDataModule()	{objTemplate.SetObject();}
	~CDataModule()	{}

	bool onMessage(PACKET_COMMAND* pack);

	bool initObjProxy(const char* xmlFile);

	CGameJsonObj* create(const char* type, int64 id);
	CGameJsonObj* createGameJsonObj(const char* type, int64 id);

	void syncCreate(CGameJsonObj* obj, int sock);
	void syncRemove(CGameJsonObj* obj, int sock);
	void syncField(CGameJsonObj* obj, int sock, const char* field);
	void syncAddMap(int64 id, int sock, const char* field, int64 mapkey, const char* jsonstr);
	void syncSetMap(int64 id, int sock, const char* field, int64 mapkey, const char* jsonstr);
	void syncDelMap(int64 id, int sock, const char* field, int64 mapkey);

protected:
	void _parseXmlNode(TiXmlElement* node, rapidjson::Value& json);
	void _parseClildNode(TiXmlElement* node, rapidjson::Value& json);

protected:
	rapidjson::Document objTemplate;

};

#define DataModule CDataModule::getSingleton()

#endif	//_DATAMODULE_H_
