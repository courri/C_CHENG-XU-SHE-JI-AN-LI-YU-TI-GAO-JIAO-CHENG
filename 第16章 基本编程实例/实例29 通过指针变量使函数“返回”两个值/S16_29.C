#include <stdio.h>
void sum_sub(int x,int y, int*p1, int *p2)
{*p1=x*x+y*y;
 *p2=x*x-y*y;
}
int main()
{void sum_sub(int, int, int*, int*);
 int  a,b, sum, sub;
 scanf("%d%d", &a, &b);
 sum_sub(a, b, &sum, &sub);
 printf("%d,%d\n", sum, sub);
 getch();
 return 0;
}
