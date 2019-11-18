#include "my.h"

int g;
char a[100]={0};
extern int k;
int main()
{
	pid_t pid;
	int i;
	static int k=20;
	printf("extern: pid=%d \n &g=%16p \n &k=%16p \n &a=%16p\n",getpid(),&g,&k,a);
	for(i=0;i<10;i++)
	{
		printf("extern: g=%d,k=%d\n",g++,k++);
	}
	return 0;
}
