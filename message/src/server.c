#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*#include <sys/socket.h>*/
#include <netinet/in.h>		// For some structs related to socket
#include <unistd.h>		// For close and read & write

/**
 * Handles and displays error message
 */
void error(char* mes) {
	perror(mes);
	exit(-1);
}

int main(int argc, char** argv)
{
	/* If no port number is provided  */
	if (argc < 2) {
		fputs("Missing port number!\n", stderr);
		exit(1);
	}

	/*
	 * Create a new socket from sys/socket.h
	 * scoketfd = socket file descriptor
	 * AF_INET: address family IPv4
	 * SOCK_STREAM: TCP
	 */
	int socketfd = socket(AF_INET, SOCK_STREAM, 0);

	/* The socket file descritor will be negative
	 * If there was something wrong in opening the socket
	 */
	if (socketfd < 0) 
		error("ERROR on opening socket");

	int portno = atoi(argv[1]);

	/*
	 * struct sockaddr_in handles internet addresses
	 * sin_family: Address Domain = IPv4
	 * sin_port: Port number
	 * sin_addr.s_addr = INADDR_ANY: receive all connections
	 */
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portno);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	/**
	 * Assign a local socket address to a socket identified by a
	 * file descriptor
	 */
	int bind_result = bind(socketfd, (struct sockaddr*) &serv_addr,
			sizeof(serv_addr));
	if (bind_result < 0)
		error("ERROR on binding");

	/*
	 * Starts listening, with maximum 5 connections in
	 * the waiting queue
	 */
	puts("Server is now listening");
	listen(socketfd, 5);

	/*
	 * Extract the first connection in a waiting queue and create another
	 * socket that has the same attributes
	 */
	struct sockaddr_in cli_addr;
	socklen_t clilen = sizeof(cli_addr);
	int client_socketfd = 
		accept(socketfd, (struct sockaddr*) &cli_addr, &clilen);

	if (client_socketfd < 0)
		error("ERROR on accepting");

	char message[256];
	int byte_read = read(client_socketfd, message, 256);
	if (byte_read < 0) 
		error("ERROR on reading from client's socket");
	printf("Incoming transmission: %s\n", message);

	int byte_write = write(client_socketfd,
			"OK\n", 3);
	if (byte_write < 0)
		error("ERROR on writing");

	/* Close sockets  */
	close(client_socketfd);
	close(socketfd);
}
