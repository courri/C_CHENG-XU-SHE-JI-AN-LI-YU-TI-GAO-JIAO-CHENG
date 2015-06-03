#include<stdio.h>
int main( )
{int x;
 scanf("%d", &x);
 if(x>=90)
   printf("优");
 else
   if(x>=80)
     printf("良");
   else
     if(x>=70)
       printf("中");
     else
       if(x >= 60)
	 printf("及格");
       else
	 printf("差");
 return 0;
}
