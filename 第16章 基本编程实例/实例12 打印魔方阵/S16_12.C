#define N 19
#include <stdio.h>
int main()
{int a[N][N]={0},i,j,k,n;
 scanf("%d",&n);
 i=0;
 j=n/2;
 a[i][j]=1;
 for(k=2;k<=n*n;k++)
   {if(--i<0)
      i+=n;
    if(++j==n)
      j-=n;
    if(a[i][j]!=0)
      {if((i+=2)>n-1)
	 i-=n;
       if((j-=1)<0)
	 j+=n;
      }
    a[i][j]=k;
   }
 for(i=0;i<n;i++)
   {for(j=0;j<n;j++)
      printf("%4d",a[i][j]);
    printf("\n");
   }
 getch();
 return 0;
}