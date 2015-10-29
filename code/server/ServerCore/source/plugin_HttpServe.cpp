#include "plugin_HttpServe.h"
#include <stdlib.h>
#include "memory.h"
#include "ThreadLib.h"
#include "httpd.h"

CHttpServe::CHttpServe()
{
}

CHttpServe::~CHttpServe()
{
}

bool CHttpServe::startup(int port, mg_handler_t handler, int threadnum)
{
	/*char cport[16] = { 0 };
	sprintf(cport, "%d", port);

	for (int i = 0; i < threadnum; ++i) {
		struct mg_server *server = mg_create_server(NULL, handler);
		mg_set_option(server, "listening_port", cport);

		ThreadLib::Create(_httpServeThread, server);
	}*/

	struct httpd_server* server = httpd_create_server(port, handler);
	ThreadLib::Create(httpd_thread, server);
	return true;
}

void CHttpServe::_httpServeThread(void * server)
{
	for (;;) mg_poll_server((struct mg_server *) server, 1000);
}
