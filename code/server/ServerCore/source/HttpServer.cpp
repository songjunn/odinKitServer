#include "HttpServer.h"
#include <stdlib.h>
#include <malloc.h>
#include "ThreadLib.h"

CHttpServer::CHttpServer()
{
}

CHttpServer::~CHttpServer()
{
}

bool CHttpServer::startup(int port, mg_handler_t handler, int threadnum)
{
	/*for (int i = 0; i < threadnum; ++i) {
		struct mg_server* httpserver = mg_create_server(NULL, handler);
		mg_set_option(httpserver, "listening_port", "8080");
		mg_start_thread(serve, httpserver);
	}*/

	struct mg_server *server = mg_create_server(NULL, handler);

	char chport[16] = {0};
	sprintf(chport, "%d", port);
	mg_set_option(server, "listening_port", chport);

	ThreadLib::Create(HttpServeThread, server);

	return true;
}

void CHttpServer::HttpServeThread(void * server)
{
	for (;;) mg_poll_server((struct mg_server *) server, 1000);
}
