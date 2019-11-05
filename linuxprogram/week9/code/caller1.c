#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	int ret;
	printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
	ret=system("/home/rlk/test/linuxprogram/week9/code/test02");
	printf("after calling!\n");
	sleep(100);
	return 0;
	
}
