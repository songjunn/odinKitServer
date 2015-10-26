#ifndef _HTTPD_H_
#define _HTTPD_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// This structure contains information about HTTP request.
struct httpd_request {
	const char *request_method; // "GET", "POST", etc
	const char *uri;            // URL-decoded URI
	const char *http_version;   // E.g. "1.0", "1.1"
	const char *query_string;   // URL part after '?', not including '?', or NULL

	char remote_ip[48];         // Max IPv6 string length is 45 characters
	unsigned short remote_port; // Client's port

	int num_headers;            // Number of HTTP headers
	struct mg_header {
		const char *name;         // HTTP header name
		const char *value;        // HTTP header value
	} http_headers[30];

	char *content;              // POST (or websocket message) data, or NULL
	size_t content_len;         // Data length

	int is_websocket;           // Connection is a websocket connection
	int status_code;            // HTTP status code for HTTP error handler
	int wsbits;                 // First byte of the websocket frame
	void *server_param;         // Parameter passed to mg_create_server()
	void *connection_param;     // Placeholder for connection-specific data
	void *callback_param;
};

void httpd_thread(void* param);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_HTTPD_H_
