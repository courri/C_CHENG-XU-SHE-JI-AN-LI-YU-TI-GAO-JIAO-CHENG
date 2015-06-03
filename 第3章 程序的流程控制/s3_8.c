#include<stdio.h>
int main()
{int  n, max, i;
 scanf("%d", &n);          /*输入第一个数*/
 max = n;                 /*第一个数作擂主*/
 for( i = 2; i<=10; i++)
   {
    scanf("%d", &n);
    if( n > max)             /*若n是更大的数*/
      max = n;            /*擂主易人*/
   }
 printf("最大数是:%d\n", max);
 return 0;
}
