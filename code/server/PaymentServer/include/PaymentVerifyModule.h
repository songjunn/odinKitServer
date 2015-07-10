#pragma once
#include "commdata.h"
#include "Singleton.h"
#include <time.h>
#include <string>

#define MG_CONN_VAR_LEN		64
#define GET_PAY_GATEID(R)	(R * 1000 + 200)

using namespace std;

struct mg_connection;
class PACKET_COMMAND;
class CPaymentVerifyModule : public Singleton< CPaymentVerifyModule >
{
public:
	CPaymentVerifyModule();
	~CPaymentVerifyModule();

	void	OnLogic();
	bool	OnMsg(PACKET_COMMAND* pack);

	bool	OnChargeFromSWServer(struct mg_connection *conn);

private:
	void	_HandlePacket_PaymentVerify(PACKET_COMMAND *pack); 
	int VerifyPayment(string postData);
	int sendPaymentVerify(string  postData);
	void getDataFromJson();
	static size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);
	void reset_data();

	bool	PayToGateServer(int gateId, int64 userId, int money);

private:
	int m_status;
	string m_productid;
	string m_transactionid;
	static string m_VerifyJson;
};

#define PaymentVerifyModule CPaymentVerifyModule::getSingleton()
