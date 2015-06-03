#include <stdio.h>
void sum(int m, int n)   /*计算两个数的和并输出*/
{int s;
 s=m+n;
 printf("%d\n", s);
}

int main()
{int a,b;
 scanf("%d%d",&a,&b);
 sum(a,b);     
 return 0;
}
