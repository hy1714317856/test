#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	int ret;
	char *vect[]={"./test02","123","hello","world",NULL};
	printf("caller02: pid=%d,ppid=%d\n",getpid(),getppid());
	execvp("test02",vect);	
	//execv("/home/rlk/test/linuxprogram/week9/cdoe/test02",vect);
	//execl("/home/rlk/test/linuxprogram/week9/code/test02","./test02","123","456",NULL);
	printf("after calling!\n");
	sleep(1);
	return 0;
}
