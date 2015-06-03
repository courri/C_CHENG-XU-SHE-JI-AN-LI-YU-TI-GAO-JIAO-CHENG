#include <math.h>
int  prime(int m)
{int  k, i, flag = 1 ;
 k = sqrt(m);
 for( i = 1;  i <= k; i++ )
     if ( m % i == 0 )
         flag = 0;
     else 
         flag = 1;
 return flag;
}

int main()
{int m;
 scanf("%d",&m);
 if(prime(m) == 1)
   printf("%d is a prime\n", m);
 else
   printf("%d is not a prime\n", m);
 getch();
 return 0;
}