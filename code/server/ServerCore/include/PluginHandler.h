#ifndef _PLUGINHANDLER_H_
#define _PLUGINHANDLER_H_

#include "plugin_httpServe.h"

class CPluginHandler
{
public:
	CPluginHandler();
	virtual ~CPluginHandler();

	virtual void handle() {}

	//plugin httpserve handler
	virtual int httpserve_ev_handler(struct mg_connection *conn, enum mg_event ev) {}
};

#endif //_PLUGINHANDLER_H_
