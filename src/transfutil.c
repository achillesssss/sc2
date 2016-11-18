#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "transfutil.h"

void send_msg(int sockfd, char* msg){
	const int msg_len = 256;
	if(sockfd < 0)
		error("Error socket");
	int n = write(sockfd, msg, msg_len);
	if (n < 0)
		error("Error read data");
}

void rec_msg(int sockfd,char *buffer){
	const int msg_len = 256;
	int n = read(sockfd, buffer, msg_len);
	if(n < 0)
		error("Error writing data");
}