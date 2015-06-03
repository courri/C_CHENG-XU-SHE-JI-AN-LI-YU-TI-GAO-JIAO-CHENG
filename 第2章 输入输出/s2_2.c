#include <stdio.h>
#include <math.h>
#include <conio.h>
int main()
{int  m ,i, k, n = 0;
 clrscr();              /*输出之前先清屏*/
 for(m = 1; m <= 10000; m++)
   {
    k = sqrt(m);
    for(i = 2; i<= k;i++)
      if(m%i == 0)
        break;
    if(i>k)
      {
       n++;
       printf("%5d",m);
       if(n%10 == 0)     /*每行输出10个*/
	 printf("\n");
       if(n%200 == 0)
	 getch();        /*一屏显示20行时暂停，看输出*/
      }
   }
 getch();
 return 0;
}
