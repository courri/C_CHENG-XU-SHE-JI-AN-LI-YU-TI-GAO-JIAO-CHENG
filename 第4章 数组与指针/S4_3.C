#include <stdio.h>
int main()
{static int  a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
 int  *p;
 for( p = a; p<= a +11; p++)
   printf("%3d,", *p);
}
