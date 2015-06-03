#include <stdio.h>
int main()
{ void sub(int*);
  int a;
  sub(&a);
  printf("%d\n", a);
  return 0;
}

void sub( int *p)
{*p=5;           /*不能写成a=5，因为a是主函数中的局部变量*/
}
