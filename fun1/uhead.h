#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define UNUMBER 100
struct arg{
   float ave;
   int sum;
};
int usum(int *,int );
void urand(int *,int);
void show(int *,int );
int comp(const void*,const void*);
int totaltime(int *,int); 
struct arg operater(int *,int);

