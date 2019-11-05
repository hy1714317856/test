#include <stdio.h>
#include <stdlib.h>
static void _attribute_ ((constructor)) before_main(void){
	printf("Running befored main!\n");
}

int main(){
	printf("Main!");
	return 0;
}
