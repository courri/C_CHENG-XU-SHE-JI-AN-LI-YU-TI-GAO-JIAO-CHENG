#include <stdio.h>
int main()
{int x, y;
 scanf("%d", &x);
 switch(x/20)
   {case 0: y = 0; break;
    case 1: y = (x-20)*2; break;
    default: y = (x - 40)*5 + 40;
   }
 printf("y=%d\n", y);
 getch();
 return 0;
}
