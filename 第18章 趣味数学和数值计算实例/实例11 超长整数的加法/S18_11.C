#include<stdio.h>
#include<stdlib.h>
#define HUNTHOU 10000
typedef struct node{
	int data;
	struct node *next;
}NODE;                 /*定义链表结构*/
struct number {
	int num;
	struct number *np;
};

void freelist(NODE* llist);
void freelist2(struct number* llist);
NODE *insert_after(NODE *u,int num); /*在u结点后插入*/
NODE *AddInt(NODE *p,NODE *q); /*完成加法操作返回指向结果的指针*/
void printint(NODE *s);
NODE *inputint(void);

int main()
{
	NODE *s1,*s2,*s;
	clrscr();
	printf(">> Input S1= ");
	s1 = inputint();            /*输入被加数*/
	if(s1 == NULL) {
		return 0;
	}
	printf(">> Input S2= ");
	s2 = inputint();            /*输入加数*/
	if(s2 == NULL) {
		freelist(s1);
		return 0;
	}
	printf(">> The addition result is as follows.\n\n");
	printf("    S1="); printint(s1); putchar('\n'); /*显示被加数*/
	printf("    S2="); printint(s2); putchar('\n'); /*显示加数*/
	s = AddInt(s1,s2);                                  /*求和*/
	if(s == NULL) {
		freelist(s1);
		freelist(s2);
		return 0;
	}
	printf(" S1+S2="); printint(s); putchar('\n'); /*输出结果*/
	freelist(s1);
	freelist(s2);
	freelist(s);
	printf("\n\n Press any key to quit...");
	getch();
	return 0;
}
NODE *insert_after(NODE *u,int num)
{
	NODE *v;
	v = (NODE *)malloc(sizeof(NODE)); /*申请一个NODE*/
	if( v == NULL){
		return NULL;
	}
	v->data = num;                        /*赋值*/
	u->next = v;                           /*在u结点后插入一个NODE*/
	return v;
}
NODE *AddInt(NODE *p,NODE *q) /*返回指向*p+*q结果的指针*/
{
	NODE *pp,*qq,*r,*s,*t,*tmp;
	int total,number,carry;
	pp = p->next;
	qq = q->next;
	s = (NODE *)malloc(sizeof(NODE));   /*建立存放和的链表头*/
	if( s == NULL){
		return NULL;
	}
	s->data = -1;
	t= tmp = s; 
	carry = 0;                             /*carry: 进位*/
	while(pp->data != -1 && qq->data != -1){  /*均不是头结点*/
		total = pp->data + qq->data + carry; /*对应位求和*/
		number = total%HUNTHOU;          /*求出存入链中部分的数值 */
		carry = total/HUNTHOU;           /*算出进位*/
		tmp = insert_after(t, number);   /*将部分和存入s指向的链中  */    
		if(tmp == NULL){
			t->next = s; 
			freelist(s);
			return NULL;
		}
		t = tmp; 
		pp = pp->next;                     /*分别取后面的加数*/
		qq = qq->next;
	}
	
	r = (pp->data != -1) ? pp:qq;     /*取尚未自理完毕的链指针*/
	while(r->data != -1) {             /*处理加数中较大的数*/
		total = r->data + carry;         /*与进位相加*/
		number = total%HUNTHOU;       /*求出存入链中部分的数值*/
		carry = total/HUNTHOU;        /*算出进位*/
		tmp = insert_after(t,number);  /*将部分和存入s指向的链中*/
		if(tmp == NULL){
			t->next = s; 
			freelist(s);
			return NULL;
		}
		t = tmp;
		r = r->next;                   /*取后面的值*/
	}
	if(carry)
		tmp = insert_after( t, 1);    /*处理最后一次进位*/
	if(tmp == NULL){
		t->next = s; 
		freelist(s);
		return NULL;
	}
	t = tmp;
	t->next = s;                    /*完成存和的链表*/
	return s;                      /*返回指向和的结构指针*/
}
NODE *inputint(void)     /*输入超长正整数*/
{
	NODE *s,*ps,*qs;
	struct number *p,*q,*pre;
	int i ,k;
	long sum;
	char c;
	p = NULL;  /*用来指向输入的整数，链首为整数的最低位，链尾为最高位*/
	while((c=getchar()) != '\n')   /*输入整数，按字符接收数字*/
		if(c >= '0' && c <= '9') {        /*若为数字则存入*/
			q = (struct number*)malloc(sizeof(struct number));
			
			if( q == NULL){
				freelist2(p);
				return NULL;
			}
			
			q->num = c-'0';           /*存入一位整数*/
			q->np = p;                /*建立指针*/
			p = q;
		}
		s = (NODE *)malloc(sizeof(NODE));
		if( s == NULL){
			freelist2(p);
			return NULL;
		}
		s->data = -1;                  /*建立表求超长正整数的链头*/
		ps = s;
		while(p != NULL) {   /*转换*/
			sum = 0;
			i = 0;
			k = 1;
			while(i < 4 && p != NULL) {     /*取出低四位*/
				sum = sum + k*(p->num);   
				i++; 
				pre = p;
				p = p->np;
				k = k*10;
				free(pre);
			}
			qs = (NODE *)malloc(sizeof(NODE));  
			if( qs == NULL){
				ps->next = s;
				freelist(s);
				return NULL;
			}
			qs->data = sum;                  /*赋值，建立链表*/
			ps->next = qs;
			ps = qs;
		}
		ps->next = s;
		return s;
}
void printint(NODE *s)
{
	int i, k;
	if(s->next->data != -1) {      /*若不是头结点，则输出*/
		printint(s->next);             /*递归输出*/
		if(s->next->next->data == -1)
			printf("%d", s->next->data);
		else{
			k = HUNTHOU;
			for(i = 1;  i <= 4;  i++,k/=10)
				putchar('0' + s->next->data % k/(k/10));
		}
	}
}
void freelist(NODE* llist)
{ 
	NODE* pnode = llist->next;
	NODE* p;
	while(pnode != llist){
		p = pnode;
		pnode = pnode->next;
		free(p);
	}
}
void freelist2(struct number* llist)
{
	struct number *p;
	while(llist)
	{
		p = llist;
		llist = llist->np;
		free(p);
	}	
}
