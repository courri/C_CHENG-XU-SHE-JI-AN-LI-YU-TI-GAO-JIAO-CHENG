#include <stdio.h>
#define  N 10
int main()
{int  a[N] = {3,5,2,9,7,4,8,1,0,6}, i, j, k, t;
 for(i=0; i<N-1; i++)
   {/* 首先将最前面数当作擂主，记录其序号 */
    k = i;

    /* 后面的每一个数都与擂主进行比较，以便找出最小数 */
    for(j=i+1; j<=N-1; j++)
      if ( a[j] < a[k] )
	k = j;

    /* 将最小数交换到（剩下数的）最前面 */
    t=a[k];
    a[k]=a[i];
    a[i]=t;
   }
 for(i=0; i<=N-1; i++)
   printf("%3d", a[i] );
 printf("\n");
 return 0;
}

