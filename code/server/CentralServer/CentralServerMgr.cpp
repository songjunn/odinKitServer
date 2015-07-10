#include "CentralServerMgr.h"
#include "MessageRegistServer.pb.h"
#include "MessageSyncServer.pb.h"
#include "MainServer.h"
#include "PacketDefine.h"


bool CCentralServerMgr::OnLogic()
{
	int tmp;
	for(int index = m_ServerList.Head(); m_ServerList.IsValidIndex(tmp=index); )
	{
		index = m_ServerList.Next(index);

		CServerObj* pObj = m_ServerList[tmp];
		if( !pObj )
		{
			m_ServerList.Remove(tmp);
		}
		else if( pObj->m_bBreak )
		{
			_DeleteServer(pObj);
			m_ServerList.Remove(tmp);
		}
	}

	return true;
}

bool CCentralServerMgr::_HandlePacket_RegistServer(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	Message::RegistServer msg;
	PROTOBUF_CMD_PARSER( pack, msg );

	CServerObj* server = CreateServer(msg.type(), msg.id(), msg.port(), msg.ip().c_str(), msg.extport(), msg.extip().c_str(), msg.world(), false, pack->GetNetID());
	if( !server )
		return false;

	return _OnAddServer(server);
}

bool CCentralServerMgr::_OnAddServer(CServerObj* pServer)
{
	if( !pServer )
		return false;

	FOR_EACH_LL(m_ServerList, index)
	{
		CServerObj* pObj = m_ServerList[index];
		if (!pObj || pObj->m_nID == pServer->m_nID) {
			continue;
		}

		bool flag = false;
		if (pServer->m_type == Svr_Data && (pObj->m_type == Svr_Game)) flag = true;
		else if (pServer->m_type == Svr_Game && (pObj->m_type == Svr_Data || pObj->m_type == Svr_GateWay || pObj->m_type == Svr_DataAnalysis)) flag = true;
		else if (pServer->m_type == Svr_GateWay && (pObj->m_type == Svr_Game || pObj->m_type == Svr_Login || pObj->m_type == Svr_Payment)) flag = true;
		else if (pServer->m_type == Svr_Login && (pObj->m_type == Svr_GateWay)) flag = true;
		else if (pServer->m_type == Svr_Payment && (pObj->m_type == Svr_GateWay)) flag = true;
		else if (pServer->m_type == Svr_DataAnalysis && (pObj->m_type == Svr_Game)) flag = true;

		if (flag)
		{
			Message::SyncServer msg;
			msg.set_id( pObj->m_nID );
			msg.set_type( pObj->m_type );
			msg.set_port( pObj->m_nPort );
			msg.set_ip( pObj->m_szIP );
			msg.set_extport( pObj->m_extPort );
			msg.set_extip( pObj->m_extIP );
			msg.set_world( pObj->m_worldID );

			PACKET_COMMAND pack;
			PROTOBUF_CMD_PACKAGE( pack, msg, C2S_NOTIFY_SYNC_SERVER );
			MainServer.SendMsgToServer(pServer->m_Socket, &pack);
		}
	}

	return true;
}
