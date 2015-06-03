#include <stdio.h>
int main()
{int  a, b, c, d, max;
 scanf("%d%d%d%d", &a, &b, &c, &d);
 if(a >= b && a >= c && a>= d)
    max = a;
 if(b >= a && b >= c && b >= d)
    max = b;
 if(c >= a && c >= b && c >= d)
    max = c;
 if(d >= a && d >= b && d >= c)
    max = d;
 printf("%d\n",  max);
 return 0;
}
