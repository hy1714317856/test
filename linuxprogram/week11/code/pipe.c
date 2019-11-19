#include "my.h"

int main()
{
	pid_t result;
	int r_num;
	int pipe_fd[2];
	char buf_r[100];
	memset(buf,0,sizeof(buf_r));
	if(pipe(pipe_fd)<0)
	{
		printf("faile to create pipe!\n");
		return -1;
	}
	result=fork();
	if(result<0)
	{
		printf("fail to create child !\n");
		exit;
	}
	else if(result==0)
	{
		close(pipe_fdf[1]);
		if((r_num=read(pipe_fd[0],buf_r,100))>0);
		printf("子进程从管道读取%d个字符，读取的字符是：%s\n",r_num,buf_r);
		close(pipe_fd[0]);
		exit(0);
	}
	else
	{
		close(pipe_fd[0]);
		if(write(pipe_fd[1],"第一串文字",10)!=-1)
		printf("父进程向管道写入“第一串文字”!\n");
		if(write(pipe_fd[1],"第二串文字",10)!=-1)
		printf("父进程向管道写入“第二串文字”!\n");
		close(pipe_fd[1]);
		waitpid(result,NULL,0);
		exit(0);
	}
}
