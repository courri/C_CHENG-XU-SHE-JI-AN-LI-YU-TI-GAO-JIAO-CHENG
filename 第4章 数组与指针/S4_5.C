#include <stdio.h>
int main()
{int  sum(int*);
 int  a[3][4] = {3,5,2,8,9,4,6,7,0,1,12,-5},  s;
 s = sum(a);
 printf("%d\n", s);
 return 0;
}
    
int  sum(int *p)
{int  i, s = 0;
 for( i = 0 ;i<=11; i++)
   s +=*(p+i);
 return s;
}
