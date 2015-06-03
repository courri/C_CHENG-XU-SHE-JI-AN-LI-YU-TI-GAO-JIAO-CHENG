#include <stdio.h>
int main(int n, char *p[])
{int i, j;
 long  sum=0, s;
 clrscr();
 for(i=1; i<n; i++)
   {
    s=0;
    for(j=0; *(p[i]+j)!='\0'; j++)
      s=s*10+*(p[i]+j)-48;
    sum+=s;
   }
 printf("sum is %ld\n", sum);
 getch();
 return 0;
}

