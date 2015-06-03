#include<stdio.h>
int main( )
{
 int  n0 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0;
 int  x;
 scanf("%d", &x);
 while(x != -1)
   {switch(x/10)
      {case  10:
       case  9:
		n9++;
		break;
       case  8:
		n8++;
		break;
       case  7:
		n7++;
		break;
       case  6:
		n6++;
		break;
       default:
		n0++;
      }
    scanf("%d", &x);
   }
 printf("%d,%d,%d,%d,%d\n", n9, n8, n7, n6, n0);
 return 0;
}
