#include <stdio.h>
#include <math.h>
void prime(int m)
{int i,k;
 k = sqrt(m);
 for( i = 2 ;i<=k; i++)
   if(m%i == 0)
     break;
 if( i == k+1)
   printf("%d是素数\n", m);
 else
   printf("%d不是素数\n", m);
}


int main()
{int i;
 for(i=100;i<=200;i++)
   prime(i);
 return 0;
}

