#ifndef _PLUGIN_NETWORK_H_
#define _PLUGIN_NETWORK_H_

#include "plugin.h"
#include "Net.h"

class CNetwork : public CPlugin, public CNet
{
public:
	CNetwork();
	~CNetwork();

	bool startup(int type, int port, int connectmax, int sendbuffsize, int recvbuffsize, int packsize);
	virtual SOCKET connect(const char * ip, int port);
	virtual SOCKET connectAsync(const char * ip, int port);
	virtual bool shutdown(SOCKET sock);
	virtual int	sendMsg(SOCKET sock, PACKET_COMMAND* pack);
	virtual bool accept(SOCKET sock, const char* ip);
	virtual void close(SOCKET sock);
	virtual bool handlePacket(PACKET_COMMAND * pCmd);

private:
	void _closeReturn(SOCKET sock);
	void _acceptReturn(SOCKET sock);
	void _connectReturn(SOCKET sock, int error = 0);

private:
	int m_type;

};

#endif //_PLUGIN_NETWORK_H_
