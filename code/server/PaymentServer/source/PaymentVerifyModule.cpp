#include "PaymentVerifyModule.h"
#include "MainServer.h"
#include "PacketDefine.h"
#include "Log.h"
#include "Packet.h"
#include "MessagePayment.pb.h"
#include "HttpServer.h"
#include "ServerMgr.h"
#include "utlMD5.h"
#include "strtools.h"
#include "json/json.h"
#include <curl/curl.h>
#include "MessageSWChargeChecker.pb.h"

#define IAP_RECEIPT		"receipt"
#define IAP_PRODUCTID 	"product_id"
#define IAP_TRANSACTIONID "transaction_id"
#define IAP_STATUS		"status"

using namespace std;

const int buff_size = 4096;

string CPaymentVerifyModule::m_VerifyJson = "";
CPaymentVerifyModule::CPaymentVerifyModule()
{
}
CPaymentVerifyModule::~CPaymentVerifyModule()
{
}

void	CPaymentVerifyModule::OnLogic()
{
}

bool	CPaymentVerifyModule::OnMsg(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	switch( pack->Type() )
	{
	case P2G_REQUEST_PAYMENT_VERIFY:	_HandlePacket_PaymentVerify(pack);	break;
	default:	return false;
	}

	return true;
}

bool CPaymentVerifyModule::OnChargeFromSWServer(struct mg_connection *conn)
{
	if (conn == NULL) {
		return false;
	}

	char orderNo[MG_CONN_VAR_LEN] = { 0 };
	char gameId[MG_CONN_VAR_LEN] = { 0 };
	char guid[MG_CONN_VAR_LEN] = { 0 };
	char money[MG_CONN_VAR_LEN] = { 0 };
	char coins[MG_CONN_VAR_LEN] = { 0 };
	char coinMes[MG_CONN_VAR_LEN] = { 0 };
	char time[MG_CONN_VAR_LEN] = { 0 };
	char gateRegion[MG_CONN_VAR_LEN] = { 0 };
	char swUserId[MG_CONN_VAR_LEN] = { 0 };
	char sign[MG_CONN_VAR_LEN] = { 0 };

	mg_get_var(conn, "orderNo", orderNo, MG_CONN_VAR_LEN);
	mg_get_var(conn, "gameId", gameId, MG_CONN_VAR_LEN);
	mg_get_var(conn, "guid", guid, MG_CONN_VAR_LEN);
	mg_get_var(conn, "money", money, MG_CONN_VAR_LEN);
	mg_get_var(conn, "coins", coins, MG_CONN_VAR_LEN);
	mg_get_var(conn, "coinMes", coinMes, MG_CONN_VAR_LEN);
	mg_get_var(conn, "time", time, MG_CONN_VAR_LEN);
	mg_get_var(conn, "gateRegion", gateRegion, MG_CONN_VAR_LEN);
	mg_get_var(conn, "swUserId", swUserId, MG_CONN_VAR_LEN);
	mg_get_var(conn, "sign", sign, MG_CONN_VAR_LEN);

	int gateSrvId = GET_PAY_GATEID(atoi(gateRegion));
	if (!ServerMgr.GetServerById(gateSrvId)) {
	//if (!GameWorldMgr.IsConnGate(gateSrvId)) {
		Log.Error("Wrong gate: %d. User: %s, orderNo: %s, money: %s, coins %s, time: %s", gateSrvId, swUserId, orderNo, money, coins, time);
		return false;
	}

	//白名单校验
	//...

	//md5校验
	char *sign_key = "52146953";
	char signStr[512] = { 0 };
	char tmpsign[512] = { 0 };
	if (coinMes[0] == 0) { //coinMes可能为0
		sprintf(signStr, "%s|%s|%s|%s|%s|%s|%s|%s|%s", coins, gameId, gateRegion, guid, money, orderNo, swUserId, time, sign_key);
	}
	else {
		sprintf(signStr, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s", coinMes, coins, gameId, gateRegion, guid, money, orderNo, swUserId, time, sign_key);
	}
	unsigned char digest[16];
	CUtlMD5 md5Tool;
	md5Tool.MDString(signStr, digest);
	for (int di = 0; di < 16; ++di) {
		sprintf(tmpsign + di * 2, "%02x", digest[di]);
	}
	memset(signStr, 0, sizeof(signStr));
	strnupper(tmpsign, signStr, strlen(tmpsign));
	
	if (strcmp(sign, signStr) != 0) { //md5校验失败
		UrlEncode((unsigned char *)signStr, (unsigned char *)tmpsign, strlen(signStr));
		if (strcmp(sign, tmpsign) != 0) {
			Log.Error("md5 check wrong. User: %s, orderNo: %s, money: %s, coins %s, time: %s", swUserId, orderNo, money, coins, time);
			Log.Error("md5 sign remote: %s, local1: %s, local2: %s", sign, signStr, tmpsign);
			return false;
		}
	}

	Log.Notice("sw_check success. orderNo: %s, userid: %s, guid: %s, gateRegion: %s, money: %s, coins: %s, time: %s",
		orderNo, swUserId, guid, gateRegion, money, coins, time);

	return PayToGateServer(gateSrvId, atoll(swUserId), atoi(money));
}

void	CPaymentVerifyModule::_HandlePacket_PaymentVerify(PACKET_COMMAND *pack)
{
	if( !pack )
		return ;

	Log.Debug("%s: perform begin ", __func__);
	Message::PaymentVerifyRequest rmsg;
	PROTOBUF_CMD_PARSER( pack, rmsg );

	PersonID  pid = rmsg.playerid();
	string receipt = rmsg.receiptdata();
	int ret = VerifyPayment(receipt);
	
	Message::PaymentVerifyResponse wmsg;
	wmsg.set_player_id(pid);
	wmsg.set_result(ret);
	if (!m_productid.empty()) {
		wmsg.set_product_id(m_productid);
		wmsg.set_transaction_id(m_transactionid);
	}

	PACKET_COMMAND wpack;
	PROTOBUF_CMD_PACKAGE( wpack, wmsg, T2G_RESPONSE_PAYMENT_VERIFY);
	MainServer.SendMsgToServer( pack->GetNetID(), &wpack );
}

int CPaymentVerifyModule::VerifyPayment(string receipt)
{
	Json::Value item;
	Json::FastWriter  writer;
	item["receipt-data"] = receipt;
	string postData = writer.write(item);

	reset_data();
	int ret = sendPaymentVerify(postData);
	if (ret != 0) {
	  	return ret;
	}
	getDataFromJson();
	Log.Debug("get payment verify json: %s", m_VerifyJson.c_str());	
	if (m_status != 0) {
		return m_status;
	}

	return ret;
}

int CPaymentVerifyModule::sendPaymentVerify(string postData)
{
	const char *url = "https://sandbox.itunes.apple.com/verifyReceipt";
	char err_msg[CURL_ERROR_SIZE] = "";

	CURL* easy_handle = curl_easy_init();
	curl_easy_setopt(easy_handle, CURLOPT_URL, url);
	curl_easy_setopt(easy_handle, CURLOPT_POST, true);
	curl_easy_setopt(easy_handle, CURLOPT_POSTFIELDS, postData.c_str());
	curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(easy_handle, CURLOPT_ERRORBUFFER, err_msg);
	int return_code = curl_easy_perform(easy_handle);
	int ret_state = 0;

	do {
		Log.Debug("%s: perform begin ", __func__);
		return_code = curl_easy_perform(easy_handle);
		Log.Debug("%s: perform end ", __func__);

		long code = 0;
		curl_easy_getinfo(easy_handle, CURLINFO_RESPONSE_CODE, &code);

		if (return_code != CURLE_OK) {
			Log.Error("download file(%s) failed return_code=%d code=%ld msg=%s", url, return_code, code, err_msg);
			ret_state = -1;
			break;
		}

		if (code == 200 || code == 304 || code == 204 || code == 206) {
			Log.Debug("download file(%s) success return_code=%d code=%ld msg=%s", url, return_code, code);
			break;
		} else if ( code == 404) {
			Log.Notice("download file(%s) failed return_code=%d code=%ld msg=%s", url, return_code, code, err_msg);
			ret_state = -1;
			break;
		} else {
			Log.Notice("download file(%s) failed return_code=%d code=%ld", url, return_code, code, err_msg);
			ret_state = -1;
		}
	}while(0);
	
	curl_easy_cleanup(easy_handle);
	return ret_state;
}

size_t CPaymentVerifyModule::write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
	char temp[buff_size+1] = "";
	int get_size = buff_size > size*nmemb ? size*nmemb : buff_size;
	memcpy(temp, ptr, get_size);
	m_VerifyJson += temp;
	Log.Debug("%s: iap verify get response,%s", __func__, temp);
	return get_size;
}

void CPaymentVerifyModule::reset_data()
{
	m_VerifyJson = "";
	m_productid = "";	
	m_transactionid = "";
}

void CPaymentVerifyModule::getDataFromJson()
{
	Json::Reader reader;
	Json::Value root;
	if (reader.parse(m_VerifyJson, root))
	{                                                                                           
		Log.Debug("%s", root[IAP_RECEIPT][IAP_PRODUCTID].asString().c_str());
		m_productid = root[IAP_RECEIPT][IAP_PRODUCTID].asString();
		m_transactionid = root[IAP_RECEIPT][IAP_TRANSACTIONID].asString();
		m_status = root[IAP_STATUS].asInt();
	}                                                                                           
}

bool CPaymentVerifyModule::PayToGateServer(int gateId, int64 userId, int money)
{
	if (userId < 1 || money < 1) {
		return false;
	}

	//SOCKET gsocket = GameWorldMgr.GetGateSocket(gateId);
	CServerObj* server = ServerMgr.GetServerById(gateId);
	if (!server || server->m_Socket == INVALID_SOCKET) {
		Log.Error("PayToGateServer Invalid socket. user: %lld, gate: %d, money: %d", userId, gateId, money);
		return false;
	}

	Message::SWChargeChecker msg;
	msg.set_userid(userId);
	msg.set_money(money);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, S2S_NOTIFY_SWCHARGE);
	MainServer.SendMsgToServer(server->m_Socket, &pack);

	Log.Notice("PayToGateServer Success. user: %lld, money: %d, gateId: %d", userId, money, gateId);

	return true;
}
