#include <stdio.h>
int main( )
{int  x,y;
 scanf("%d", &x);
 switch(x/20)
   {
    case 0:
	    y = 0;
	    break;
    case 1:
	    y = (x - 20)*2;
	    break;
    default:
	    y = 20*2 + (x - 40) *5;
   }
 printf("%d\n", y);
 return 0;
}

