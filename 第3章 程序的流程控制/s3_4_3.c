#include <stdio.h>
int main()
{int  a, b, c, d, max;
 scanf("%d%d%d%d", &a, &b, &c, &d);
 max = a;                           /*a先当第一任擂主*/
 if(b > max)                         /*如果b比擂主大，则b成为擂主否则擂主不变*/
    max = b;
 if(c > max)
    max = c;
 if(d > max)
    max = d;
 printf("%d\n",  max);
 return 0;
}
