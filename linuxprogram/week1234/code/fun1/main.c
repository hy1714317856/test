#include "uhead.h"
int main()
{
  struct arg k;
  int a[UNUMBER];
  urand(a,UNUMBER);
  show(a,UNUMBER);
  k=operater(a,UNUMBER);
  printf("\n***********\nsum=%d\n",usum(a,UNUMBER));
  totaltime(a,UNUMBER);
  printf("数据总和为%d,数据平均值为%f\n",k.sum,k.ave);
}
