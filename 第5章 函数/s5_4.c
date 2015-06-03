#include  <stdio.h>
int main()
{void  edit(int *);                   
 int  a = 59;
 edit(&a);                            /*变量地址做实参*/
 printf("修改后a的数据是：%d\n", a);
 return 0;
}

void  edit(int *p)                      /*指针变量做虚参*/
{*p = 60;
}
