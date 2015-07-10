#pragma once
#include "RobotUnit.h"
#include "RobotObj.h"
#include "Packet.h"
#include "PacketDefine.h"
#include "MessageConnectGate.pb.h"
#include "MessagePlayerCount.pb.h"
#include "MessageCreatePlayer.pb.h"
#include "MessagePlayerAttrib.pb.h"
#include "MessagePlayerLoadOver.pb.h"
#include "MessageCombatStart.pb.h"
#include "MessageCombatReport.pb.h"
#include "MessageCombatResult.pb.h"
#include "MessageErrorNo.pb.h"
#include "MessageNetTestResponse.pb.h"
#include "MessagePlayerAttribI64.pb.h"
#include "MessagePlayerAttribInt.pb.h"
#include "MessagePlayerAttribName.pb.h"


void PacketParser( PACKET_COMMAND* pack )
{
	if( !pack )
		return;

	printf("recv pack %d\n", pack->Type());

	CMessageHandler* handler = TestUnitMgr.GetMessageHandler( pack->Type() );
    if( !handler )
		return;

	int index = 0;
	LuaParam pParam[50];	

	switch( pack->Type() )
	{
	case L2P_NOTIFY_CONNECT_GATESVR:
		{
			Message::ConnectGate msg;
			PROTOBUF_CMD_PARSER( pack, msg );

			pParam[index++].SetDataNum( pack->GetNetID() );
			pParam[index++].SetDataNum( msg.uid() );
			pParam[index++].SetDataNum( msg.key() );
			pParam[index++].SetDataNum( msg.server() );
			pParam[index++].SetDataString( msg.ip().c_str() );
			pParam[index++].SetDataNum( msg.port() );

			printf("user:%I64d\n", msg.uid());

			LuaEngine.RunLuaFunction(handler->m_szFunc, handler->m_szUnit, NULL, pParam, index);
		}
		break;
	case S2P_NOTIFY_SYNC_ERROR:
		{
			Message::ErrorNo msg;
			PROTOBUF_CMD_PARSER( pack, msg );

			printf("Error:%d\n", msg.error());
		} 
		break;
	case D2P_NOTIFY_PLAYER_COUNT:
		{
			Message::PlayerCount msg;
			PROTOBUF_CMD_PARSER( pack, msg );

			pParam[index++].SetDataNum( pack->GetNetID() );
			pParam[index++].SetDataNum( msg.count() );

			LuaEngine.RunLuaFunction(handler->m_szFunc, handler->m_szUnit, NULL, pParam, index);
		}
		break;
	case G2P_NOTIFY_PLAYER_ATTRIBUTE:
		{
			Message::PlayerAttrib msg;
			PROTOBUF_CMD_PARSER( pack, msg );

			pParam[index++].SetDataNum( pack->GetNetID() );
			pParam[index++].SetDataNum( msg.pid() );

			printf("Message %d size %u: {%s}", pack->Type(), pack->Size(), msg.Utf8DebugString().c_str());
			//LuaEngine.RunLuaFunction(handler->m_szFunc, handler->m_szUnit, NULL, pParam, index);
		}
		break;
	case D2G_NOTIFY_PLAYER_ATTRINT:
		{
			Message::PlayerAttribInt msg;
			PROTOBUF_CMD_PARSER( pack, msg );

			printf("SetAttrInt player:%I64d attr:%d value:%d\n", msg.pid(), msg.attr(), msg.value());
		}
		break;
	case D2G_NOTIFY_PLAYER_ATTRI64:
		{
			Message::PlayerAttribI64 msg;
			PROTOBUF_CMD_PARSER( pack, msg );

			printf("SetAttrI64 player:%I64d attr:%d value:%I64d\n", msg.pid(), msg.attr(), msg.value());
		}
		break;
	case D2G_NOTIFY_PLAYER_NAME:
		{
			Message::PlayerAttribName msg;
			PROTOBUF_CMD_PARSER( pack, msg );

			printf("SetName player:%I64d name:%s\n", msg.pid(), msg.name());
		}
		break;
	case D2G_NOTIFY_PLAYER_LOADOVER:
		{
			Message::PlayerLoadOver msg;
			PROTOBUF_CMD_PARSER( pack, msg );

			CRobotObj* robot = RobotMgr.GetRobot( pack->GetNetID() );
			if (robot != NULL)
			{
				robot->m_PlayerID = msg.pid();
				robot->setStat(ESTAT_LOGINGATE);
				//robot->AddExp(1000);
				//robot->AddItem();
				robot->AddHero();
				//robot->SendChat();
				//robot->RequestObserver();
				//robot->RequestJoinBattle();
				//robot->RequestAttackBoss();
				//robot->RequestHelper();
			}

			pParam[index++].SetDataNum( pack->GetNetID() );
			pParam[index++].SetDataNum( msg.pid() );

			LuaEngine.RunLuaFunction(handler->m_szFunc, handler->m_szUnit, NULL, pParam, index);
		}
		break;
	case G2P_NOTIFY_COBBAT_START:
		{
			Message::CombatStart msg;
			PROTOBUF_CMD_PARSER( pack, msg );

			pParam[index++].SetDataNum( pack->GetNetID() );
			
			for(int i=0; i<msg.fighter_size(); ++i)
			{
				int type = msg.fighter(i).type();
				int id = msg.fighter(i).id();
				std::string name(msg.fighter(i).name());
				int hp = msg.fighter(i).hp();
				int level = msg.fighter(i).level();
				int pos = msg.fighter(i).pos();
			}

			//LuaEngine.RunLuaFunction(handler->m_szFunc, handler->m_szUnit, NULL, pParam, index);
		}
		break;
	case G2P_NOTIFY_COMBAT_REPORT:
		{
			Message::CombatReport msg;
			PROTOBUF_CMD_PARSER( pack, msg );

			pParam[index++].SetDataNum( pack->GetNetID() );

			for(int i=0; i<msg.action_size(); ++i)
			{
				int round = msg.action(i).round();
				int attackerindex = msg.action(i).attackerindex();
				int skill = msg.action(i).skill();

				/*int defenderindex = msg.action(i).defenderindex();
				int damage = msg.action(i).damage();
				int flag = msg.action(i).flag();
				int counter = msg.action(i).counter();*/
			}

			//LuaEngine.RunLuaFunction(handler->m_szFunc, handler->m_szUnit, NULL, pParam, index);
		}
		break;
	case G2P_NOTIFY_COMBAT_RESULT:
		{
			Message::CombatResult msg;
			PROTOBUF_CMD_PARSER( pack, msg );

			pParam[index++].SetDataNum( pack->GetNetID() );
			/*if( msg.result() )
				pParam[index++].SetDataNum( TRUE );
			else
				pParam[index++].SetDataNum( FALSE );*/

			LuaEngine.RunLuaFunction(handler->m_szFunc, handler->m_szUnit, NULL, pParam, index);
		}
		break;
	case G2P_RESPONSE_NET_TEST:
		{
			Message::NetTestResponse msg;
			PROTOBUF_CMD_PARSER(pack, msg);

			pParam[index++].SetDataNum( pack->GetNetID() );
			pParam[index++].SetDataNum( msg.no() );
			pParam[index++].SetDataString( msg.sdata().c_str() );

			LuaEngine.RunLuaFunction(handler->m_szFunc, handler->m_szUnit, NULL, pParam, index);
		}
		break;
	default:
		break;
	}

	return;
}

