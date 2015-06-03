#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{int n, i, k;
 randomize();
 n=random(101);
 for(i=1; i<=5; i++)
   {printf("\n请输入一个数，您还有%d次机会:  ", 6-i);
    scanf("%d", &k);
    if( k == n )
       break;
    if(k > n)
       printf("\n不对，大了");
    else
       printf("\n不对，小了");
   }
 if(i<=5)
   printf("\n恭喜您，猜对了! :) 答案是%d\n", n);
 else
   printf("\n抱歉，没猜对! :( 正确答案是%d\n", n);
 getch();
 return 0;
}


