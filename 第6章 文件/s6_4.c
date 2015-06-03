#include <stdio.h>
#include<stdlib.h>
struct student{
   unsigned  num;
   char      name[9];
   unsigned  cla;
   int       score;
};

/*写数据的函数：*/
#include <stdio.h>
#include<stdlib.h>
#define N 10
void  stu_write ()
{int  i;
 struct student stu;
 FILE *fp;
 if((fp = fopen("student.txt", "w")) == NULL)
   {
    printf("打开文件失败");
    exit(1);
   }
 for( i = 0; i<=N-1; i++)
   {
    scanf("%d%s%d%d",  &stu.num, stu.name, &stu.cla, &stu.score);
    fprintf(fp,"%2d  %-8s  %1d  %3d\n", stu.num, stu.name, stu.cla, stu.score);
   }
 fclose(fp);
}


/*读数据并排序的函数：*/
void  stu_read_sort()
{int  i, j, k;
 struct student stu[N], t;    /*变量t用来交换数据*/
 FILE *fp;
 if((fp = fopen("student.txt", "r")) == NULL)
   {
    printf("打开文件失败");
    exit(1);
   }

 /*读数据*/
 i=0;
 while(!feof(fp))
   {
    fseek(fp, (2+8+1+3+2*3+2)*i, 0);         /*读写指针跳到第i行开头*/
    fscanf(fp, "%2d  %8s  %1d  %3d", &stu[i].num, stu[i].name, &stu[i].cla, &stu[i].score);
    i++;
   }
 fclose(fp);

 /*排序*/
 for( i = 0; i<=N-2; i++)
   {
    k = i;
    for( j= i+1; j<=N-1; j++)
      {
       if(stu[k].score < stu[j].score)
	  k = j;
      }
    t = stu[k];
    stu[k] = stu[i];
    stu[i] = t;
   }

 /*输出*/
 for ( i= 0; i<=N-1; i++)
   printf("%2d  %-8s  %d  %3d\n", stu[i].num, stu[i].name, stu[i].cla, stu[i].score);
}

int main()
{stu_write();
 stu_read_sort();
 return 0;
}