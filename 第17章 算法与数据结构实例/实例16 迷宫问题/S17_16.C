#include <stdio.h>
#include <stdlib.h>
#define M 8
#define N 11
typedef struct
{
	int x,y,d;
}DataType;
struct  SeqStack  /* 顺序栈类型定义 */
 {
	int MAXNUM;
	int  t; 			/* t<MAXNUM，指示栈顶位置，而不是元素个数 */
	DataType  *s;
};
typedef  struct SeqStack  *PSeqStack;	/* 顺序栈类型的指针类型 */
PSeqStack CreateEmptyStack_seq(int n)
{
	PSeqStack p;
	p=(PSeqStack)malloc(sizeof(struct SeqStack));
	p->MAXNUM=n;
	p->t=-1;
	p->s=(DataType *)malloc(sizeof(DataType)*(p->MAXNUM));
	return p;
}

void  push_seq( PSeqStack pastack, DataType x )
/* 在栈中压入一元素x */
{  if( pastack->t >= pastack->MAXNUM - 1  )
      printf( "Overflow! \n" );
  else
	{  pastack->t = pastack->t + 1;
	   pastack->s[pastack->t] = x;
	 }
}

void  pop_seq( PSeqStack pastack )
/* 删除栈顶元素 */
{  	if (pastack->t == -1 )
	printf( "Underflow!\n" );
    else
	pastack->t = pastack->t - 1;
}
int isEmptyStack_seq(PSeqStack pastack)
{
	if(pastack->t==-1)
		return 1;
	else
		return 0;
}

DataType  top_seq( PSeqStack pastack )
/* 当pastack所指的栈不为空栈时，求栈顶元素的值 */
{ 	if (pastack->t == -1 )
    	printf("Error!\n");
    else
         return (pastack->s[pastack->t]);
}

void mazePath(int maze[M][N],int direction[4][2],int x1,int y1,int x2,int y2,int m,int n)
/* 迷宫maze[M][N]中求从入口maze[x1][y1]到出口maze[x2][y2]的一条路径 */
/* 其中 1<=x1,x2<=M-2 , 1<=y1,y2<=N-2 */
{
	int i,j,k; 
	int g,h;
	PSeqStack  st;
	DataType element;
	st = CreateEmptyStack_seq(m*n);
    if(st == NULL)
      return;
	maze[x1][y1] = 2;  							
	element.x = x1;	  
	element.y = y1;
	element.d = -1;
	push_seq(st,element);   						  
	while (! isEmptyStack_seq(st))   				 
	{ 
		element = top_seq(st);
		pop_seq(st);
		i = element.x;
		j = element.y;
		k = element.d + 1;
		while (k<=3)  							
		{
			g = i + direction[k][0];
			h = j + direction[k][1];
			if (g==x2 && h==y2 && maze[g][h]==0)   
			{ 
				printf("The revers path is:\n");   			
				printf("the node is: %d %d \n",g,h);
				printf("the node is: %d %d \n",i,j);
				while(!isEmptyStack_seq(st))
				{
					element=top_seq(st);
					pop_seq(st);
					printf("the node is: %d %d \n",element.x,element.y);
				}
                free(st->s);  
	            free(st);
				return;
			}
			if (maze[g][h]==0)   				 
			{ 
				maze[g][h] = 2;   				 
				element.x = i;	  
				element.y = j;
				element.d = k;
				push_seq(st,element);  			
				i = g;     						
				j = h;
				k = -1;
			}	   
			k = k + 1;
		}
	}
	printf("The path has not been found.\n"); 	
	free(st->s);
	free(st);
}
int main()
{
	int maze[M][N]={{1,1,1,1,1,1,1,1,1,1,1},
		          {1,0,1,0,0,1,1,1,0,0,1},
				  {1,0,0,0,0,0,1,0,0,1,1},
				  {1,0,1,1,1,0,0,0,1,1,1},
				  {1,0,0,0,1,0,1,1,0,1,1},
				  {1,1,0,0,1,0,1,1,0,0,1},
				  {1,1,1,0,0,0,0,0,0,0,1},
				  {1,1,1,1,1,1,1,1,1,1,1},
	};
	int direction[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

	mazePath(maze,direction,1,1,6,9,M,N);
	return 0;
}
