#include<stdio.h>
int main()
{int  n, max, k, i;          /*k用来记录最大数的序号*/
 scanf("%d", &n);
 max = n;
 k = 1;                   /*目前第一个数最大，记录其序号*/
 for( i = 2; i<=10; i++)
   {
    scanf("%d", &n);
    if( n > max)
      {
       max = n;
       k = i;               /*记录新擂主的序号*/
      }
   }
 printf("最大数的序号是:%d\n",  k);
 return 0;
}
