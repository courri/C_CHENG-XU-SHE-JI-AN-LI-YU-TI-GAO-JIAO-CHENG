#define N 100
#include <stdio.h>
int main()
{int a[N], n, m, k;
 int i, count, j;
 clrscr();
 scanf("%d%d%d", &n, &k, &m);
 for(i=1; i<=n; i++)
   a[i]=i;
 j=n;
 count=0;
 i=1;
 while(j>m)
   {
    if(a[i]!=0)
      {
       count++;
       if(count == k)
	 {
	  a[i] = 0;
	  count = 0;
	  j--;
	 }
      }
    i++;
    if(i>n)
      i = 1;
   }
 for(i=1; i<=n; i++)
   if(a[i]!=0)
     printf("%4d", a[i]);
 getch();
 return 0;
}
