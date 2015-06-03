#include <stdio.h>
int main()
{int w[5] = {100, 90, 100, 90, 90};
int sum = 0, i, k = 1, m;
 for( i = 0; i<5; i++ ) {
   sum += w[i]*k;
   k*=2;
 }
 m = (100*31 - sum)/10 ;
 k=16;
 for(i=5; i>=1; i--)
   {
    if(m>=k)
      {
       printf("µÚ%dÏäÊÇ¼Ù»õ\n", i);
       m -= k;
      }
    k /= 2;
   }
 getch();
 return 0;
}

