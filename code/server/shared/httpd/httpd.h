#ifndef _HTTPD_H_
#define _HTTPD_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// This structure contains information about HTTP request.
struct http_request {
	const char *method;         // "GET", "POST", etc
	const char *uri;            // URL-decoded URI
	const char *version;        // E.g. "1.0", "1.1"
	const char *query_string;   // URL part after '?', not including '?', or NULL

	char remote_ip[48];         // Max IPv6 string length is 45 characters
	unsigned short remote_port; // Client's port

	struct http_header {
		const char *name;         // HTTP header name
		const char *value;        // HTTP header value
	} headers[30];
	unsigned short num_headers; // Number of HTTP headers

	char *body;                 // POST data, or NULL
	size_t body_len;            // Data length

	int status_code;            // HTTP status code for HTTP error handler
};

void httpd_thread(void* param);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_HTTPD_H_
