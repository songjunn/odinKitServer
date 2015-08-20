#include "DataModule.h"
#include "IBaseObj.h"
#include "PlayerMgr.h"
#include "GameServer.h"
#include "LoginModule.h"
#include "MessageTypeDefine.pb.h"
#include "MessageGameobj.pb.h"


void CDataModule::syncCreate(IBaseObj* obj, std::string type, int sock)
{
	std::string json;
	obj->Serialize(json);

	Message::SyncObjField msg;
	msg.set_id(obj->GetID());
	msg.set_type(type);
	msg.set_jsonstr(json);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_GAMEOBJ_CREATE);
	GETSERVERNET(&GameServer)->sendMsg(sock, &pack);
}

void CDataModule::syncRemove(IBaseObj* obj, int sock)
{
	Message::SyncObjField msg;
	msg.set_id(obj->GetID());

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_GAMEOBJ_REMOVE);
	GETSERVERNET(&GameServer)->sendMsg(sock, &pack);
}

void CDataModule::syncFieldInt(IBaseObj* obj, const char* group, int i, int sock)
{
	Message::SyncObjFieldItem msg;
	msg.set_id(obj->GetID());
	msg.set_key(group);
	msg.set_key2(obj->GetFieldName(i));
	msg.set_vali32(obj->GetFieldInt(i));

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_GAMEOBJ_OBJFIELD_SETI32);
	GETSERVERNET(&GameServer)->sendMsg(sock, &pack);
}

void CDataModule::syncFieldI64(IBaseObj* obj, const char* group, int i, int sock)
{
	Message::SyncObjFieldItem msg;
	msg.set_id(obj->GetID());
	msg.set_key(group);
	msg.set_key2(obj->GetFieldName(i));
	msg.set_vali64(obj->GetFieldI64(i));

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_GAMEOBJ_OBJFIELD_SETI64);
	GETSERVERNET(&GameServer)->sendMsg(sock, &pack);
}

void CDataModule::syncGroupAll(IBaseObj* obj, const char* group, const char* json, int sock)
{
	Message::SyncObjField msg;
	msg.set_id(obj->GetID());
	msg.set_key(group);
	msg.set_jsonstr(json);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_GAMEOBJ_OBJFIELD_SETALL);
	GETSERVERNET(&GameServer)->sendMsg(sock, &pack);
}

void CDataModule::syncAddMap(int64 id, int sock, const char* field, int64 mapkey, const char* jsonstr)
{
	Message::SyncObjField msg;
	msg.set_id(id);
	msg.set_key(field);
	msg.set_mapkey(mapkey);
	msg.set_jsonstr(jsonstr);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_GAMEOBJ_MAPFIELD_ADD);
	GETSERVERNET(&GameServer)->sendMsg(sock, &pack);
}

void CDataModule::syncSetMap(int64 id, int sock, const char* field, int64 mapkey, const char* jsonstr)
{
	Message::SyncObjField msg;
	msg.set_id(id);
	msg.set_key(field);
	msg.set_mapkey(mapkey);
	msg.set_jsonstr(jsonstr);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_GAMEOBJ_MAPFIELD_SET);
	GETSERVERNET(&GameServer)->sendMsg(sock, &pack);
}

void CDataModule::syncDelMap(int64 id, int sock, const char* field, int64 mapkey)
{
	Message::SyncObjField msg;
	msg.set_id(id);
	msg.set_key(field);
	msg.set_mapkey(mapkey);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_GAMEOBJ_MAPFIELD_DEL);
	GETSERVERNET(&GameServer)->sendMsg(sock, &pack);
}

bool CDataModule::onMessage(PACKET_COMMAND* pack)
{
	if (!pack)
		return false;

	switch(pack->Type()) {
		case Message::MSG_GAMEOBJ_SYNC:
			{
				Message::SyncObjField msg;
				PROTOBUF_CMD_PARSER(pack, msg);

				if (msg.type() == "player") {
					CPlayer* player = PlayerMgr.Create(msg.id());
					if (player) {
						player->Deserialize(msg.jsonstr());
						player->OnCreate(player->GetFieldInt(Role_Attrib_TemplateID));
					}
				}
			}
			break;
		case Message::MSG_GAMEOBJ_SYNC_OBJFIELD:
			{
				Message::SyncObjField msg;
				PROTOBUF_CMD_PARSER(pack, msg);

				if (msg.type() == "player") {
					CPlayer* player = PlayerMgr.GetObj(msg.id());
					if (player) {
						if (msg.key() == "attr") {
							player->Deserialize(msg.jsonstr());
						}
					}
				}
			}
			break;
		case Message::MSG_GAMEOBJ_SYNC_MAPFIELD:
			{
				Message::SyncObjField msg;
				PROTOBUF_CMD_PARSER(pack, msg);

				/*CMetadata* obj = this->GetObj(msg.id());
				if (obj && obj->haveMember(msg.key())) {
					obj->addFieldMap(msg.key(), msg.mapkey(), msg.jsonstr());
				}*/
			}
			break;
		case Message::MSG_GAMEOBJ_SYNC_FINISH:
			{
				Message::SyncObjField msg;
				PROTOBUF_CMD_PARSER(pack, msg);

				if (msg.type() == "player") {
					LoginModule.eventPlayerLoadover(msg.id());
				}
			}
			break;
		default:	
			return false;
	}

	return true;
}
