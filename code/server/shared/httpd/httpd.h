#ifndef _HTTPD_H_
#define _HTTPD_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// This structure contains information about HTTP request.
struct httpd_request {
	const char *method;         // "GET", "POST", etc
	const char *uri;            // URL-decoded URI
	const char *version;        // E.g. "1.0", "1.1"
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
};

void httpd_thread(void* param);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_HTTPD_H_
