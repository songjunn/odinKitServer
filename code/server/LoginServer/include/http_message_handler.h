#include "httpd.h"
#include <string>
#include "platform.h"

static int httpserver_ev_handler(struct httpd_request *conn, enum httpd_event ev);

// guest login, for my db
void auth_verify_from_mydb_by_client(std::string guest);
void auth_verify_from_mydb_by_gate(int64 userid, std::string accesstoken);