#include <stdio.h>
#include <malloc.h>
#define DataType char
#define TRUE  1
#define FALSE 0
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
	p->MAXNUM=MAX_SEQSTACK;
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
    	 return -1;
    else
         return (pastack->s[pastack->t]);
}

int infixtoSuffix(char *infix,char *suffix)
/*将中缀表达式转换为后缀表达式，成功返回TRUE,如发现非法，则返回FALSE*/
{
	int state_int=FALSE;
	char c,c2;
	int i,j=0;
	PSeqStack ps=CreateEmptyStack_seq();
    if(ps == NULL)
      return FALSE;

	if(infix[0]=='\0')
    { 
     free(ps->s);
     free(ps);
     return FALSE;
	}
    for(i=0;infix[i]!='\0';i++)
	{
		c=infix[i];
		switch(c)
		{
		case ' ':case '\t':case '\n':
			if(state_int==TRUE)suffix[j++]=' ';
			state_int=FALSE;
			break;
		case '0':case '1':case '2':case '3':case '4':
		case '5':case '6':case '7':case '8':case '9':
			state_int=TRUE;
			suffix[j++]=c;      
			break;
		case'(':
			if(state_int==TRUE) suffix[j++]=' ';
			state_int=FALSE;
			push_seq(ps,c);
			break;
		case')':
			if(state_int==TRUE) suffix[j++]=' ';
			state_int=FALSE;
			c2=')';
			while(!isEmptyStack_seq(ps))
			{
				c2=top_seq(ps);
				pop_seq(ps);
				if(c2=='(') break;
				suffix[j++]=c2;
			}
			if(c2!='(')
			{
				free(ps->s);
                free(ps);
				suffix[j++]='\0';
				return FALSE;  
			}
			break;
		case'+':case'-':
			if(state_int==TRUE) suffix[j++]=' ';
			state_int=FALSE;
		    while(!isEmptyStack_seq(ps))
			{
				c2=top_seq(ps);
				if(c2=='+'||c2=='-'||c2=='*'||c2=='/')
				{
					pop_seq(ps);
					suffix[j++]=c2;
				} 
				else
					break;
			}
			push_seq(ps,c);
			break;
		case'*':case'/':
			if(state_int==TRUE) suffix[j++]=' ';
			state_int=FALSE;
			while(!isEmptyStack_seq(ps))
			{
				c2=top_seq(ps);
				if(c2=='*'||c2=='/')
				{
					pop_seq(ps);
					suffix[j++]=c2;
				} 
				else
					break;
			}
			push_seq(ps,c);
			break;
		default:  
			free(ps->s);
            free(ps);
			suffix[j++]='\0';
			return FALSE;
		}
	}
	if(state_int==TRUE) suffix[j++]=' ';
	while(!isEmptyStack_seq(ps))
	{
		c2=top_seq(ps);
		pop_seq(ps);
		if(c2=='(')
		{   free(ps->s);
			free(ps);
			suffix[j++]='\0';
			return FALSE;
		}
		suffix[j++]=c2;
	}
	free(ps->s);
	free(ps);
	suffix[j++]='\0';
	return TRUE;
}
int calculateSuffix(char *suffix,int *presult)

{
	int state_int=FALSE;
	int num=0,num1,num2;
	int i;
	char c;
	PSeqStack ps=CreateEmptyStack_seq();
	if(ps == NULL)
	  return FALSE;
	for(i=0;suffix[i]!='\0';i++)
	{
		c=suffix[i];
		switch(c)
		{
		case '0':case '1':case '2':case '3':case '4':
		case '5':case '6':case '7':case '8':case '9':
			if(state_int==TRUE) num=num*10+c-'0';
			else num=c-'0';
			state_int=TRUE;
			break;
		case' ':case'\t':case'\n':
			if(state_int==TRUE)
			{
				push_seq(ps,num);
				state_int=FALSE;
			}
			break;
		case'+':case'-':case'*':case'/':
			if(state_int==TRUE)
			{
				push_seq(ps,num);
				state_int=FALSE;
			}
			if(isEmptyStack_seq(ps))
			{   free(ps->s);
				free(ps);
				return FALSE;
			}
			num2=top_seq(ps);
			pop_seq(ps);
			if(isEmptyStack_seq(ps))
			{   free(ps->s);
				free(ps);
				return FALSE;
			}
			num1=top_seq(ps);
			pop_seq(ps);
			if(c=='+')push_seq(ps,num1+num2);
			if(c=='-')push_seq(ps,num1-num2);
			if(c=='*')push_seq(ps,num1*num2);
			if(c=='/')
			{
				if(num2==0)
				{ free(ps->s);
				  free(ps);
				  return FALSE;
				}
				push_seq(ps,num1/num2);
			}
			break;
		default:
			free(ps->s);
			free(ps);
			return FALSE;
		}
	}
	*presult=top_seq(ps);
	pop_seq(ps);
	if(!isEmptyStack_seq(ps))
	{   free(ps->s);
	    free(ps);
	    return FALSE;
	}
	free(ps->s);
	free(ps);
	return TRUE;
}
int main()
{
	char infix[80]="20+(3*(4+1)-5)/2-3*(2+1)";
	char suffix[80];
	int result;
	if(infixtoSuffix(infix,suffix)==TRUE)
	{
		if(calculateSuffix(suffix,&result)==TRUE)
			printf("The Reuslt is: %3d\n",result);
		else
			printf("Error!\n");
	}
	else
		printf("Input Error!\n");

	return 0;
}