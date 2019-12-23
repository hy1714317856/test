#include "my.h"
#define NUM_THREADS 4

struct info
{
	int a;
	int b;
};

struct rval
{
	int sum;
	pthread_t tid;
};

void hello(void *t)
{
	pthread_t my_tid;
	struct info *y;
	y=(struct info *)(t);
	int result=0;
	for(int i =0;i<=y->b;i++)
	{
		result=result+i;
	}
	my_tid=pthread_self();
	printf("\tThread %d : my tid is %lx,Hello world\n",(int)y->a+1,my_tid);
	printf("\tThread %d : sum 1 to %d is %d\n",(int)y->a,y->b,result);
}

int main()
{
	pthread_t tid;
	struct info a[4];
	int rv,t;
	for(t=0;t<NUM_THREADS;t++)
	{
		a[t].a=t;
		a[t].b=(t+1)*100;
		rv=pthread_create(&tid,NULL,(void*(*)())hello,(void*)&a[t]);
		if(rv!=0)
		{
			printf("thread create failed!\n");
			return -1;
		}
		printf("Create thread %lx\n",tid);
	}
	printf("Good bye!\n");
	pthread_exit(NULL);
}
