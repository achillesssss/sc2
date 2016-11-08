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
This is a very simple example where a server will establish a socket and wait for receiving a message from a client (telnet).
````
/**
 * @file    server.c
 */
#include <string.h>
#include "sockutil.h"

int main(int argc, char** argv)
{
	if (argc < 2) {
		puts("Missing port number");
		exit(1);
	}

	int sockfd = tcp_sock_init(atoi(argv[1]));

	puts("Now waiting for incoming connection");
	int cli_sockfd = tcp_sock_accept(sockfd);

	char buffer[256];
	int byte_read = read(cli_sockfd, buffer, 256);
	if (byte_read < 0)
		error("Failed to read");
	char message[256] = "Tranmission is sent\n";

	int byte_write = write(cli_sockfd, message, strlen(message));
	if (byte_write < 0)
		error("Failed to write");

	printf("Received: %s\n", buffer);

	close(cli_sockfd);
	close(sockfd);
}
````
Output
```
ttys001
$ ./server 8888
Now waiting for incoming tramission
```

```
ttys002
telnet localhost 8888
> Hello sockutil!
Tranmission is sent
```

```
ttys001
Received: Hello sockutil!
```
