#ifndef _PLUGIN_HTTPSERVE_H_
#define _PLUGIN_HTTPSERVE_H_

#include "plugin.h"
#include "mongoose.h"
#include "httpd.h"

class CHttpServe : public CPlugin
{
public:
	CHttpServe();
	~CHttpServe();

	bool startup(int port, mg_handler_t handler, int threadnum = 1);

protected:
	static void _httpServeThread(void * server);

};

#endif //_PLUGIN_HTTPSERVE_H_
