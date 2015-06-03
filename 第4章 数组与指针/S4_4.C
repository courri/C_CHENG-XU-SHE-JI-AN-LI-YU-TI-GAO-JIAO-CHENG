#include <stdio.h>
int main()
{ void sort(int*);
  int  a[10] = {3,5,8,1,4,9,2,4,0,6}, i;
  sort(a);
  for( i = 0; i<=9; i++)
    printf("%3d", a[i]);
  return 0;
}

void  sort(int*p)
{int  i, j, k, t;
 for( i = 0; i<9; i++)
   {
    k = i;
    for( j= i+1; j<=9; j++)
      if(*(p+k)<*(p+j))
          k=j;
    t = *(p+k);
    *(p+k) = *(p+i);
    *(p+i) = t;
   }
}
