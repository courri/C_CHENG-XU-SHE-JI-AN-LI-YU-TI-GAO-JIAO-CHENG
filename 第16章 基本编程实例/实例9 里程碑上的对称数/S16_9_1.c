#include<stdio.h>
int main()
{long  i;
 int  a,b,c,d,e;
 for( i = 67577;    ; i++)
   {a = i%10;
    b = i/10%10;
    d = i/1000%10;
    e = i/10000;
    if( a == e && b == d)
      break;
   }
 printf("汽车速度是：%5.2f\n", ( i - 67576)/2.); 
 getch();
 return 0;
}
