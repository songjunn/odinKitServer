#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <list>
#include <map>
#ifdef _WIN
#include <WinSock2.h>
#include <mswsock.h>
#include "mstcpip.h"
#else
#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#define LINGER linger
#include <netinet/in.h>
#ifdef FREEBSD 
#include <netinet/tcp_timer.h>
#endif
#ifdef __linux__
#include <sys/time.h>
#endif
#include <arpa/inet.h>
#include <errno.h>
#include "linux_time.h"
#endif

#include "platform.h"
#include "memory.h"
#include "Singleton.h"
#include "memorypool.h"
#include "Log.h"

