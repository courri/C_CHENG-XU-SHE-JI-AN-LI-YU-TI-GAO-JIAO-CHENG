#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAX_SEQSTACK 100
typedef struct DT
{
	int location;
	int movers;
}DataType;
struct  SeqStack  /* 顺序栈类型定义 */
 { 	
	    int MAXNUM;
	     int  t; 			/* t<MAXNUM，指示栈顶位置，而不是元素个数 */
	     DataType  *s;	
};

typedef  struct SeqStack  *PSeqStack;	/* 顺序栈类型的指针类型 */
PSeqStack CreateEmptyStack_seq()
{
	     PSeqStack p;
	     p=(PSeqStack)malloc(sizeof(struct SeqStack));
	     p->MAXNUM=MAX_SEQSTACK;
	     p->t=-1;
	     p->s=(DataType *)malloc(sizeof(DataType)*(p->MAXNUM));
	     return p;
}

void  push_seq( PSeqStack pastack, DataType x )
/* 在栈中压入一元素x */
{   if( pastack->t >= pastack->MAXNUM - 1  )
        printf( "Overflow! \n" );
    else
	    {    pastack->t = pastack->t + 1;
	         pastack->s[pastack->t] = x;
	     }
}

void  pop_seq( PSeqStack pastack )
/* 删除栈顶元素 */
{   	if (pastack->t == -1 )
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
{    	if (pastack->t == -1 )    
          	printf("Error.\n");
    else
         return (pastack->s[pastack->t]);
}
/*个体状态判断函数*/
int farmer(int location) {     /*判断农夫的位置*/
    return (0 != (location & 0x08));
}
int wolf(int location) {      /*判断狼的位置*/
    return (0 != (location & 0x04));
}
int cabbage(int location) {    /*判断白菜的位置*/
    return (0 != (location & 0x02));
}
int goat(int location) {       /*判断羊的位置*/
    return (0 !=(location & 0x01));
}

/*安全状态的判断函数*/
int safe(int location)
{    /* 若状态安全则返回true */
     if ((goat(location) == cabbage(location)) && (goat(location) != farmer(location)) )  
         return (0); /* 羊吃白菜*/
     if ((goat(location) == wolf(location)) && (goat(location) != farmer(location)))  
         return (0); /* 狼吃羊*/
    return (1);
}
void farmerProblem( )
{
	int i, location, newlocation;
	int route[16];        /*用于记录已考虑的状态路径*/
	DataType x,y;
	PSeqStack moveTo;
	moveTo=CreateEmptyStack_seq();
	x.location=0x00;
	x.movers=1;
	push_seq(moveTo,x);
	for(i=0;i<16;i++)
		     route[i]=-1;
	route[0]=0;
	while(!isEmptyStack_seq(moveTo)&&route[15]==-1)
	{
		x=top_seq(moveTo);
		pop_seq(moveTo);
		while(x.movers<=8)
		{
			if((0!=(x.location&0x08))==(0!=(x.location&x.movers)))
			{
				newlocation=x.location^(0x08|x.movers);
				if(safe(newlocation)&&route[newlocation]==-1)
				{
					route[newlocation]=x.location;
					y.location=newlocation;
					y.movers=1;
					push_seq(moveTo,y);
					if(newlocation==15) break;
				}
			}
			x.movers<<=1;
		}
	}
	if(route[15]!=-1)  /*打印路径*/
	     {
		         printf("The reverse path is:\n");
		         for(location=15;location>=0;location=route[location])
		         {
			             printf("The Location is:%d\n",location);
			             if(location==0) break;
		          }
	      }
	    else
		          printf("NO Solution.\n");
	free(moveTo->s);
	free(moveTo);


	
}
int main()
{
	farmerProblem();
	return 0;
}