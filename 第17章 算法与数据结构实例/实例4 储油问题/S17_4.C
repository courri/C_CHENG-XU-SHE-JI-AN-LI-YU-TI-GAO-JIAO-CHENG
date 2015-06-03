#include<stdio.h>
#define N 10
int main()
{int distance[N]={500},oil[N]={500};
 int k;
 clrscr();
 for(k=1; distance[k-1]>0; k++)
   { distance[k]= distance[k-1] -500/(2*k+1);
     oil[k]=500*(k+1);
   }
 k--;
 if(distance[k]<0)
   { distance[k]=0;
     oil[k]=500*k+(2*k+1)*distance[k-1];
   }
 printf("\ndistance   oil\n\n");
 for(; k>=0; k--)
   printf("%5d,%8d\n", distance[k], oil[k]);
 getch();
 return 0;
}
