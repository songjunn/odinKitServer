#include "Plugin_HttpServe.h"
#include <stdlib.h>
#include <malloc.h>
#include "ThreadLib.h"

CHttpServe::CHttpServe()
{
}

CHttpServe::~CHttpServe()
{
}

bool CHttpServe::startup(int port, int threadnum)
{
	char cport[16] = { 0 };
	sprintf(cport, "%d", port);

	for (int i = 0; i < threadnum; ++i) {
		struct mg_server *server = mg_create_server(NULL, m_handler->httpserve_ev_handler);
		mg_set_option(server, "listening_port", cport);

		ThreadLib::Create(_httpServeThread, server);
	}
	return true;
}

void CHttpServe::_httpServeThread(void * server)
{
	for (;;) mg_poll_server((struct mg_server *) server, 1000);
}
