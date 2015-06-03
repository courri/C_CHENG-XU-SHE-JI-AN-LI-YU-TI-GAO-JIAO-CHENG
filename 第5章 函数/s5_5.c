#include  <stdio.h>
int main()
{void  swap(int *,int*);                   
 int  a = 1, b = 2;
 swap(&a, &b);                    /* 传递两个变量的地址 */
 printf("%d,%d\n",  a, b);
 return 0;
}

void  swap( int *pa,  int *pb )        /* 设两个虚参 */
{int  t;
 t = *pa;                          /* 相当于t=a */
 *pa = *pb;                        /* 相当于a=b */
 *pb = t;                          /* 相当于b=t */
}
