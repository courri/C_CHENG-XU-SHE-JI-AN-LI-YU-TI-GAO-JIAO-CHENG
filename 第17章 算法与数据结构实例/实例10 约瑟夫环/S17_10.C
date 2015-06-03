#include "stdio.h"
#include "stdlib.h"

struct Boy
{int n;
 struct Boy *next;
};

void create(struct Boy**,int);
struct Boy* proceed(struct Boy*,int,int,int);
void print(struct Boy*);
void del(struct Boy*);

int main()
{struct Boy *head;
 int n,k,m;
 clrscr();
 puts("Please input n,k,m:");
 scanf("%d,%d,%d",&n,&k,&m);
 create(&head,n);
 head=proceed(head,n,k,m);
 print(head);
 del(head);
 getch();
 return 0;
}

void create(struct Boy **p,int n)
{struct Boy *p1,*p2;
 int i;
 for(i=1;i<=n;i++)
   {p1=(struct Boy*)malloc(sizeof(struct Boy));
    if(p1==NULL)
      {
       printf("no space.\n");
       *p=NULL;
       return;
      }
    p1->n=i;
    if(i==1)
       *p=p1;
    else
       p2->next=p1;
    p2=p1;
    p1->next=*p;
   }
}

void print(struct Boy *head)
{struct Boy *p=head;
 while(1)
   {printf("%5d",p->n);
    p=p->next;
    if(p==head)
      break;
   }
}

struct Boy* proceed(struct Boy *head,int n,int k,int m)
{struct Boy *p1,*p2;
 int i,count,min;
 p1=p2=head;
 for(count=1;count<=n-m;count++)
   {for(i=1;i<k;i++)
      {p2=p1;
       p1=p1->next;
      }

    p2->next=p1->next;
    p2=p1;
    p1=p1->next;
    free(p2);
   }
 head=p1;

 min=p1->n;
 for(i=1;i<=m;i++)
   {p1=p1->next;
    if(min>p1->n)
      {head=p1;
       min=p1->n;
      }
   }
 return head;
}

void del(struct Boy *head)
{struct Boy *p1,*p2;
 p1=head;
 if(p1!=NULL)
   while(1)
     {p2=p1;
      p1=p1->next;
      free(p2);
      if(p1==head)
	break;
     }
}