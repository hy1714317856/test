#include "../lib/lib.h"

int main(){
	int a[100];
	int n=100;
	getnumber(a,n);
	printf("max=%d",max(a,n));
	printf("sum=%d",sum(a,n));
	return 0;
}
