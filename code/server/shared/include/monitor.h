#ifndef _MONITOR_H_
#define _MONITOR_H_

#include "udsvr.h"

class CMonitor
{
public:
	typedef void (*data_func)( char *output );

	CMonitor(const char *path, data_func func);
	virtual ~CMonitor();

protected:
	static void MonitorThread(void *param);
	
public:
	CUnixDomainServer udsvr;
	data_func func;

};

#endif	//_MONITOR_H_
