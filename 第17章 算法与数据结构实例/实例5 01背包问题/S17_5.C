#define  CONTENT 20
#define  NUM  10
#include <stdio.h>
void knapsack(int v[NUM],int w[NUM], int c, int m[NUM][CONTENT+1])
{int n = NUM-1;
 int i,j;
 int jMax;
 /*初始化数组，只有最后一件物品可选时*/
 for( j =0; j<=c; j++)             /*先都清0*/
   m[n][j] = 0;
 for( j = w[n]; j<=c; j++)          /*对于c>=w[n]的情况，置为价值*/
   m[n][j] = v[n];

 /*以下求解m[i][j]*/
 for(i=n-1; i>=0; i--)
   {if(w[i]-1<c)
      jMax=w[i]-1;
    else
      jMax=c;
    for(j=0; j<=jMax; j++)
      m[i][j] = m[i+1][j];
    for(j=jMax+1; j<=c; j++)
      {if(m[i+1][j] >= m[i+1][j-w[i]]+v[i])
	 m[i][j] = m[i+1][j];
       else
	 m[i][j] = m[i+1][j-w[i]]+v[i];
      }
   }
}

void traceback(int flag[NUM], int w[NUM], int m[NUM][CONTENT+1])
{int n = NUM-1;
 int i;
 int c=CONTENT;
 int j;
 for(i=0; i<=n-1; i++)
   {if(m[i][c] != m[i+1][c])
      {flag[i] = 1;
       c-=w[i];
      }
   }
 if(m[n][c]>0)
   flag[n] = 1;
}

void printResult(int flag[], int w[],int v[],int m[][CONTENT+1])
{int i;
 printf(" num  weight value\n");
 for(i=0; i<=NUM-1; i++)
   if(flag[i]==1)
     printf("%3d%7d%5d\n",i,w[i],v[i]);
 printf("content is %d,",CONTENT);
 printf("the max value is: %d\n", m[0][CONTENT]);

}

int main()
{int value [NUM] = { 5,2,3,9,3,6,5,7,8,2};
 int weight [NUM] = {2,1,3,5,7,3,6,2,6,3};
 int c=CONTENT;
 int maxvalue[NUM][CONTENT+1];
 int flag[NUM]={0};
 clrscr();
 knapsack(value,weight,c,maxvalue);
 traceback(flag,weight,maxvalue);
 printResult(flag,weight,value,maxvalue);
 getch();
 return 0;
}
