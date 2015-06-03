#include<stdio.h>
int main()
{int  m, n, i;
 scanf("%d,%d", &m, &n);
 for( i =1;  i <= m*n;  i++)
   {
    if( i%m != 0)
      continue;        /*若除以m除不尽，则回到i++换下一个数*/
    if( i%n == 0)
      break;          /*若除以n除尽，意味着已找到最小公倍数，跳出循环输出结果*/
   }
 printf("%d和%d的最小公倍数是:%d\n", m,n,i);
 return 0;
}
