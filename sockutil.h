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
#include <unistd.h>
#include <netinet/in.h>

/**
 * @brief	Establishes a socket with a port number.
 * @param	An integer which is the port number.
 * @return	An integer which is the file descriptor or the socket.
 */
int tcp_sock_init(int portno);

/**
 * @brief	Establishes a client socket that connect to server.
 * @param	An integer which is the file descriptor of server's socket.
 * @return	An integer which is the file descriptor of client's socket.
 */
int tcp_sock_accept(int serv_sockfd);

/**
 * @brief	Puts an error message and terminate the process
 * @param	A string of error message
 */
void error(char* msg);

#endif	// UTIL_H
