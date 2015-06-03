#include <stdio.h>
#include  <math.h>
int main()
{int prime(int);
 int i;
 for(i=1; i<=1000; i++)
   if ( prime(i) == 1)
     printf("%5d", i);
 printf("\n");
 getch();
 return 0;
}

int prime(int m)
{int k, i;
 k=sqrt(m);
 for(i=2; i<=k; i++)
   if(m%i == 0)
     return 0;
 return 1;
}
