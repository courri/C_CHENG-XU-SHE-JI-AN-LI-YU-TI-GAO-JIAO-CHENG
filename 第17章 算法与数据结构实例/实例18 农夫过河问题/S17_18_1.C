#include <stdio.h>
#include <stdlib.h>
#define DataType int
#define MaxQueue 100

struct  SeqQueue{	      /* 顺序队列类型定义 */
int  MAXNUM;      /* 队列中最大元素个数 */
int  f,r;
DataType  *q;
};
typedef  struct SeqQueue  *PSeqQueue;	/* 顺序队列类型的指针类型 */
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
    return (1);	 /* 其他状态是安全的*/
}

PSeqQueue createEmptyQueue_seq()
{
	PSeqQueue paqu;
	paqu=(PSeqQueue)malloc(sizeof(struct SeqQueue));
    if(paqu == NULL)
        return NULL;
	paqu->MAXNUM=MaxQueue;
	paqu->f=paqu->r=0;
	paqu->q=(DataType *)malloc(sizeof(DataType)*paqu->MAXNUM);
	return paqu;

}
int isEmptyQueue_seq(PSeqQueue paqu)
{
	if(paqu->f==paqu->r)
		return 1;
	else
		return 0;
}

void  enQueue_seq( PSeqQueue paqu, DataType x )
/* 在队尾插入元素x */
{ if( (paqu->r + 1) %paqu->MAXNUM == paqu->f  )
     printf( "Full queue.\n" );
  else { paqu->q[paqu->r] = x;
	   paqu->r = (paqu->r + 1) % paqu->MAXNUM;
	 }
}

void  deQueue_seq( PSeqQueue paqu )
/* 删除队列头部元素 */
{
 		if( paqu->f == paqu->r )
			printf( "Empty Queue.\n" );		
  		else
		paqu->f = (paqu->f + 1) % paqu->MAXNUM;
}

DataType  frontQueue_seq( PSeqQueue paqu )
{ 	if( paqu->f == paqu->r )
		printf( "Empty Queue.\n" );
  		else
     return (paqu->q[paqu->f]);
 }
/*农夫过河主程序*/
void farmProblem()
{
	int i,movers,location,newlocation;
	int route[16] ;   /*记录已考虑的状态*/
	PSeqQueue moveTo;
	moveTo=createEmptyQueue_seq();
    if(moveTo == NULL)
        return ;

	enQueue_seq(moveTo,0x00);
	for(i=0;i<16;i++)
		route[i]=-1;
	route[0]=0;
	/*开始移动*/
	while(!isEmptyQueue_seq(moveTo))
	{
		location=frontQueue_seq(moveTo);
		deQueue_seq(moveTo);
		for(movers=1;movers<=8;movers<<=1)
		{
			if((0!=(location&0x08))==(0!=(location&movers)))
			{
				newlocation=location^(0x08|movers);
				if(safe(newlocation)&&(route[newlocation]==-1))
				{
					route[newlocation]=location;
					enQueue_seq(moveTo,newlocation);
				}
			}
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
		free(moveTo->q);
	  free(moveTo);

}

int main()
{
	farmProblem();
	return 0;
}
