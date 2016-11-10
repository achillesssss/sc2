#ifndef TRANSFUTIL_H
#define TRANSFUTIL_H

/**
 * @brief	Send a quick message to server
 * @param	int sockfd socket's file descriptor
 * @param	string message
 */
void send_msg(int sockfd, char* msg);

/**
 * @brief	Get quick message
 * @param	int socket's file descriptor
 * @return	string the message
 */
char* rec_msg(int sockfd);

/**
 * @brief	Send binary data.
 * @param	int sockfd socket's file descriptor
 * @param	string filename
 */
void send_blob(int sockfd, char* filename);

#endif	// TRANSFUTIL_H
