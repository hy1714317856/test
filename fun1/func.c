#include "uhead.h"
//计算数组总和
int usum(int *a,int n)
{
  int s=0,i;
  for(i=0;i<n;i++)
     s=s+a[i];
   return s;
}
//为数组生成随机数
void urand(int *a,int n)
{
  int i;
  srand((int)time(0));
  for(i=0;i<n;i++)
    a[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));
}
void show(int *a,int n)
{
  int i;
  for(i=0;i<n;i++)
    printf("%d\n",a[i]);
}
//冒泡排序
void bsort(int *a,int n)
{
  int i,j,temp;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i;j++)
    {
       if(a[j]>a[j+1])
        {temp=a[j];
         a[j]=a[j+1];
         a[j+1]=temp;
        }
    }
  } 
}
//比较函数
int comp(const void*a,const void*b)
{
    return *(int *)a-*(int *)b;
}
//
int totaltime(int *a,int n)
{
   clock_t start,finish;
   double run;
   start=clock();
   bsort(a,n);
   finish=clock();
   run=(double)(finish-start)/CLOCKS_PER_SEC;
   printf("冒泡排序法运行时间为%lfs\n",run);
   urand(a,n);
   start=clock();
   qsort(a,UNUMBER,sizeof(int),comp);
   finish=clock();
   run=(double)(finish-start)/CLOCKS_PER_SEC;
   printf("快速排序法运行时间为%lfs\n",run);
}
void sysort(void *base,int num,int width)
{
    qsort((int *)base,UNUMBER,sizeof(int),comp);
}
