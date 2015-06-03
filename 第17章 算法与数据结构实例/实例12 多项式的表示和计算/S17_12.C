#include <stdio.h>
#include <malloc.h>
#define MAX_CHARS_PER_LINE 10
struct Node {
  int coef;
  int power;
  struct Node *link;
};

typedef struct Node *PNode;
typedef struct Node *LinkList;

LinkList createNullList(void);
int append(LinkList llist,int coef,int power);
void freelist(LinkList llist);

LinkList createList(void)
/*返回创建成功的单链表，若创建失败，返回NULL*/
{
	LinkList llist;
	char buffer[MAX_CHARS_PER_LINE];
	int coef,power;
	llist=createNullList();
	if(llist==NULL)
	  return NULL;
	fgets(buffer,MAX_CHARS_PER_LINE,stdin);
	sscanf(buffer,"%d %d",&coef,&power);
	while(coef!=0||power!=0)
	{if(coef!=0)
	   if(append(llist,coef,power))
	     {
	      freelist(llist);
	      return NULL;
	     }
	   fgets(buffer,MAX_CHARS_PER_LINE,stdin);
	   sscanf(buffer,"%d %d",&coef,&power);
	}
	return llist;
}
/*其中调用函数定义如下*/
LinkList createNullList(void)
{
	LinkList llist;
	llist=(PNode)malloc(sizeof(struct Node));
	if(llist!=NULL)
	  llist->link=NULL;
	return llist;
}
int append(LinkList llist,int coef,int power)
{
	PNode pnode;
	pnode=llist;
	while(pnode->link!=NULL)
	  pnode=pnode->link;
	pnode->link=(PNode)malloc(sizeof(struct Node));
	pnode=pnode->link;
	if(pnode!=NULL)
	{
		pnode->coef=coef;
		pnode->power=power;
		pnode->link=NULL;
	}
	return pnode==NULL;
}
void freelist(LinkList llist)
{
	LinkList pnode=llist->link;
	LinkList p;
	while(pnode!=NULL)
	{
		p=pnode;
		pnode=pnode->link;
		free(p);
	}
}
LinkList add(LinkList a,LinkList b)/*a和b分别为两个数被加的多项式，返回和的多项式*/
{
	LinkList c;
	PNode cur_a,cur_b;
	c=createNullList();
	if(c==NULL)
		return NULL;
	cur_a=a->link;
	cur_b=b->link;
	while(cur_a!=NULL&&cur_b!=NULL)
	{
		if(cur_a->power>cur_b->power)
		{
			if(append(c,cur_a->coef,cur_a->power))
			{
				freelist(c);
				return NULL;
			}
			cur_a=cur_a->link;
		}
		else if(cur_a->power<cur_b->power)
		{
			if(append(c,cur_b->coef,cur_b->power))
			{
				freelist(c);
				return NULL;
			}
			cur_b=cur_b->link;

		}
		else
		{
			if(append(c,cur_a->coef+cur_b->coef,cur_a->power))
			{
				freelist(c);
				return NULL;
			}
			cur_a=cur_a->link;
			cur_b=cur_b->link;
		}
	}
	if(cur_a!=NULL)
	{
		while(cur_a!=NULL)
		{
			if(append(c,cur_a->coef,cur_a->power))
			{
				freelist(c);
				return NULL;
			}
			cur_a=cur_a->link;
		}
	}
	if(cur_b!=NULL)
	{
		while(cur_b!=NULL)
		{
			if(append(c,cur_b->coef,cur_b->power))
			{
				freelist(c);
				return NULL;
			}
			cur_b=cur_b->link;

		}
	}
	return c;
}
void print(LinkList head)
{LinkList p=head->link;
 while(p!=NULL)
   {printf("%d,%d\n",p->coef,p->power);
    p=p->link;
   }
}

int main()
{
	LinkList a,b,c;
	printf("Please input a:");          /*输入0 0表示结束*/
	if((a = createList()) == NULL)
	{
	  printf("Create List a fail\n");
	  return 0;
	}
	printf("Please input b:");
	if((b = createList()) == NULL)
	{
	  printf("Create List b fail\n");
	  freelist(a);
	  return 0;
	}
	if((c = add(a,b)) == NULL)
	  printf("Create List c fail\n");
	else
	{
	  print(c);      /*输出链表c*/
	  freelist(c);
	}
	freelist(a);
	freelist(b);
	return 0;
}