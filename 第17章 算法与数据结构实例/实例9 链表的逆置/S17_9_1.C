#include "stdio.h"
#include "stdlib.h"
struct Student
{int n;
 struct Student *next;
};

int main()
{struct Student *head;
 void create(struct Student**);
 struct Student* reverse(struct Student*);
 void print(struct Student*);
 void del_list(struct Student*);
 create(&head);
 print(head);
 head=reverse(head);
 print(head);
 del_list(head);
 return 0;
}

void create(struct Student **p)
{struct Student *p1,*p2;
 int i,n;
 *p=NULL;
 printf("Please input n:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {  p1=(struct Student*)malloc(sizeof(struct Student));
    if(p1==NULL)
      break;
    p1->n=i;
    if(i==1)
      *p=p1;
    else
      p2->next=p1;
    p1->next=NULL;
    p2=p1;
 } 
}

void print(struct Student *head)
{struct Student *p=head;
 while(p!=NULL)
   {printf("%4d",p->n);
    p=p->next;
   }
 printf("\n");
}

struct Student* reverse(struct Student *head)
{struct Student *p1,*p2,*t;
 if(head!=NULL)
   {
    p1=p2=head;
    p1=p1->next;
    while(p1!=NULL)
      {t=p1->next;
       p1->next=p2;
       if(p2==head)
	 p2->next=NULL;
       p2=p1;
       p1=t;
      }
    head=p2;
   }
 return head;
}

void del_list(struct Student*head)
{struct Student *p1,*p2;
 p1=head;
 while(p1!=NULL)
 {  p2=p1;
    p1=p1->next;
    free(p2);
 }
}