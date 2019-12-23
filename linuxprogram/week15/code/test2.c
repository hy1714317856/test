#include "my.h"

static int share_cnt=0;
static pthread_rwlock_t rwlock;

void *reader(void *param)
{
	int i=(int)param;
	while(1)
	{
		pthread_rwlock_rdlock(&rwlock);
		fprintf(stderr,"reader---%d:the share_cnt=%d\n",i,share_cnt);
	}
}
