/***********************************
 * Copyright (C) 2016 by Khoi Hoang*
 ***********************************/

/**
 * @file	socketutil.h
 * @author	Khoi Hoang
 */

#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

extern const int DEFAULT_SCK_QUEUE_LEN;

/**
 * @brief	Creates an unbound socket
 * @return	int socket file descriptor (sockfd)
 */
int tcp_sock_init();

/**
 * @brief	Creates a server's socket with a port number.
 * @param	int port number	 (portno)
 * @return	int socket file descriptor (sockfd)
 */
int tcp_sock_serv(int portno);

/**
 * @brief	Establishes a client socket that connect to server.
 * @param	An integer which is the file descriptor of server's socket.
 * @return	An integer which is the file descriptor of client's socket.
 */
int tcp_sock_accept(int serv_sockfd);

/**
 * @brief	Connect the socket to server
 * @param	int socket file descriptor (sockfd)	
 * @param	string hostname
 * @prortno	int port number
 */
void tcp_sock_connect(int sockfd, char* hostname, int portno);
/**
 * @brief	Puts an error message and terminate the process
 * @param	string message
 */
void error(char* msg);

#endif	// UTIL_H
