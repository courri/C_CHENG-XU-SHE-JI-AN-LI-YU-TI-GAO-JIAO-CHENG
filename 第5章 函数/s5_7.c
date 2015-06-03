#include <stdio.h>
int main()
{void sub(int[]);
 int  a[10] = {1,3,5,2,7,9,6,8,0,4};
 printf("a的空间大小：%d\n", sizeof(a));
 printf("a的值：%p\n", a);
 sub(a);
 printf("a的值：%p\n", a);
 return 0;
}
void sub(int x[])
{printf("x的空间大小：%d\n", sizeof(x));
 printf("x的值：%p\n", x);
 printf("x的地址：%p\n", &x);
 x++;
 printf("x的值：%p\n", x); 
}
