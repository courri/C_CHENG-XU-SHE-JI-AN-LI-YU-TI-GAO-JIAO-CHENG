#define M 3
#define K 4
#define N 2
#include <stdio.h>
int main()
{int a[M][K]={3,9,12,10,1,8,6,7,5,4,2,11};
 int b[K][N]={5,8,2,1,7,3,6,4}, c[M][N]={0};
 int i,j,k;
 clrscr();
 for(i=0; i<M; i++)
   {
    for(j=0; j<N; j++)
      {
       for(k=0;k<K;k++)
	 c[i][j]+=a[i][k]*b[k][j];
       printf("%5d", c[i][j]);
      }
    printf("\n");
   }
 getch();
 return 0;
}
