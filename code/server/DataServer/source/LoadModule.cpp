#include "LoadModule.h"
#include "DataModule.h"
#include "commdata.h"
#include "utlsymbol.h"
#include "strtools.h"
#include "gtime.h"
#include "MainServer.h"
#include "Packet.h"
#include "PacketDefine.h"
#include "MessagePlayerCount.pb.h"
#include "MessageUserLogin.pb.h"
#include "MessageReqPlayerData.pb.h"
#include "MessageCheckNameRequest.pb.h"
#include "MessageCheckNameResponse.pb.h"
#include "MessageWorldDataRequest.pb.h"
#include "MessageWorldDataResponse.pb.h"


bool CLoadModule::onMessage(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	switch(pack->Type())
	{
	case A2D_REQUEST_USER_LOGIN:		_handlePacket_LoadPlayerCount(pack);	break;
	case G2D_REQUEST_GAMEOBJ_DATA:		_handlePakcet_LoadObjData(pack);		break;
	case G2D_REQUEST_CHECK_NAME:		_handlePacket_CheckNameRepeat(pack);	break;
	case D2G_REQUEST_WORLD_DATA:		_handlePacket_LoadWorldData(pack);		break;
	default:	return false;
	}

	return true;
}

void CLoadModule::onLogic()
{
	int n = 0;
	int index = m_LoadList.Head();

	while( m_LoadList.IsValidIndex(index) && n++ < 10 )
	{
		CLoadObj* loader = m_LoadList[index];
		if( loader )
		{
			if( loader->id > 0 )
			{
				CDataObj* obj = DataModule.loadDb(loader->type, loader->key, loader->id);
				if( obj )
					DataModule.syncObjSeparate(obj, loader->sock);
			}
			else
			{
				if( DataModule.loadDb(loader->type) )
					DataModule.syncObj(loader->type, loader->sock);
			}

			SAFE_DELETE(loader);
		}
		
		m_LoadList.Remove(index);
		index = m_LoadList.Head();
	}
}

bool CLoadModule::_handlePacket_LoadWorldData(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::WorldDataRequest msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	mongo::Query query;
	mongo::auto_ptr<mongo::DBClientCursor> cursor;
	GETMONGODB->select(cursor, "player", query.sort(BSON("playerid" << -1)));

	PersonID playerid = INVALID_VALUE;
	if (cursor.get() && cursor->more()) {
		GETMONGODB->getBsonFieldI64(cursor->next(), "playerid", playerid);
	}

	Message::WorldDataResponse msgData;
	msgData.set_playerid( playerid );

	PACKET_COMMAND packData;
	PROTOBUF_CMD_PACKAGE( packData, msgData, D2G_RESPONSE_WORLD_DATA );
	GETSERVERNET->sendMsg(pack->GetNetID(), &packData);

	return true;
}

bool CLoadModule::_handlePakcet_LoadObjData(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::ReqPlayerData msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	CDataObj* obj = DataModule.GetObj(msg.pid());
	if( obj )
	{
		DataModule.syncObjSeparate(obj, pack->GetNetID());
	}
	else
	{
		CLoadObj* loader = NEW CLoadObj;
		if( !loader )
			return false;

		loader->type = msg.type();
		loader->key = msg.key();
		loader->id = msg.pid();
		loader->sock = pack->GetNetID();

		m_LoadList.AddToTail(loader);
	}

	return true;
}

bool CLoadModule::_handlePacket_CheckNameRepeat(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::CheckNameRequest msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	//全部转换小写进行比较
	char name[OBJ_NAME_LEN] = {0};
	strnlower(msg.name().c_str(), name, OBJ_NAME_LEN);

	CUtlSymbol symbol = CUtlSymbol::Find(name);
	bool result = !symbol.IsValid();
	if( result )
		symbol.AddString(name);

	Message::CheckNameResponse msg1;
	msg1.set_uid( msg.uid() );
	msg1.set_pid( msg.pid() );
	msg1.set_result( result );

	PACKET_COMMAND pack1;
	PROTOBUF_CMD_PACKAGE( pack1, msg1, G2D_RESPONSE_CHECK_NAME );
	GETSERVERNET->sendMsg(pack->GetNetID(), &pack1);

	return true;
}

bool CLoadModule::_handlePacket_LoadPlayerCount(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::UserLogin msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	mongo::Query query = QUERY(msg.key()<<(int64)msg.uid());
	mongo::auto_ptr<mongo::DBClientCursor> cursor;
	GETMONGODB->select(cursor, msg.type(), query);

	std::string idstr = msg.type() + "id";
	std::vector<int64> objs;
	while (cursor.get() && cursor->more())
	{
		mongo::BSONObj p = cursor->next();

		PersonID playerid = INVALID_VALUE;
		if (GETMONGODB->getBsonFieldI64(p, idstr, playerid)) {
			objs.push_back(playerid);
		}
	}

	Message::PlayerCount msgCnt;
	msgCnt.set_uid(msg.uid());
	for(uint i=0; i<objs.size(); ++i)
		msgCnt.add_player(objs[i]);

	PACKET_COMMAND packCnt;
	PROTOBUF_CMD_PACKAGE(packCnt, msgCnt, D2P_NOTIFY_PLAYER_COUNT);
	GETSERVERNET->sendMsg(pack->GetNetID(), &packCnt);

	return true;
}
