#include<stdio.h>
int main()
{long  i;
 int  a,b,c,d,e;
 int flag = 0;
 for( i = 67577; flag == 0 ; i++)
   {a = i%10;
    b = i/10%10;
    d = i/1000%10;
    e = i/10000;
    if( a == e && b == d)
      flag = 1;
   }
 printf("汽车速度是：%5.2f\n", ( i - 67576 - 1)/2.); 
 getch();
 return 0;
}
