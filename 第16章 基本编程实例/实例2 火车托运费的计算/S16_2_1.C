#include <stdio.h>
int main()
{int x, y;
 scanf("%d", &x);
 if(x<=20)
   y = 0;
 if(x>20&&x<=40)
   y = (x-20)*2;
 if(x>40)
   y = (x - 40)*5 + 40;
 printf("y=%d\n", y);
 getch();
 return 0;
}
