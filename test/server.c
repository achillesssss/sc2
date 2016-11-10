#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/sockutil.h"

void handle_connection(int cli_sockfd);
void handle_arithmetic(int sockfd, int num0, int num1);

int main(int argc, char** argv)
{
	if (argc < 2) {
		puts("Missing port");
		exit(0);
	}

	int sockfd = tcp_sock_serv(atoi(argv[1]));

	puts("Server is listening to incoming connections");
	int cli_sockfd, pid;

	/* Support multiple connections  */
	while (1) {
		cli_sockfd = tcp_sock_accept(sockfd);
		pid = fork();
		if (pid < 0)
			error("Can not folk");
		else if (pid == 0){
			handle_connection(cli_sockfd);
			puts("Closing client's socket");
			close(cli_sockfd);
		} else {
			printf("Spawned a process for new connection: %d\n", pid);
			continue;
		}
	}

	puts("Closing server's socket");
	close(sockfd);
}

void handle_connection(int cli_sockfd) {
	char buffer[256];

	if (read(cli_sockfd, buffer, 255) < 0)
		error("Failed to read data");

	char* token;
	int num0, num1;

	token = strtok(buffer, " ");
	num0 = atoi(token);
	token = strtok(NULL, " ");
	num1 = atoi(token);

	handle_arithmetic(cli_sockfd, num0, num1);
}

void handle_arithmetic(int sockfd, int num0, int num1)
{
	char buffer[256];
	if (abs(num0) >= 100000 || abs(num1) >= 100000) {
		memset(buffer, '\0', 256);
		strcpy(buffer, "Abslute values of number should be smaller than 100K");
	} else if (num1 == 0) {
		memset(buffer, '\0', 256);
		sprintf(buffer, "Addition: %d\nSubtraction: %d\nMultiplication: %d\nDivision is invalid.\n", num0, num0, 0);
	} else {
		memset(buffer, '\0', 256);
		sprintf(buffer, "Addition: %d\nSubtraction: %d\nMultiplication: %d\nDivision: %f.\n", num0 + num1, num0 - num1, num0 * num1, ((double) num0) / num1);
	}
	
	if (write(sockfd, buffer, strlen(buffer)) < 0) 
		error("Failed to write");
}
