#include <stdio.h>
#include <math.h>
int  prime(int m)
{int i,k;
 k = sqrt(m);
 for (i = 2; i<=k; i++)
   if(m%i == 0)
     return 0;
 return 1;
}

int main()
{int i;
 for(i=100;i<=200;i++)
   if(prime(i))
     printf("%4d",i);
 return 0;
}

