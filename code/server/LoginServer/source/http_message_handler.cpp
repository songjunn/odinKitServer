#include "http_message_handler.h"
#include "sqlite3.h"
#include "Log.h"

static int httpserver_ev_handler(struct httpd_request *conn, enum httpd_event ev) {
	if (ev == HTTP_REQUEST) {
		//Log.Debug("[HttpServer]Handle Event:%d ip:%s", ev, conn->remote_ip);

		char action[8], platform[8], guest[128];
		httpd_get_post_var(conn, "action", action, sizeof(action));
		httpd_get_post_var(conn, "platform", platform, sizeof(platform));
		httpd_get_post_var(conn, "guest", guest, sizeof(guest));

		if (action == "1" && platform == "0") {
			auth_verify_from_mydb_by_client(guest);
		}
		else if (action == 2) {
			//auth_verify_from_mydb_by_gate
		}

		/*if (true) {
			httpd_send_data(conn, "0", 1);
		}
		else {
			httpd_send_data(conn, "1", 1);
		}*/
		return 0;
	}
	else {
		return 1;
	}
}

void auth_verify_from_mydb_by_client(std::string guest)
{
	int ret, row, col;
	sqlite3 *db = NULL;
	char *errmsg = NULL, **result;
	std::string sql;

	ret = sqlite3_open("./auth.db", &db);
	if (ret != SQLITE_OK) {
		Log.Error("auth_verify_from_mydb_by_client open error: %s", sqlite3_errmsg(db));
		goto QUIT;
	}

	sql = "select * from guest where name='" + guest + "'";
	ret = sqlite3_get_table(db, sql.c_str(), &result, &row, &col, &errmsg);
	if (ret != SQLITE_OK) {
		Log.Error("auth_verify_from_mydb_by_client get table error: %s", sqlite3_errmsg(db));
		goto QUIT;
	}

QUIT:
	if (db) sqlite3_close(db);
	if (errmsg) sqlite3_free(errmsg);
}

void auth_verify_from_mydb_by_gate(int64 userid, std::string accesstoken)
{

}
