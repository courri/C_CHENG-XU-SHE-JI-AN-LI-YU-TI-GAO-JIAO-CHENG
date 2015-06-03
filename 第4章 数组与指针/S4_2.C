#include <stdio.h>
int main()
{int  a[4], b[3][4], c[2][3][4];
 printf("%p,%p \n",  a, a +1);
 printf("%p,%p \n",  b, b +1);
 printf("%p,%p \n",  c, c +1);
 printf("%p,%p,%p \n",  b, b[0] +1, b +1);
 return 0;
}
