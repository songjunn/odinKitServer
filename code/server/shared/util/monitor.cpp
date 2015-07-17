#include "monitor.h"
#include "ThreadLib.h"

#define MONITRO_BUFFER_SIZE	40960

CMonitor::CMonitor(const char *path, data_func func) : func(func)
{
	udsvr.StartUp(path);

	ThreadLib::CreateByPool(MonitorThread, this);
}

CMonitor::~CMonitor()
{
}

void CMonitor::MonitorThread(void *param)
{
	CMonitor *pData = (CMonitor*)param;

	char output[MONITRO_BUFFER_SIZE] = {0};	

	while (true) {
		//FPS 
		sleep(1);

		if (!pData->udsvr.IsConnected()) {
			continue;
		}

		(pData->func)(output);

		pData->udsvr.SendToMonitor(1, output);	
	}
}
