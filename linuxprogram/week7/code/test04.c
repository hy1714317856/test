#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int global=4;
int main(void)
{
	pid_t pid;
	int vari=5;
	printf("before error\n");
	if((pid=fork())<0){
		printf("fork error\n");
		exit(0);	
	}else if(pid==0){
		global++;
		vari--;	
		printf("Child changed\n");
		printf("global=%d  vari=%d\n",global,vari);
	}else{
		printf("Parent did not change\n");
		printf("global=%d  vari=%d\n",global,vari);
		exit(0);
	}
	
}
