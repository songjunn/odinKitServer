#ifndef _GATESERVER_H_
#define _GATESERVER_H_

#include "server.h"

class CGateServer : public CBaseServer
{
public:
	CGateServer();
	~CGateServer();

	virtual bool onInit();
	virtual bool onMessage(PACKET_COMMAND* pack);
	virtual bool onLogic();
	virtual void onPrint();
	virtual void output(char* output);
};

#endif //_GATESERVER_H_
