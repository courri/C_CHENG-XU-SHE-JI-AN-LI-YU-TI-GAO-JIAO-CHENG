#include<stdio.h>
int main()
{int  m, n, k;                  /*k用来存储余数*/
 scanf("%d%d", &m, &n);
 if(m<n)
   {                   /*若m<n则交换*/
    int  t;
    t = m;
    m = n;
    n = t;
   }
 k = m%n;
 while( k != 0)
   {
    m = n;
    n = k;
    k = m%n;
   }
 printf("最大公约数是：%d\n", n);      /*最后一次的除数便是所求*/
 return 0;
}



