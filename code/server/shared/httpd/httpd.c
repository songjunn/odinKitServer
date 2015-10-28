#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <strings.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "ThreadLib.h"
#include "httpd.h"

#define ISspace(x) isspace((int)(x))

#define SERVER_STRING "Server: httpd/0.1.0\r\n"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

enum http_error {
	HTTP_ERROR_BAD_REQUEST = 400,
	HTTP_ERROR_NOT_FOUND = 404,
	HTTP_ERROR_INTERNAL_SERVER_ERROR = 500,
	HTTP_ERROR_METHOD_NOT_IMPLEMENTED = 501,
};

int start_net(int port);
void worker_thread(void* param);
int get_line(int sock, char *buf, int size);
void handle_request_cgi(int client, const char *path, const char *method, const char *query_string);
void handle_request_file(int client, const char *filename);
void send_file(int client, FILE *resource);
void send_headers_ok(int client);
void send_headers_err(int client, int error);

#ifdef __cplusplus
}
#endif // __cplusplus

/**********************************************************************/
/* A request has caused a call to accept() on the server port to
 * return.  Process the request appropriately.
 * Parameters: the socket connected to the client */
/**********************************************************************/
void worker_thread(void* param)
{
	char buf[1024], method[255], url[255], path[512];
    int numchars, cgi = 0;
    size_t i = 0, j = 0;
    struct stat st;
    char *query_string = NULL;
    int client = *(int *)param;

    numchars = get_line(client, buf, sizeof(buf));
    while (!ISspace(buf[j]) && (i < sizeof(method) - 1)) {
        method[i] = buf[j];
        i++; j++;
    }
    method[i] = '\0';

    if (strcasecmp(method, "GET") && strcasecmp(method, "POST")) {
		send_headers_err(client, HTTP_ERROR_METHOD_NOT_IMPLEMENTED);
        return;
    }

	if (strcasecmp(method, "POST") == 0) {
		cgi = 1;
	}

    i = 0;
	while (ISspace(buf[j]) && (j < sizeof(buf))) {
		j++;
	}
    while (!ISspace(buf[j]) && (i < sizeof(url) - 1) && (j < sizeof(buf))) {
        url[i] = buf[j];
        i++; j++;
    }
    url[i] = '\0';

    //if (strcasecmp(method, "GET") == 0) 
	{
        query_string = url;
		while ((*query_string != '?') && (*query_string != '\0')) {
			query_string++;
		}
        if (*query_string == '?') {
            cgi = 1;
            *query_string = '\0';
            query_string++;
        }
    }

	printf("httpd recv request: %s\n", url);
	printf("httpd recv query: %s\n", query_string);

    /*sprintf(path, "htdocs%s", url);
	if (path[strlen(path) - 1] == '/') {
		strcat(path, "index.html");
	}
    if (stat(path, &st) == -1) {
        while ((numchars > 0) && strcmp("\n", buf))  // read & discard headers
            numchars = get_line(client, buf, sizeof(buf));
		send_headers_err(client, HTTP_ERROR_NOT_FOUND);
    } else {
        if ((st.st_mode & S_IFMT) == S_IFDIR)
            strcat(path, "/index.html");
        if ((st.st_mode & S_IXUSR) ||
            (st.st_mode & S_IXGRP) ||
            (st.st_mode & S_IXOTH))
            cgi = 1;
        if (!cgi)
            handle_request_file(client, path);
        else
            handle_request_cgi(client, path, method, query_string);
    }*/

    close(client);
}

/**********************************************************************/
/* Get a line from a socket, whether the line ends in a newline,
* carriage return, or a CRLF combination.  Terminates the string read
* with a null character.  If no newline indicator is found before the
* end of the buffer, the string is terminated with a null.  If any of
* the above three line terminators is read, the last character of the
* string will be a linefeed and the string will be terminated with a
* null character.
* Parameters: the socket descriptor
*             the buffer to save the data in
*             the size of the buffer
* Returns: the number of bytes stored (excluding null) */
/**********************************************************************/
int get_line(int sock, char *buf, int size)
{
	int n, i = 0;
	char c = '\0';

	while ((i < size - 1) && (c != '\n')) {
		n = recv(sock, &c, 1, 0);
		if (n > 0) {
			if (c == '\r') {
				n = recv(sock, &c, 1, MSG_PEEK);
				if ((n > 0) && (c == '\n'))
					recv(sock, &c, 1, 0);
				else
					c = '\n';
			}
			buf[i] = c;
			i++;
		}
		else {
			c = '\n';
		}
	}
	buf[i] = '\0';

	return i;
}

/**********************************************************************/
/* Execute a CGI script.  Will need to set environment variables as
 * appropriate.
 * Parameters: client socket descriptor
 *             path to the CGI script */
/**********************************************************************/
void handle_request_cgi(int client, const char *path,
                 const char *method, const char *query_string)
{
    char c, buf[1024];
	int cgi_input[2], cgi_output[2];
	int i, status, numchars = 1, content_length = -1;
	pid_t pid;

    buf[0] = 'A'; buf[1] = '\0';
	if (strcasecmp(method, "GET") == 0) {
		while ((numchars > 0) && strcmp("\n", buf))  /* read & discard headers */
			numchars = get_line(client, buf, sizeof(buf));
	} else {   /* POST */
        numchars = get_line(client, buf, sizeof(buf));
        while ((numchars > 0) && strcmp("\n", buf)) {
            buf[15] = '\0';
            if (strcasecmp(buf, "Content-Length:") == 0)
                content_length = atoi(&(buf[16]));
            numchars = get_line(client, buf, sizeof(buf));
        }
        if (content_length == -1) {
			send_headers_err(client, HTTP_ERROR_BAD_REQUEST);
            return;
        }
    }

    sprintf(buf, "HTTP/1.0 200 OK\r\n");
    send(client, buf, strlen(buf), 0);

    if (pipe(cgi_output) < 0) {
		send_headers_err(client, HTTP_ERROR_INTERNAL_SERVER_ERROR);
        return;
    }
    if (pipe(cgi_input) < 0) {
		send_headers_err(client, HTTP_ERROR_INTERNAL_SERVER_ERROR);
        return;
    }

    if ((pid = fork()) < 0) {
		send_headers_err(client, HTTP_ERROR_INTERNAL_SERVER_ERROR);
        return;
    }
    if (pid == 0) { /* child: CGI script */
        char meth_env[255];
        char query_env[255];
        char length_env[255];

        dup2(cgi_output[1], 1);
        dup2(cgi_input[0], 0);
        close(cgi_output[0]);
        close(cgi_input[1]);
        sprintf(meth_env, "REQUEST_METHOD=%s", method);
        putenv(meth_env);
		if (strcasecmp(method, "GET") == 0) {
			sprintf(query_env, "QUERY_STRING=%s", query_string);
			putenv(query_env);
		} else {   /* POST */
            sprintf(length_env, "CONTENT_LENGTH=%d", content_length);
            putenv(length_env);
        }
        execl(path, path, NULL);
        exit(0);
    } else {    /* parent */
        close(cgi_output[1]);
        close(cgi_input[0]);
	    if (strcasecmp(method, "POST") == 0) {
		    for (i = 0; i < content_length; i++) {
		 	    recv(client, &c, 1, 0);
			    write(cgi_input[1], &c, 1);
		    }
	    }
	    while (read(cgi_output[0], &c, 1) > 0) {
		    send(client, &c, 1, 0);
	    }

        close(cgi_output[0]);
        close(cgi_input[1]);
        waitpid(pid, &status, 0);
    }
}

/**********************************************************************/
/* Send a regular file to the client.  Use headers, and report
* errors to client if they occur.
* Parameters: a pointer to a file structure produced from the socket
*              file descriptor
*             the name of the file to serve */
/**********************************************************************/
void handle_request_file(int client, const char *filename)
{
	FILE *resource = NULL;
	int numchars = 1;
	char buf[1024];

	buf[0] = 'A'; buf[1] = '\0';
	while ((numchars > 0) && strcmp("\n", buf))  /* read & discard headers */
		numchars = get_line(client, buf, sizeof(buf));

	resource = fopen(filename, "r");
	if (resource == NULL) {
		send_headers_err(client, HTTP_ERROR_NOT_FOUND);
	} else {
		send_headers_ok(client);
		send_file(client, resource);
	}
	fclose(resource);
}

/**********************************************************************/
/* Put the entire contents of a file out on a socket.  This function
* is named after the UNIX "cat" command, because it might have been
* easier just to do something like pipe, fork, and exec("cat").
* Parameters: the client socket descriptor
*             FILE pointer for the file to cat */
/**********************************************************************/
void send_file(int client, FILE *resource)
{
	char buf[1024];

	fgets(buf, sizeof(buf), resource);
	while (!feof(resource)) {
		send(client, buf, strlen(buf), 0);
		fgets(buf, sizeof(buf), resource);
	}
}

/**********************************************************************/
/* Return the informational HTTP headers. */
/* Parameters: the socket to print the headers on */
/**********************************************************************/
void send_headers_ok(int client)
{
    char buf[1024];
    sprintf(buf, "HTTP/1.0 200 OK\r\n");
    send(client, buf, strlen(buf), 0);
	sprintf(buf, SERVER_STRING);
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "Content-Type: text/html\r\n");
    send(client, buf, strlen(buf), 0);
	sprintf(buf, "\r\n");
    send(client, buf, strlen(buf), 0);
}

/**********************************************************************/
/* Return the error HTTP headers. */
/* Parameters: the socket to print the headers on 
/*             the error number */
/**********************************************************************/
void send_headers_err(int client, int error)
{
    char buf[1024];
    sprintf(buf, "HTTP/1.0 %d\r\n", error);
    send(client, buf, strlen(buf), 0);
    sprintf(buf, SERVER_STRING);
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "Content-Type: text/html\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "\r\n");
    send(client, buf, strlen(buf), 0);
}

/**********************************************************************/
/* This function starts the process of listening for web connections
 * on a specified port.  If the port is 0, then dynamically allocate a
 * port and modify the original port variable to reflect the actual
 * port.
 * Parameters: pointer to variable containing the port to connect on
 * Returns: the socket */
/**********************************************************************/
int start_net(int port)
{
    int httpd = 0;
    struct sockaddr_in name;

    httpd = socket(PF_INET, SOCK_STREAM, 0);
	if (httpd == -1) {
		printf("httpd create socket error\n");
		return -1;
	}

    memset(&name, 0, sizeof(name));
    name.sin_family = AF_INET;
    name.sin_port = htons(port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    
	if (bind(httpd, (struct sockaddr *)&name, sizeof(name)) < 0) {
		printf("httpd bind socket error\n");
		return -1;
	}

	if (listen(httpd, SOMAXCONN) < 0) {
		printf("httpd listen socket error\n");
		return -1;
	}

    return httpd;
}

/**********************************************************************/
void httpd_thread(void* param) 
{
    int server_sock = -1;
    int client_sock = -1;
    int port = *(int *)param;
    struct sockaddr_in client_name;
    socklen_t client_name_len = sizeof(client_name); 

    server_sock = start_net(port);
	if (server_sock == -1) {
		printf("httpd start net failed\n");
		return;
	}
    printf("httpd running on port %d\n", port);

	while (1) {
		client_sock = accept(server_sock,
			(struct sockaddr *)&client_name,
			&client_name_len);

		if (client_sock == -1) {
			printf("httpd accept socket error\n");
			continue;
		}

		//if (pthread_create(&workthread, NULL, worker_thread, (void*)&client_sock) != 0) {
                if (ThreadLib::Create(worker_thread, (void*)&client_sock) == 0) {
			printf("httpd create thread error\n");
			continue;
		}
	}

	close(server_sock);
}
