#include <stdio.h>
#include <malloc.h>
#define DataType char
#define MAX_SEQSTACK 100
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
	     if(p==NULL)
	       return NULL;
	     p->MAXNUM=MAX_SEQSTACK;
	     p->t=-1;
	     p->s=(DataType *)malloc(sizeof(DataType)*(p->MAXNUM));
	    if(p->s==NULL)
	      {free(p);
	       return NULL;
	      }
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
	   return pastack->t == -1;
}

DataType  top_seq( PSeqStack pastack )
/* 当pastack所指的栈不为空栈时，求栈顶元素的值 */
{
		 return (pastack->s[pastack->t]);
}
int correct(char *exp)
{
	int i=0;
	DataType x;
	PSeqStack st;
	if((st=CreateEmptyStack_seq())==NULL)
	  return 0;
	do
	{
		x=*(exp+i);
		switch(x)
		{
		 case '{':case'[':case'(':
			push_seq(st,x);
			break;
		 case ')':
			if(isEmptyStack_seq(st))
			  {free(st->s);
			   free(st);
			   return 0;
			  }
			x=top_seq(st);
			if(x!='(')
			  {free(st->s);
			   free(st);
			   return 0;
			  }
			pop_seq(st);
			break;
		 case ']':
			if(isEmptyStack_seq(st))
			  {free(st->s);
			   free(st);
			   return 0;
			  }
			x=top_seq(st);
			if(x!='[')
			  {free(st->s);
			   free(st);
			   return 0;
			  }
			pop_seq(st);
			break;
		 case '}':
			if(isEmptyStack_seq(st))
			  {free(st->s);
			   free(st);
			   return 0;
			  }
			x=top_seq(st);
			if(x!='{')
			  {free(st->s);
			   free(st);
			   return 0;
			  }
			pop_seq(st);
			break;
		default:
			break;
		}
		i++;
	}while(x!='\0');
	if(!isEmptyStack_seq(st))
	  {free(st->s);
	   free(st);
	   return 0;
	  }
    free(st->s);
    free(st);
	return 1;
}

int main()
{
	char exp[80];
	gets(exp);
	if(correct(exp)==0)
		printf("Error\n");
	else
		printf("Ok\n");
	getch();
	return 0;
}