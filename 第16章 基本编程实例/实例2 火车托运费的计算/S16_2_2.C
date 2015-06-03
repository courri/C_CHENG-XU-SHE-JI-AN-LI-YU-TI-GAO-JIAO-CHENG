#include <stdio.h>
int main()
{int x, y;
 scanf("%d", &x);
 if(x<=20)
   y = 0;
 else if(x<=40)       /*在x>=20不成立的情况下，若x<=40*/
   y = (x-20)*2;
 else               /*在前面两个条件都不成立的情况下*/
   y = (x - 40)*5 + 40;
 printf("y=%d\n", y);
 getch();
 return 0;
}
