#include <stdio.h>
int  sum(int,int);       /*函数声明*/
int main()
{int a,b,s;
 scanf("%d%d",&a,&b);
 s=sum(a,b);     
 printf("%d\n", s);
 return 0;
}
int  sum(int m, int n)   /*计算两个数的和*/
{int s;
 s=m+n;
 return s;            
}
