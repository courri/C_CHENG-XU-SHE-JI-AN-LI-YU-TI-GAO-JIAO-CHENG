#include <stdio.h>
int main()
{
 float sum=0;
 int  a = 1, b = 1, sign = 1, i;
 for( i = 1; i<=20; i++)
   {sum += ((float)a/b)*sign;
    b = a+b;
    a = b-a;
    sign *= -1;
   }
 printf("%5.3f\n", sum);
 getch();
 return 0;
}
