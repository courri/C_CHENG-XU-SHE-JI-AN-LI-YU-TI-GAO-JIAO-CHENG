#include<stdio.h>
int main()
{int  n;
 float y = 1;
 for( n = 0; y < 2.0; n++)    /*循环条件不是计数器控制的*/
   y *= 1.09;
 printf("%d\n", n);
 getch();
 return 0;
}
