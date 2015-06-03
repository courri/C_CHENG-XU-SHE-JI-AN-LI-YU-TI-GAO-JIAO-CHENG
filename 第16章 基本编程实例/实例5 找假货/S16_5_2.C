#include <stdio.h>
int main()
{int w[5] = {100, 90, 100, 90, 90};
 int sum = 0, i, k = 1, m;
 for( i = 1; i<=5; i++ )
   {
    sum += w[i-1]*k;
    k*=2;
   }
 m = (100*31 - sum)/10 ;
 for(i=1; i<=5; i++)
   {
    if(m&1)
      printf("µÚ%dÏäÊÇ¼Ù»õ\n", i);
    m>>=1;
   }
 getch();
 return 0;
}

