#include <stdio.h>
void func(int[], int*, int*);    /*声明被调函数func */
int main()
{int  max,min;                   /*定义局部变量用来存储最大、最小值*/
 int a[10] = {3,5,1,8,7,9,2,4,6,0};
 func (a, &max, &min);           /*将a及最大值、最小值的存储位置告诉func */
 printf("max=%d,min=%d\n", max, min);
 return 0;
}
void func (int x[], int *p1, int *p2)
{int  i;
 *p1 = *p2 = x[0];               /*相当于 max=min=x[0]; */
 for( i = 1; i<=9; i++)
   {
    if(x[i]>*p1)
      *p1 = x[i];
    if(x[i]<*p2)
      *p2 = x[i];
   }
}
