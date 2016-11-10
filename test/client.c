#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/sockutil.h"

int main(int argc, char** argv)
{
	if (argc < 3) {
		puts("Missing host and port");
		exit(0);
	}

	int sockfd = tcp_sock_init();

	tcp_sock_connect(sockfd, argv[1], atoi(argv[2]));

	char buffer[256];
	puts("Connection is ready, put two integers below");
	fgets(buffer, 256, stdin);

	if (write(sockfd, buffer, strlen(buffer)) < 0)
		error("Failed to write data");

	memset(buffer, '\0', 256);
	if (read(sockfd, buffer, 256) < 0)
		error("Failed to get results");
	puts(buffer);

	close(sockfd);
}
