#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

int main(){
	int a[100];
	int n=100;
	void *handle;
	void (*f1)();
	int (*f2)();
	int (*f3)();
	char *error;
	handle=dlopen("../d-lib/libd-lib.so",RTLD_LAZY);
	if(!handle){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);	
	}
	f1=dlsym(handle,"getnumber");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);	
	}
	f2=dlsym(handle,"max");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);	
	}
	f3=dlsym(handle,"sum");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);	
	}
	
	f1(a,n);
	printf("max=%d",f2(a,n));
	printf("sum=%d",f3(a,n));
	if(dlclose(handle)<0){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);	
	}
	return 0;
}
