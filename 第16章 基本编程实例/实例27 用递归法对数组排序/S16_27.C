#include <stdio.h>
void sort(int *p, int n)
{int i, t, k;
 if(n>=2)
   {k=0;
    for(i=1; i<n; i++)
      if(p[i]>p[k])
	k=i;
    t=*p;
    *p=p[k];
    p[k]=t;
    sort(p+1, n-1);
   }
}

int main()
{int i, a[10]={3,7,1,9,0,6,2,4,8,5};
 clrscr();
 sort(a,10);
 for(i=0; i<=9; i++)
   printf("%3d", a[i]);
 getch();
 return 0;
}