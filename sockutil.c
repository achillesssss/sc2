/***********************************
 * Copyright (C) 2016 by Khoi Hoang*
 ***********************************/

/**
 * @file	socketutil.c
 * @author	Khoi Hoang
 */

#include "sockutil.h"

int tcp_sock_init()
{
	/*  
	 *  sockfd: Socket File Descriptor
	 *  AF_INET: Internet Domain IPv4
	 *  SOCK_STREAM: TCP
	 */
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("Failed to open socket");

	return sockfd;
}

int tcp_sock_serv(int portno)
{
	int sockfd = tcp_sock_init();

	/**
	 * struct sockaddr_in handles internet address
	 */
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(portno);
	addr.sin_addr.s_addr = INADDR_ANY;

	/* Attemps to bind the socket  */
	int bind_result = 
		bind(sockfd, (struct sockaddr *) &addr, sizeof(addr));
	
	if (bind_result < 0)
		error("Failed to bind");

	return sockfd;
}

int tcp_sock_accept(int serv_sockfd)
{
	/* Starts listening to server socket  */
	listen(serv_sockfd, 5);

	/* Constructs an address for client  */
	struct sockaddr_in cli_addr;
	socklen_t cli_len = sizeof(cli_addr);

	/* Blocks the process until a client is connected to server */
	int cli_sockfd =
		accept(serv_sockfd, (struct sockaddr *) &cli_addr, &cli_len);

	if (cli_sockfd < 0)
		error("Failed to accept");

	return cli_sockfd;
}

void tcp_sock_connect(int sockfd, char* hostname, int portno) 
{
	/* Resolve hostname  */
	struct hostent *serv;
	serv = gethostbyname(hostname);
	if (serv == NULL)
		error("Host not found");
	
	/* Set up address  */
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(portno);

	memcpy(&addr.sin_addr, serv->h_addr, serv->h_length);

	int connect_result =
		connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));

	if (connect_result < 0)
		error("Failed to connect");
}

void error(char* msg)
{
	perror(msg);
	exit(1);
}
