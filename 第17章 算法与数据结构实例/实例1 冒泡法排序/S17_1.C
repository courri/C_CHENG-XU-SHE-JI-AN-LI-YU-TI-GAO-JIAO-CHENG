#include <stdio.h>
#define  N 10
int main()
{int  a[N] = {3,5,2,9,7,4,8,1,0,6}, i, j, t;
 for(i=0; i<N-1; i++)
   {for(j=0; j<N-i-1; j++)
      if ( a[j] > a[j+1] )
	{
	 t=a[j];
	 a[j]=a[j+1];
	 a[j+1]=t;
	}
   }
 for(i=0; i<=N-1; i++)
   printf("%3d", a[i] );
 printf("\n");
 return 0;
}
