#include "Player.h"
#include "RoleTemplate.h"
#include "gtime.h"
#include "error.h"
#include "attrs.h"
#include "NoticeModule.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "MessageTypeDefine.pb.h"
#include "MessageGameobj.pb.h"


void CPlayer::Release()
{
	CFighter::Release();
	m_EventUnit.Release();
}

void CPlayer::Init()
{
	CFighter::Init();

	m_type = Role_Type_Player;
	m_GateSocket = -1;
	m_GoldCoin = 0;
	m_SilverCoin= 0;
	m_Exp = 0;
	m_ExpMax = 0;
	m_UserID = 0;
	m_OnlineFlag = Online_Flag_Null;
	m_LoadTime = 0;
	m_CreateTime = 0;
	m_LoginTime = 0;
	m_LogoutTime = 0;
	m_VipLevel = 0;

	m_EventUnit.Initialize(this);
}

bool CPlayer::OnMsg(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	return false;
}

void CPlayer::Copy(const CPlayer& player)
{
	CFighter::Copy(player);
}

bool CPlayer::OnCreate(int templateid)
{
	CRoleTemplate* temp = RoleTemplateMgr.GetObj( templateid );
	if( !temp )
	{
		Log.Error("[CPlayer] Invalid Player Template:%d", templateid);
		return false;
	}

	SetTemplateID(templateid);
	SetFieldInt(Role_Attrib_TemplateID, templateid);
	SetFieldInt(Role_Attrib_Vocation, temp->m_Career);
	SetFieldInt(Role_Attrib_Sex, temp->m_Sex);
	SetFieldInt(Role_Attrib_BaseStrength, temp->m_Strength);
	SetFieldInt(Role_Attrib_BaseIntellect, temp->m_Intelli);
	SetFieldInt(Role_Attrib_BaseTechnique, temp->m_Technic);
	SetFieldInt(Role_Attrib_BaseAgility, temp->m_Agility);
	SetFieldInt(Role_Attrib_Hp, temp->m_Hp);
	SetFieldInt(Role_Attrib_BaseHpMax, temp->m_Hp);
	SetFieldInt(Role_Attrib_BasePhysiDamage, temp->m_PhysiDamage);
	SetFieldInt(Role_Attrib_BaseMagicDamage, temp->m_MagicDamage);
	SetFieldInt(Role_Attrib_BaseStuntDamage, temp->m_StuntDamage);
	SetFieldInt(Role_Attrib_BasePhysiDefense, temp->m_PhysiDefense);
	SetFieldInt(Role_Attrib_BaseMagicDefense, temp->m_MagicDefense);
	SetFieldInt(Role_Attrib_BaseStuntDefense, temp->m_StuntDefense);
	SetFieldInt(Role_Attrib_BaseHit, temp->m_Hit);
	SetFieldInt(Role_Attrib_BaseJouk, temp->m_Jouk);
	SetFieldInt(Role_Attrib_BaseCrit, temp->m_Crit);
	SetFieldInt(Role_Attrib_BaseTenacity, temp->m_Tenacity);
	SetFieldInt(Role_Attrib_BaseParry, temp->m_Parry);
	SetFieldInt(Role_Attrib_BaseTreat, temp->m_Treat);

	for(int i=0; i<Combat_Place_Destory; ++i)
	{
		m_Place[i] = temp->m_Place[i];
	}

	return true;
}

int* CPlayer::_FindFieldInt(int i)
{
	int* field = CFighter::_FindFieldInt(i);
	if( field )
		return field;

	switch(i)
	{
	default:	return NULL;
	}

	return NULL;
}

int64* CPlayer::_FindFieldI64(int i)
{
	int64* field = CFighter::_FindFieldI64(i);
	if( field )
		return field;

	switch(i)
	{
	case Role_Attrib_Exp:			return &m_Exp;
	case Role_Attrib_UserID:		return &m_UserID;
	case Role_Attrib_CreateTime:	return &m_CreateTime;
	case Role_Attrib_LoginTime:		return &m_LoginTime;
	case Role_Attrib_LogoutTime:	return &m_LogoutTime;
	default:	return NULL;
	}

	return NULL;
}

std::string CPlayer::GetFieldName(int i)
{
	return attrs::player_attr_name(i);
}

void CPlayer::SyncFieldIntToData(int i)
{
	Message::SyncObjFieldItem msg;
	msg.set_id(GetID());
	msg.set_key("attrs");
	msg.set_key2(attrs::player_attr_name(i));
	msg.set_vali32(GetFieldInt(i));

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_GAMEOBJ_OBJFIELD_SETI32);
	SendDataMsg(&pack);
}

void CPlayer::SyncFieldI64ToData(int i)
{
	Message::SyncObjFieldItem msg;
	msg.set_id(GetID());
	msg.set_key("attrs");
	msg.set_key2(attrs::player_attr_name(i));
	msg.set_vali64(GetFieldI64(i));

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_GAMEOBJ_OBJFIELD_SETI64);
	SendDataMsg(&pack);
}

void CPlayer::SyncFieldIntToClient(int i, CPlayer* toPlayer)
{
	Message::PlayerAttrSync msg;
	msg.set_pid(GetID());
	_PackageMsgAttr32(msg, i);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_PLAYER_LOAD_DATA);

	if( toPlayer )
		SendObserveMsg( &pack, toPlayer );
	else
		SendClientMsg( &pack );
}

void CPlayer::SyncFieldI64ToClient(int i, CPlayer* toPlayer)
{
	Message::PlayerAttrSync msg;
	msg.set_pid(GetID());
	_PackageMsgAttr64(msg, i);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_PLAYER_LOAD_DATA);

	if (toPlayer)
		SendObserveMsg(&pack, toPlayer);
	else
		SendClientMsg(&pack);
}

void CPlayer::_PackageMsgAttr32(Message::PlayerAttrSync& msg, int i)
{
	Message::PlayerAttrSync::Attr * attr = msg.add_attr();
	attr->set_type(i);
	attr->set_val32(GetFieldInt(i));
}

void CPlayer::_PackageMsgAttr64(Message::PlayerAttrSync& msg, int i)
{
	Message::PlayerAttrSync::Attr * attr = msg.add_attr();
	attr->set_type(i);
	attr->set_val64(GetFieldI64(i));
}

void CPlayer::SyncAllAttrToClient(CPlayer* toPlayer)
{
	Message::PlayerAttrSync msg;
	msg.set_pid(GetID());
	_PackageMsgAttr32(msg, Role_Attrib_TemplateID);
	_PackageMsgAttr32(msg, Role_Attrib_Level);
	_PackageMsgAttr32(msg, Role_Attrib_Hp);
	_PackageMsgAttr32(msg, Role_Attrib_GoldCoin);
	_PackageMsgAttr32(msg, Role_Attrib_SilverCoin);
	_PackageMsgAttr32(msg, Role_Attrib_Fighting);
	_PackageMsgAttr32(msg, Role_Attrib_Strength);
	_PackageMsgAttr32(msg, Role_Attrib_Intellect);
	_PackageMsgAttr32(msg, Role_Attrib_Technique);
	_PackageMsgAttr32(msg, Role_Attrib_Agility);
	_PackageMsgAttr32(msg, Role_Attrib_Hit);
	_PackageMsgAttr32(msg, Role_Attrib_Jouk);
	_PackageMsgAttr32(msg, Role_Attrib_Crit);
	_PackageMsgAttr32(msg, Role_Attrib_Tenacity);
	_PackageMsgAttr32(msg, Role_Attrib_Parry);
	_PackageMsgAttr32(msg, Role_Attrib_PhysiDamage);
	_PackageMsgAttr32(msg, Role_Attrib_PhysiDefense);
	_PackageMsgAttr32(msg, Role_Attrib_MagicDamage);
	_PackageMsgAttr32(msg, Role_Attrib_MagicDefense);
	_PackageMsgAttr32(msg, Role_Attrib_StuntDamage);
	_PackageMsgAttr32(msg, Role_Attrib_StuntDefense);
	_PackageMsgAttr32(msg, Role_Attrib_BaseStrength);
	_PackageMsgAttr32(msg, Role_Attrib_BaseIntellect);
	_PackageMsgAttr32(msg, Role_Attrib_BaseTechnique);
	_PackageMsgAttr32(msg, Role_Attrib_BaseAgility);
	_PackageMsgAttr64(msg, Role_Attrib_Exp);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_PLAYER_LOAD_DATA);

	if( toPlayer )
		SendObserveMsg( &pack, toPlayer );
	else
		SendClientMsg(&pack);
}

void CPlayer::DataInit()
{
	this->InitBaseAttr();
}

void CPlayer::DataSync()
{
	this->SyncAllAttrToClient();
}

void CPlayer::SerializeFieldInt(int i, rapidjson::Value& json, rapidjson::Document& root)
{
	rapidjson::Value jsonName;
	rapidjson::Value jsonValue;

	jsonName.SetString(attrs::player_attr_name(i).c_str(), root.GetAllocator());
	jsonValue.SetInt(GetFieldInt(i));

	json.AddMember(jsonName, jsonValue, root.GetAllocator());
}

void CPlayer::SerializeFieldI64(int i, rapidjson::Value& json, rapidjson::Document& root)
{
	rapidjson::Value jsonName;
	rapidjson::Value jsonValue;

	jsonName.SetString(attrs::player_attr_name(i).c_str(), root.GetAllocator());
	jsonValue.SetInt64(GetFieldI64(i));

	json.AddMember(jsonName, jsonValue, root.GetAllocator());
}

void CPlayer::Serialize(std::string& jsonstr)
{
	rapidjson::Document root;
	root.SetObject();

	rapidjson::Value attrs;
	attrs.SetObject();

	SerializeFieldI64(Role_Attrib_ID, root, root);
	SerializeFieldI64(Role_Attrib_UserID, root, root);
	SerializeFieldInt(Role_Attrib_TemplateID, root, root);

	//name
	rapidjson::Value jsonName;
	rapidjson::Value jsonValue;
	jsonName.SetString("name", root.GetAllocator());
	jsonValue.SetString(GetName());
	root.AddMember(jsonName, jsonValue, root.GetAllocator());
	
	SerializeFieldI64(Role_Attrib_SceneID, attrs, root);
	SerializeFieldInt(Role_Attrib_Position, attrs, root);
	SerializeFieldInt(Role_Attrib_Vocation, attrs, root);
	SerializeFieldInt(Role_Attrib_Sex, attrs, root);
	SerializeFieldInt(Role_Attrib_Level, attrs, root);
	SerializeFieldI64(Role_Attrib_Exp, attrs, root);
	SerializeFieldInt(Role_Attrib_GoldCoin, attrs, root);
	SerializeFieldInt(Role_Attrib_SilverCoin, attrs, root);
	SerializeFieldInt(Role_Attrib_Fighting, attrs, root);
	SerializeFieldI64(Role_Attrib_CreateTime, attrs, root);
	SerializeFieldI64(Role_Attrib_LoginTime, attrs, root);
	SerializeFieldI64(Role_Attrib_LogoutTime, attrs, root);

	root.AddMember("attrs", attrs, root.GetAllocator());

	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	root.Accept(writer);
	jsonstr.assign(buffer.GetString(), buffer.Size());
}

void CPlayer::Deserialize(std::string jsonstr)
{
	rapidjson::Document attrs;
	attrs.Parse<0>(jsonstr.c_str());

	for (rapidjson::Value::MemberIterator it = attrs.MemberBegin(); it != attrs.MemberEnd(); ++it) {

		if (it->value.IsInt()) {
			SetFieldInt(attrs::player_attr_type(it->name.GetString()), it->value.GetInt());
		}
		else if (it->value.IsInt64()) {
			SetFieldI64(attrs::player_attr_type(it->name.GetString()), it->value.GetInt64());
		}
		else if (it->value.IsString()) {
			SetName(it->value.GetString()); //Ö±½ÓÐ´Ãû×Ö°É
		}
		else if (it->value.IsArray()) {

		}
		else if (it->value.IsObject()) {

		}
	}
}
