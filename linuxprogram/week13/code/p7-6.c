#include "my.h"

int main(void)
{
	sigset_t base_mask,waiting_mask,oldmask;
	int sig;
	sigemptyset(&base_mask);
	sigaddset(&base_mask,SIGQUIT);
	sigaddset(&base_mask,SIGINT);
	if(sigprocmask(SIG_BLOCK,&base_mask,&oldmask)<0)
	{
		err_exit("SIG_BLOCK error");	
	}
	printf("I have blocked SIGQUIT and SIGINT,and\n you can try to send these two signals and wait for my reply.\n");
	sleep(10);
	printf("Let me see if there is any pending signal.\n");
	
}

