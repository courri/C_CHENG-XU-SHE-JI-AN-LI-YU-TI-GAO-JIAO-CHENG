#include <stdio.h>
int main()
{int x;
 for(x = 1; x<=4; x++)
   if( (x != 1) + ( x == 3) + ( x == 4) + ( x != 4) == 3 )
 printf("%c��С͵��\n", x+64);
 getch();
 return 0;
}

