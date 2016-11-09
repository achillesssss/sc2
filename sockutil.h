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

/**
 * @brief	Creates an unbound socket
 */
int tcp_sock_init();

/**
 * @brief	Establishes a server's socket with a port number.
 * @param	An integer which is the port number.
 * @return	An integer which is the file descriptor or the socket.
 */
int tcp_sock_serv();

/**
 * @brief	Establishes a client socket that connect to server.
 * @param	An integer which is the file descriptor of server's socket.
 * @return	An integer which is the file descriptor of client's socket.
 */
int tcp_sock_accept(int serv_sockfd);

/**
 * @brief	Connect the socket to server
 * @param	sockfd: Socket File Descriptor
 * @param	hostname
 * @prortno	Port number
 */
void tcp_sock_connect(int sockfd, char* hostname, int portno);
/**
 * @brief	Puts an error message and terminate the process
 * @param	A string of error message
 */
void error(char* msg);

#endif	// UTIL_H
