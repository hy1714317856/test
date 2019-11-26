#include "my.h"

int main(){
	pid_t p;
	char w_buf[100],r_buf[100];
	int fd[2],wn,rn;
	memset(w_buf,0,100);
	memset(r_buf,0,100);
	pipe(fd);
	p=fork();
	if(p<0){
		perror("fork failed.\n");
		return -1;
	}
	else if(p==0){
		char b='a';
		close(fd[0]);
		//sprintf(w_buf,"pid=%d",getpid());
		for(int i=0;i<65535;i++)
		{
			printf("child write %d times.\n",i);
			write(fd[1],w_buf,1);
		}
		printf("child write ok\n",wn);
		close(fd[1]);
		exit(0);
	}
	else{
		wait(NULL);
		close(fd[1]);
		wait(NULL);
		for(int i=0;i<65536;i++)
		{
			read(fd[0],r_buf,1);
			printf("%d: parent read from pipe: %s\n",i,r_buf);
		}
		close(fd[0]);
		return 0;
	}
}
