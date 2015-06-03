#define  N 10
#include <stdio.h>
int main()
{int  a[N] = {3,5,2,9,7,4,8,1,0,6}, i, j, t;
 for(i=1; i<=N-1; i++)
   {
    t=a[i];
    for(j=i-1; t<a[j]&&j>=0; j--)
      a[j+1]=a[j];
    a[j+1]=t;
   }
 for(i=0; i<=N-1; i++)
   printf("%3d", a[i] );
 printf("\n");
 getch();
 return 0;
}
