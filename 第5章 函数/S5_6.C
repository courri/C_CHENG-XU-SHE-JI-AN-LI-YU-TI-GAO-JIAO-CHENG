#include <stdio.h>
int main()
{int  a[10] = {4,9,2,7,8,6,5,1,0,3},  i;
 void  sort(int*);            /*函数声明*/
 sort(a);                    /*数组名做实参，相当于传递了a[0]的地址*/
 for( i = 0; i<=9; i++)
   printf("%3d", a[i]);
 printf("\n");
 return 0;
}
void sort(int *p)             /*指针变量做虚参*/
{int  i, j, k, t;
 for( i = 0; i<=8; i++)
   {
    k = i;
    for( j = i +1 ;j<=9; j++)
       if( p[j] > p[k] )
         k = j;
    t = p[i];
    p[i] = p[k];
    p[k] = t;
   }
}
