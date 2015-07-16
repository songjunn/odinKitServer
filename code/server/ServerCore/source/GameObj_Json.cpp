#include "GameObj_Json.h"
#include "Log.h"


int CGameJsonObj::getFieldInt(std::string key)
{
	rapidjson::Value& member = this->getFieldVal(m_members, key);
	return this->getFieldInt(member);
}

void CGameJsonObj::setFieldInt(std::string key, int value)
{
	rapidjson::Value& member = this->getFieldVal(m_members, key);
	this->_setFieldInt(member, value);
}

int64 CGameJsonObj::getFieldI64(std::string key)
{
	rapidjson::Value& member = this->getFieldVal(m_members, key);
	return this->getFieldI64(member);
}

void CGameJsonObj::setFieldI64(std::string key, int64 value)
{
	rapidjson::Value& member = this->getFieldVal(m_members, key);
	this->_setFieldI64(member, value);
}

std::string CGameJsonObj::getFieldString(std::string key)
{
	rapidjson::Value& member = this->getFieldVal(m_members, key);
	return this->getFieldStr(member);
}

void CGameJsonObj::setFieldString(std::string key, std::string value)
{
	rapidjson::Value& member = this->getFieldVal(m_members, key);
	this->_setFieldStr(member, value);
}

int CGameJsonObj::getFieldObjInt(std::string group, std::string key)
{
	rapidjson::Value& member = this->getFieldVal(m_members, group);
	rapidjson::Value& attr = this->getFieldVal(member, key);
	return this->getFieldInt(attr);
}

void CGameJsonObj::setFieldObjInt(std::string group, std::string key, int value)
{
	rapidjson::Value& member = this->getFieldVal(m_members, group);
	rapidjson::Value& attr = this->getFieldVal(member, key);
	this->_setFieldInt(attr, value);
}

int64 CGameJsonObj::getFieldObjI64(std::string group, std::string key)
{
	rapidjson::Value& member = this->getFieldVal(m_members, group);
	rapidjson::Value& attr = this->getFieldVal(member, key);
	return this->getFieldI64(attr);
}

void CGameJsonObj::setFieldObjI64(std::string group, std::string key, int64 value)
{
	rapidjson::Value& member = this->getFieldVal(m_members, group);
	rapidjson::Value& attr = this->getFieldVal(member, key);
	this->_setFieldI64(attr, value);
}

std::string CGameJsonObj::getFieldObjString(std::string group, std::string key)
{
	rapidjson::Value& member = this->getFieldVal(m_members, group);
	rapidjson::Value& attr = this->getFieldVal(member, key);
	return this->getFieldStr(attr);
}

void CGameJsonObj::setFieldObjString(std::string group, std::string key, std::string value)
{
	rapidjson::Value& member = this->getFieldVal(m_members, group);
	rapidjson::Value& attr = this->getFieldVal(member, key);
	this->_setFieldStr(attr, value);
}

int CGameJsonObj::getVecCount(std::string key)
{
	rapidjson::Value& member = this->getFieldVal(m_members, key);
	return this->_getVecCount(member);
}

rapidjson::Value& CGameJsonObj::getFieldVec(std::string key, int idx)
{
	rapidjson::Value& member = this->getFieldVal(m_members, key);
	return this->getFieldVec(member, idx);
}

void CGameJsonObj::addFieldMap(std::string key, int64 id, std::string jsonstring)
{
	rapidjson::Document document(&m_members.GetAllocator());
	document.Parse<0>(jsonstring.c_str());
	this->addFieldMap(key, id, document);
}

void CGameJsonObj::addFieldMap(std::string key, int64 id, rapidjson::Value& value)
{
	char idx[32] = {0};
	sprintf(idx, INT64_FMT, id);
	rapidjson::Value& member = this->getFieldVal(m_members, key);
	if (this->isFieldObj(member) && !this->_hasMember(member, idx)) {
		this->_addFiledVal(member, idx, value);
	}
}

void CGameJsonObj::setFieldMap(std::string key, int64 id, std::string jsonstring)
{
	rapidjson::Document document(&m_members.GetAllocator());
	document.Parse<0>(jsonstring.c_str());
	this->setFieldMap(key, id, document);
}

void CGameJsonObj::setFieldMap(std::string key, int64 id, rapidjson::Value& value)
{
	rapidjson::Value& member = this->getFieldVal(m_members, key);
	if (this->isFieldObj(member)) {
		char idx[32] = {0};
		sprintf(idx, INT64_FMT, id);
		rapidjson::Value& node = this->getFieldVal(member, idx);
		this->_setFieldVal(node, value);
	}
}

void CGameJsonObj::delFieldMap(std::string key, int64 id)
{
	rapidjson::Value& member = this->getFieldVal(m_members, key);
	if (this->isFieldObj(member)) {
		char idx[32] = {0};
		sprintf(idx, INT64_FMT, id);
		this->_delFieldVal(member, idx);
	}
}

void CGameJsonObj::addFieldObj(std::string key)
{
	rapidjson::Document val(&m_members.GetAllocator());
	val.SetObject();
	this->_addFiledVal(m_members, key, val);
}

rapidjson::Value& CGameJsonObj::getFieldObj(std::string key)
{
	return this->getFieldVal(m_members, key);
}

void CGameJsonObj::fromBson(mongo::BSONObj& bson)
{
	std::vector<mongo::BSONElement> elements;
	bson.elems(elements);
	for (int i = 0; i<elements.size(); ++i) {
		this->_fieldBsonToJson(m_members, elements[i].fieldName(), bson);
	}
}

void CGameJsonObj::fromBson(mongo::BSONObj& bson, std::string key)
{
	rapidjson::Value& member = this->getFieldVal(m_members, key);

	std::vector<mongo::BSONElement> elements;
	bson.elems(elements);
	for (int i = 0; i<elements.size(); ++i) {
		this->_fieldBsonToJson(member, elements[i].fieldName(), bson);
	}
}

void CGameJsonObj::_fieldBsonToJson(rapidjson::Value& json, std::string key, mongo::BSONObj& bson)
{
	mongo::BSONObj valObj;
	mongo::vector<mongo::BSONElement> valArray;
	int valInt; int64 valInt64; std::string valString;
		
	switch(bson[key].type())
	{
		case mongo::NumberInt:
			if (CMongoDB::getBsonFieldInt(bson, key, valInt)) {
				if (this->_hasMember(json, key)) {
					rapidjson::Value& member = this->getFieldVal(json, key);
					this->_setFieldInt(member, valInt);
				} else {
					rapidjson::Value val;
					val.SetInt(valInt);
					this->_addFiledVal(json, key, val);
				}
			}
			break;
		case mongo::NumberLong:
			if (CMongoDB::getBsonFieldI64(bson, key, valInt64)) {
				if (this->_hasMember(json, key)) {
					rapidjson::Value& member = this->getFieldVal(json, key);
					this->_setFieldI64(member, valInt64);
				} else {
					rapidjson::Value val;
					val.SetInt64(valInt64);
					this->_addFiledVal(json, key, val);
				}
			}
			break;
		case mongo::String:
			if (CMongoDB::getBsonFieldString(bson, key, valString)) {
				if (this->_hasMember(json, key)) {
					rapidjson::Value& member = this->getFieldVal(json, key);
					this->_setFieldStr(member, valString);
				} else {
					rapidjson::Value val;
					val.SetString(valString.c_str(), m_members.GetAllocator());
					this->_addFiledVal(json, key, val);
				}
			}
			break;
		case mongo::Array:
			if (CMongoDB::getBsonFieldArray(bson, key, valArray)) {
				rapidjson::Document val(&m_members.GetAllocator());
				val.SetArray();
				this->_vecBsonToJson(val, valArray);
				if (this->_hasMember(json, key)) {
					rapidjson::Value& member = this->getFieldVal(json, key);
					this->_setFieldVal(member, val);
				} else {
					this->_addFiledVal(json, key, val);
				}
			}
			break;
		case mongo::Object:
			if (CMongoDB::getBsonFieldObj(bson, key, valObj)) {
				rapidjson::Document val(&m_members.GetAllocator());
				val.SetObject();
				this->_objBsonToJson(val, valObj);
				if (this->_hasMember(json, key)) {
					rapidjson::Value& member = this->getFieldVal(json, key);
					this->_setFieldVal(member, val);
				} else {
					this->_addFiledVal(json, key, val);
				}
			}
			break;
		default:
			break;
	}
}

void CGameJsonObj::_vecBsonToJson(rapidjson::Value& json, mongo::vector<mongo::BSONElement>& value)
{
	for (int i=0; i<value.size(); ++i) {
		rapidjson::Value val;
		switch(value[i].type())
		{
			case mongo::NumberInt: val.SetInt(value[i].Int()); break;
			case mongo::NumberLong: val.SetInt64(value[i].Long()); break;
			case mongo::String: val.SetString(value[i].String().c_str()); break;
			default: break;
		}
		this->_addFieldVec(json, val);
	}
}

void CGameJsonObj::_objBsonToJson(rapidjson::Value& json, mongo::BSONObj& bson)
{
	std::vector<mongo::BSONElement> values;
	bson.elems(values);
	for (int i = 0; i<values.size(); ++i) {
		this->_fieldBsonToJson(json, values[i].fieldName(), bson);
	}
}

void CGameJsonObj::toBson(mongo::BSONObj& bson)
{
	mongo::BSONObjBuilder objbuilder;
	for (rapidjson::Value::MemberIterator it = m_members.MemberBegin(); it != m_members.MemberEnd(); ++it) {
		this->_fieldJsonToBson(m_members, it->name.GetString(), objbuilder);
	}
	bson = objbuilder.obj(); 
}

void CGameJsonObj::toBson(mongo::BSONObj& bson, std::string key)
{
	rapidjson::Value& member = this->getFieldVal(m_members, key);

	mongo::BSONObjBuilder objbuilder;
	for (rapidjson::Value::MemberIterator it = member.MemberBegin(); it != member.MemberEnd(); ++it) {
		this->_fieldJsonToBson(member, it->name.GetString(), objbuilder);
	}
	bson = objbuilder.obj(); 
}

void CGameJsonObj::_fieldJsonToBson(rapidjson::Value& json, std::string key, mongo::BSONObjBuilder& builder)
{
	rapidjson::Value& member = this->getFieldVal(json, key);

	if (this->isFieldI64(member)) {
		builder.append(key, this->getFieldI64(member));
	}
	else if (this->isFieldInt(member)) {
		builder.append(key, this->getFieldInt(member));
	}
	else if (this->isFieldStr(member)) {
		builder.append(key, this->getFieldStr(member));
	}
	else if (this->isFieldVec(member)) {
		mongo::BSONArrayBuilder vecBuilder;
		this->_vecJsonToBson(member, vecBuilder);
		builder.append(key, vecBuilder.arr());
	}
	else if (this->isFieldObj(member)) {
		mongo::BSONObjBuilder objBuilder;
		this->_objJsonToBson(member, objBuilder);
		builder.append(key, objBuilder.obj());
	}
}

void CGameJsonObj::_vecJsonToBson(rapidjson::Value& json, mongo::BSONArrayBuilder& vecBuilder)
{
	for(int i=0; i<this->_getVecCount(json); ++i) {

		rapidjson::Value& member = this->getFieldVec(json, i);

		if (this->isFieldI64(member)) {
			vecBuilder.append(this->getFieldI64(member));
		}
		else if (this->isFieldInt(member)) {
			vecBuilder.append(this->getFieldInt(member));
		}
		else if (this->isFieldStr(member)) {
			vecBuilder.append(this->getFieldStr(member));
		}
		else if (this->isFieldObj(member)) {
			mongo::BSONObjBuilder objbuilder;
			for (rapidjson::Value::MemberIterator it = member.MemberBegin(); it != member.MemberEnd(); ++it) {
				this->_fieldJsonToBson(member, it->name.GetString(), objbuilder);
			}
			vecBuilder.append(objbuilder.obj());
		}
	}
}

void CGameJsonObj::_objJsonToBson(rapidjson::Value& json, mongo::BSONObjBuilder& objBuilder)
{
	for (rapidjson::Value::MemberIterator it = json.MemberBegin(); it != json.MemberEnd(); ++it) {
		this->_fieldJsonToBson(json, it->name.GetString(), objBuilder);
	}
}

void CGameJsonObj::toJsonstring(rapidjson::Value& json, std::string& str)
{
	rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    json.Accept(writer);
	str.assign(buffer.GetString(), buffer.Size());
}

void CGameJsonObj::toJsonstring(std::string& json)
{
	rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    m_members.Accept(writer);
	json.assign(buffer.GetString(), buffer.Size());
}

void CGameJsonObj::toJsonstring(std::string& json, std::string key)
{
	rapidjson::Value& member = this->getFieldVal(m_members, key);
	this->toJsonstring(member, json);
}

void CGameJsonObj::fromJsonstring(std::string json)
{
	rapidjson::Document doc(&m_members.GetAllocator());
	doc.Parse<0>(json.c_str());

	for (rapidjson::Value::MemberIterator it = doc.MemberBegin(); it != doc.MemberEnd(); ++it) {
		this->_fieldJsonToJson(m_members, it->name.GetString(), doc);
	}
}

void CGameJsonObj::fromJsonstring(std::string json, std::string key)
{
	rapidjson::Document doc(&m_members.GetAllocator());
	doc.Parse<0>(json.c_str());

	if (this->_hasMember(m_members, key)) {
		rapidjson::Value& member = this->getFieldVal(m_members, key);
		if (this->isFieldObj(member)) {
			for (rapidjson::Value::MemberIterator it = doc.MemberBegin(); it != doc.MemberEnd(); ++it) {
				this->_fieldJsonToJson(member, it->name.GetString(), doc);
			}
		}
		else if (this->isFieldVec(member)) {
			for(int i=0; i<this->_getVecCount(member); ++i) {
				rapidjson::Value& arrItem = this->getFieldVec(member, i);
				this->_addFieldVec(member, arrItem);
			}
		}
		else if (this->isFieldI64(member)) {
			this->_setFieldI64(member, this->getFieldI64(doc));
		}
		else if (this->isFieldInt(member)) {
			this->_setFieldInt(member, this->getFieldInt(doc));
		}
		else if (this->isFieldStr(member)) {
			this->_setFieldStr(member, this->getFieldStr(doc));
		}
	}
}

void CGameJsonObj::_fieldJsonToJson(rapidjson::Value& desjson, std::string key, rapidjson::Value& srcjson)
{
	rapidjson::Value& srcmember = this->getFieldVal(srcjson, key);
	if (this->_hasMember(desjson, key)) {
		rapidjson::Value& desmember = this->getFieldVal(desjson, key);

		if (this->isFieldI64(desmember)) {
			this->_setFieldI64(desmember, this->getFieldI64(srcmember));
		}
		else if (this->isFieldInt(desmember)) {
			this->_setFieldInt(desmember, this->getFieldInt(srcmember));
		}
		else if (this->isFieldStr(desmember)) {
			this->_setFieldStr(desmember, this->getFieldStr(srcmember));
		}
		else if (this->isFieldVec(desmember)) {
			this->_vecJsonToJson(desmember, srcmember);
		}
		else if (this->isFieldObj(desmember)) {
			this->_objJsonToJson(desmember, srcmember);
		}
	} else {
		this->_addFiledVal(desjson, key, srcmember);
	}
}

void CGameJsonObj::_objJsonToJson(rapidjson::Value& desjson, rapidjson::Value& srcjson)
{
	for (rapidjson::Value::MemberIterator it = srcjson.MemberBegin(); it != srcjson.MemberEnd(); ++it) {
		this->_fieldJsonToJson(desjson, it->name.GetString(), srcjson);
	}
}

void CGameJsonObj::_vecJsonToJson(rapidjson::Value& desjson, rapidjson::Value& srcjson)
{
	for(int i=0; i<this->_getVecCount(srcjson); ++i) {

		rapidjson::Value& member = this->getFieldVec(srcjson, i);

		if (i < desjson.Size()) {
			if (this->isFieldI64(member)) {
				this->_setFieldVec(desjson, member, i);
			}
			else if (this->isFieldInt(member)) {
				this->_setFieldVec(desjson, member, i);
			}
			else if (this->isFieldStr(member)) {
				this->_setFieldVec(desjson, member, i);
			}
			else if (this->isFieldObj(member)) {
				this->_objJsonToJson(desjson, member);
			}
		} else {
			if (this->isFieldI64(member)) {
				this->_addFieldVec(desjson, member);
			}
			else if (this->isFieldInt(member)) {
				this->_addFieldVec(desjson, member);
			}
			else if (this->isFieldStr(member)) {
				this->_addFieldVec(desjson, member);
			}
			else if (this->isFieldObj(member)) {
				rapidjson::Value obj;
				obj.SetObject();
				this->_objJsonToJson(obj, member);
			}
		}
	}
}

void CGameJsonObj::fromJsonstringCompletely(std::string json)
{
	m_members.Parse<0>(json.c_str());
}

void CGameJsonObj::fromJsonstringCompletely(std::string json, std::string key)
{
	rapidjson::Document document(&m_members.GetAllocator());
	document.Parse<0>(json.c_str());
	rapidjson::Value& member = this->getFieldVal(m_members, key);
	this->_setFieldVal(member, document);
}

void CGameJsonObj::toProtobuf(google::protobuf::Message &message)
{
	//protobuf
	const google::protobuf::Reflection	*pReflection = message.GetReflection();
	const google::protobuf::Descriptor	*pDescriptor = message.GetDescriptor();
	google::protobuf::FieldDescriptor	*pFieldDescriptor = NULL;
	std::string tmpStr;
	std::string NameStr;

	for(int i = 0; i < pDescriptor->field_count(); i++) {
		
		pFieldDescriptor = (google::protobuf::FieldDescriptor *)pDescriptor->field(i);
		
		NameStr = pFieldDescriptor->name();
		if (!m_members.HasMember(NameStr.data()))
			continue;

		if (pFieldDescriptor->is_repeated()) {
			if (this->isFieldVec(m_members[NameStr.data()])) {
				switch(pFieldDescriptor->cpp_type())
				{
					case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
						for(int idx = 0; idx < this->_getVecCount(m_members[NameStr.data()]); ++idx) {
							pReflection->AddInt32(&message, pFieldDescriptor, this->getFieldInt(m_members[NameStr.data()][idx]));
						}
						break;
					case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
						for(int idx = 0; idx < this->_getVecCount(m_members[NameStr.data()]); ++idx) {
							pReflection->AddInt64(&message, pFieldDescriptor, this->getFieldI64(m_members[NameStr.data()][idx]));
						}
						break;
					case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
						for(int idx = 0; idx < this->_getVecCount(m_members[NameStr.data()]); ++idx) {
							pReflection->AddString(&message, pFieldDescriptor,this->getFieldStr(m_members[NameStr.data()][idx]));
						}
						break;
					default:
						return;
				}
			}
		} else {
			switch(pFieldDescriptor->cpp_type())
			{
				case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
					if (this->isFieldInt(m_members[NameStr.data()])) {
						pReflection->SetInt32(&message, pFieldDescriptor, this->getFieldInt(m_members[NameStr.data()]));	
					}
					break;
				case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
					if (this->isFieldI64(m_members[NameStr.data()])) {
						pReflection->SetInt64(&message, pFieldDescriptor, this->getFieldI64(m_members[NameStr.data()]));
					}
					break;
				case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
					if (this->isFieldStr(m_members[NameStr.data()])) {
						tmpStr.assign(this->getFieldStr(m_members[NameStr.data()]));
						pReflection->SetString(&message, pFieldDescriptor, tmpStr);
					}
					break;
				default:
					return;
			}
		}
	}
}

void CGameJsonObj::fromProtobuf(google::protobuf::Message& message)
{
	//protobuf
	const google::protobuf::Reflection *pReflection = message.GetReflection();
	const google::protobuf::Descriptor *pDescriptor = message.GetDescriptor();
	google::protobuf::FieldDescriptor *pFieldDescriptor = NULL;
	std::string NameStr;
	int32  FieldNum;

	for(int i = 0; i < pDescriptor->field_count(); i++){

		pFieldDescriptor = (google::protobuf::FieldDescriptor *)pDescriptor->field(i);

		NameStr = pFieldDescriptor->name();
		if (!m_members.HasMember(NameStr.data()))
			continue;

		if (pFieldDescriptor->is_repeated()) {
			if (this->isFieldVec(m_members[NameStr.data()])) {
				switch(pFieldDescriptor->cpp_type())
				{
					case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
						for(FieldNum = 0; FieldNum < pReflection->FieldSize(message, pFieldDescriptor); FieldNum++){
							this->setFieldVec(NameStr, FieldNum, (int)pReflection->GetRepeatedInt32(message, pFieldDescriptor, FieldNum));
						}
						break;
					case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
						for(FieldNum = 0; FieldNum < pReflection->FieldSize(message, pFieldDescriptor); FieldNum++){
							this->setFieldVec(NameStr, FieldNum, (int64)pReflection->GetRepeatedInt64(message, pFieldDescriptor, FieldNum));
						}
						break;
					case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
						for(FieldNum = 0; FieldNum < pReflection->FieldSize(message, pFieldDescriptor); FieldNum++){
							this->setFieldVec(NameStr, FieldNum, pReflection->GetRepeatedString(message, pFieldDescriptor, FieldNum).c_str());
						}
						break;
					default:
						return;
				}
			}
		} else {
			switch(pFieldDescriptor->cpp_type())
			{
				case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
					if (this->isFieldInt(m_members[NameStr.data()])) {
						this->setFieldInt(NameStr, pReflection->GetInt32(message, pFieldDescriptor));
					}
					break;
				case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
					if (this->isFieldI64(m_members[NameStr.data()])) {
						this->setFieldI64(NameStr, pReflection->GetInt64(message, pFieldDescriptor));
					}
					break;
				case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
					if (this->isFieldStr(m_members[NameStr.data()])) {
						this->setFieldString(NameStr, pReflection->GetString(message, pFieldDescriptor));
					}
					break;
				default:
					return;
			}
		}
	}
}
