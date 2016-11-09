# sockutil
C library that simplifies socket programming in C, please feel free to make a pull request!

## Usage
```
/* Open a socket and bind it with a port number in a single line */
	int sockfd = tcp_sock_init(atoi(argv[1]));

    /* Listen and accept incoming connection in a single line */
	int cli_sockfd = tcp_sock_accept(sockfd);
```

## Example
This is a very simple example where a server will establish a socket and wait for receiving a message from a client.
Server

````
/**
 * @file server.c
 */
#include "sockutil.h"

int main(int argc, char** argv)
{
	if (argc < 2) {
		puts("Missing port number");
		exit(1);
	}

	int sockfd = tcp_sock_serv(atoi(argv[1]));

	puts("Server is listening");

	int cli_sockfd = tcp_sock_accept(sockfd);

	char read_buffer[256];

	memset(read_buffer, '\0', 256);
	int byte_read = read(cli_sockfd, read_buffer, 256);
	if (byte_read < 0)
		error("Failed to read from client");

	int len = strlen(read_buffer);
	read_buffer[len - 1] = '\0';

	char* conf_msg = "Success!\n";
	int byte_write = write(cli_sockfd, conf_msg, strlen(conf_msg));
	if (byte_write < 0)
		error("Failed to write");

	printf("Received: %s\n", read_buffer);

	close(cli_sockfd);
	close(sockfd);
}
```

Client

```
/**
 * @file server.c
 */
#include "sockutil.h"

int main(int argc, char** argv)
{
	if (argc < 2) {
		puts("Missing port number");
		exit(1);
	}

	int sockfd = tcp_sock_serv(atoi(argv[1]));

	puts("Server is listening");

	int cli_sockfd = tcp_sock_accept(sockfd);

	char read_buffer[256];

	memset(read_buffer, '\0', 256);
	int byte_read = read(cli_sockfd, read_buffer, 256);
	if (byte_read < 0)
		error("Failed to read from client");

	int len = strlen(read_buffer);
	read_buffer[len - 1] = '\0';

	char* conf_msg = "Success!\n";
	int byte_write = write(cli_sockfd, conf_msg, strlen(conf_msg));
	if (byte_write < 0)
		error("Failed to write");

	printf("Received: %s\n", read_buffer);

	close(cli_sockfd);
	close(sockfd);
}
```
