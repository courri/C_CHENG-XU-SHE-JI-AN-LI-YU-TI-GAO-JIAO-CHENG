#include<stdio.h>
int main()
{int  n, m, k, count=0;          /*count用来计数*/
 for( m = 0; m<=20; m++)
   for( n = 0; n<=50; n++)
     for( k = 0; k<=100; k++)
       if(m*5+n*2+k==100)
          count++;
 printf("共有%d种兑换法\n",  count);
 return 0;
}

