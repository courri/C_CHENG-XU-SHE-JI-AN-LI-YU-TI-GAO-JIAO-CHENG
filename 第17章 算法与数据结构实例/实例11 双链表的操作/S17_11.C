#include "stdio.h"
#include "stdlib.h"

typedef  struct node{
  struct node *pre;
  int n;
  int score;
  struct node *next;
}Node;

void delAll(Node *head);

Node *create()
{int i, n,score;
 Node *p1, *head=NULL, *p2;
 printf("input student number:");
 scanf("%d",&n);
 for(i=1; i<=n; i++)
   {if((p1=(Node *)malloc(sizeof(Node)))==NULL)
      {printf("no space!\n");
       delAll(head);
       return NULL;
      }
   scanf("%d %d", &p1->n,&p1->score);
   if(i==1)
     {head=p1;
      p1->pre=NULL;
     }
   else
     {
      p2->next=p1;
      p1->pre=p2;
     }
   p2=p1;
   p2->next=NULL;
 }
 return head;
}


void print(Node *head)
{Node *p=head;
 while(p!=NULL)
   {printf("%3d,%3d,%p,%p,%p\n", p->n, p->score, p->pre, p, p->next);
    p=p->next;
   }
}

Node *insert(Node *head)
{Node *p,*stu;
 p=head;
 if((stu=(Node *)malloc(sizeof(Node)))==NULL)
   {printf("no space!\n");
    return head;
   }
 scanf("%d%d", &stu->n, &stu->score);
 if(p==NULL)
   {head=stu;
    stu->pre=NULL;
    stu->next=NULL;
   }
 else
   {while((stu->score>p->score)&&p->next!=NULL)
       p=p->next;
    if(stu->score<=p->score)
      {if(p==head)
	 {stu->pre=NULL;
	  stu->next=head;
	  head->pre=stu;
	  head=stu;
	 }
       else
	 {p->pre->next=stu;
	  stu->pre=p->pre;
	  stu->next=p;
	  p->pre=stu;
	 }
      }
    else
      {p->next=stu;
       stu->pre=p;
       stu->next=NULL;
      }
   }
 return head;
}

Node *del(Node *head)
{Node *p,*stu;
 int n;
 p=head;
 if(p==NULL)
   {printf("no data!\n");
    return head;
   }
 scanf("%d", &n);
 while((p->n!=n)&&p->next!=NULL)
   p=p->next;
 if(p->n==n)
   {if(p==head)
      {head=p->next;
       head->pre=NULL;
      }
    else
      {if(p->next!=NULL)
	 {p->pre->next=p->next;
	  p->next->pre=p->pre;
	 }
       else
	 p->pre->next=NULL;
      }
    free(p);
   }
 else
   printf("no this student!\n");
 return head;
}


void delAll(Node *head)
{Node *p,*t;
 p=head;
 while(p!=NULL)
   {t=p->next;
    free(p);
    p=t;
   }
}

int main()
{Node *head;
 int i;
 head=create();
 if(head==NULL)
   exit(0);
 print(head);

 for(i=1;i<=3;i++)
   {printf("delete:");
    head=del(head);
    print(head);
   }
 for(i=1;i<=3;i++)
   {printf("insert:");
    head=insert(head);
    print(head);
   }
 delAll(head);
 getch();
 return 0;
}