#ifndef _PLUGIN_HTTPSERVE_H_
#define _PLUGIN_HTTPSERVE_H_

#include "Plugin.h"
#include "mongoose.h"

class CHttpServe : public CPlugin
{
public:
	CHttpServe();
	~CHttpServe();

	bool startup(int port, int threadnum = 1);

protected:
	static void _httpServeThread(void * server);

};

#endif //_PLUGIN_HTTPSERVE_H_
