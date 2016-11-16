#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "transfutil.h"

void send_msg(int sockfd, char* msg){
	if(sockfd < 0)
		error("Error socket");
	int n = write(sockfd,msg,256);
	if (n < 0)
		error("Error read data");
}

void error(char* msg)
{
	perror(msg);
	exit(1);
}
