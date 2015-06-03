#include <stdio.h>
int main()
{float average(int *), aver;         /*函数声明和变量定义可放在一起*/
 int score[3][4] ={65,78,96,75,80,79,95,76,58,87,65,90};
 aver = average(score);
 printf("总平均是%5.2f\n",aver);
 return 0;
}
float average(int *p)
{float  sum = 0;
 int  i;
 for( i = 0; i<=11; i++)
   {
    sum += *p;
    p++;
   }
 return  sum/12;
}
