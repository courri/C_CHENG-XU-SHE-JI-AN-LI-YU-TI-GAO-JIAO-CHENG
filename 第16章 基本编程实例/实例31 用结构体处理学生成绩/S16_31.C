#define N 10
#include <stdio.h>

typedef struct
  {
   int num;
   char  name[9];
   int english, math, computer, sum;
  }STU;

int main()
{void input(STU*,int), output(STU*,int), sort(STU*,int);
 STU s[N];
 input(s, N);
 sort(s, N);
 output(s, N);
 getch();
 return 0;
}

void input(STU*p, int n)
{int i;
 for(i=0; i<=n-1; i++)
   {printf("请输入第 %d个学生的数据: ", i+1);
    scanf("%d",&p[i].num);
    scanf("%s", p[i].name);
    scanf("%d%d%d",&p[i].english, &p[i].math, &p[i].computer);
    p[i].sum=p[i]. english + p[i].math + p[i].computer;
   }
}

void sort(STU*p, int n)
{int i, j, k;
 STU  t;
 for(i=0; i<n-1; i++)
   {
    k=i;
    for(j=i+1; j<=n-1; j++)
      if(p[j].sum>p[k].sum)
        k=j;
    t=p[k]; p[k]=p[i]; p[i]=t;
   }
}

void output(STU*p, int n)
{int i;
 for(i=0; i<=n-1; i++)
   {
    printf("%2d,%d,%8s,%2d,%2d,%2d,%3d\n",
    i+1, p[i].num, p[i].name, p[i].english, p[i].math, p[i].computer, p[i].sum);
   }
}
