#include<stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include<time.h>
#include <stddef.h>
#include <pthread.h>

#define SERVPORT 3333 //端口号
#define MAXDATASIZE 100 /*每次最大数据传输量 */

int main(int argc, char *argv[]){
	
	int sockfd1;
    int numbytes;
		char info[70];
	char buf[MAXDATASIZE];

    time_t *timep = malloc(sizeof(*timep));
	time(timep);
   	char *s = ctime(timep);
	struct hostent *host;
	struct sockaddr_in serv_addr;

	if (argc < 2) {
		fprintf(stderr,"Please enter the server's hostname!\n");
		exit(1);
	}
	if((host=gethostbyname(argv[1]))==NULL) {
		herror("gethostbyname error！");
		exit(1);
	}
	if ((sockfd1 = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("socket create error！");
		exit(1);
	}
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(SERVPORT);
	serv_addr.sin_addr = *((struct in_addr *)host->h_addr);
	bzero(&(serv_addr.sin_zero),8);

	if (connect(sockfd1, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr)) == -1) {
		perror("connect error！");
		exit(1);
	}

	//sprintf(info,"%s %s",inet_ntoa(serv_addr.sin_addr),s);

	if (send(sockfd1, s, 26, 0) == -1)
	{
			perror("send 出错！");
			close(sockfd1);
			exit(0);
	}

	if ((numbytes=recv(sockfd1,buf,MAXDATASIZE,0)) == -1)
	{ 
    printf("recv() error\n"); 
    exit(1); 
    } 
	else
	{	
		printf("%s\n",buf);
		close(sockfd1);
		return 0;
	}

}

