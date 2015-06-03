#define NUMBER  5
#include <stdio.h>
int main()
{
 int a[NUMBER+1][5],i,j,k,t,n;
 for(i=1;i<=NUMBER;i++)
   {printf("请输入第 %d个学生的数据: ",i);
    scanf("%d,%d,%d,%d", &a[i][0],&a[i][1],&a[i][2],&a[i][3]);
    a[i][4]=a[i][1]+a[i][2]+a[i][3];
   }
 for(i=1;i<=NUMBER;i++)
   {
    k=i;
    for(j=i+1;j<=NUMBER;j++)
      if(a[j][4]>a[k][4])
	k=j;
    for(n=0;n<=4;n++)
      {
       t=a[i][n];
       a[i][n]=a[k][n];
       a[k][n]=t;
      }
   }
 printf(" 学号  数学  英语 计算机 总分 名次\n");
 for(i=1;i<=NUMBER;i++)
   for(j=0;j<=5;j++)
      {if(j!=5)
	 printf(" %3d  ",a[i][j]);
       else
	 printf(" %3d  \n",i);
      }
 getch();
 return 0;
}
