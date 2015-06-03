#include<stdio.h>
int main()
{int n=0;
 float  y = 1;            /*设当年的产值为1*/
 while( y < 2.0)         /*以产值达到2作为结束循环的条件*/
   {y *= 1.09;
    n++;                /*每乘一次1.09都意味着过了一年*/
   }
 printf("%d\n", n);
 getch();
 return 0;
}
