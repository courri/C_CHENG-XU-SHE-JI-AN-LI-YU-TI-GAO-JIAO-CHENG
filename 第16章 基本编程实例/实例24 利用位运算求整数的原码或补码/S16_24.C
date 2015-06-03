#include "stdio.h"
int main()
{int n,i;
 char k;
 clrscr();
 scanf("%d", &n);
 printf("要转成什么？\n");
 printf("1、原码\n");
 printf("2、补码\n");
 do
   {
    k=getch();
   }while(k!='1'&&k!='2');
 if(k=='1' && n<0)
   {n--;
    n^=~0;
    n|=1<<sizeof(int)*8-1;
   }

 for(i = sizeof(int)*8 - 1; i >= 0; i--)
   {
    printf("%d", n>>i&1);
   }
 printf("\n");
 getch();
 return 0;
}
