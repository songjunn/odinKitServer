#ifndef _HTTPSERVER_H_
#define _HTTPSERVER_H_

#include "mongoose.h"

class CHttpServer
{
public:
	CHttpServer();
	~CHttpServer();

	bool startup(int port, mg_handler_t handler, int threadnum = 0);
	static void HttpServeThread(void * server);

};

#endif //_HTTPSERVER_H_
