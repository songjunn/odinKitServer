#pragma once

#include "Singleton.h"
#include "Player.h"
#include <vector>
#include "MessageDebugRequest.pb.h"

class CDebugModule: public Singleton<CDebugModule>
{
public:
	CDebugModule(){}
	~CDebugModule(){}
public:
	bool OnMsg(PACKET_COMMAND* pack);
	bool _handleDebug(PACKET_COMMAND* pack);

};

#define DebugModule CDebugModule::getSingleton()
