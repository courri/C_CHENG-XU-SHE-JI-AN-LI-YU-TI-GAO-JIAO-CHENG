#include "stdlib.h"
#include "stdio.h"
typedef struct student
  { int n;
    int score;
    struct student  *next;
  }stud;
void del_list(stud *head);
void creat(stud** h)
{stud *head,*p1,*p2;
 head=NULL;
 p1=p2=(stud *)malloc(sizeof(stud));
 if(p1==NULL)
   {printf("no space.\n");
    *h=NULL;
    return;
   }
 scanf("%d,%d",&p1->n,&p1->score);
 while(p1->n!=0)
    {if(head==NULL)
       head=p1;
     else
       p2->next=p1;
     p2=p1;
     p2->next=NULL;
     p1=(stud*)malloc(sizeof(stud));
     if(p1==NULL)
       {printf("no space.\n");
        del_list(head);
        *h=NULL;
        return;
       }
     scanf("%d,%d",&p1->n,&p1->score);
    }
 free(p1);
 *h=head;
}

void print(stud *p)
{while(p!=NULL)
   {printf("%d,%d\n",p->n,p->score);
    p=p->next;
   }
}
stud *delete(stud* head,int num)
{stud *p1,*p2;
 p1=head;
 while(p1!=NULL&&p1->n!=num)
    {p2=p1;
     p1=p1->next;
    }
 if(p1==NULL)
   printf("Not found\n");
 else
   {if(p1==head)
      head=p1->next;
    else
      p2->next=p1->next;
    free(p1);
   }
 return head;
}

stud *insert(stud *head,stud *stu)
{stud *p1,*p2;
 p1=head;
 if(p1==NULL)
   {head=stu;
    stu->next=NULL;
   }
 else
   {while((stu->score>p1->score)&&p1->next!=NULL)
      {p2=p1;
       p1=p1->next;
      }
    if(stu->score<=p1->score)
      {if(p1==head)
	 {head=stu;
	  stu->next=p1;
	 }
       else
	 {p2->next=stu;
	  stu->next=p1;
	 }
      }
    else
      {p1->next=stu;
       stu->next=NULL;
      }
   }
 return head;
}


int main()
{stud *head,*stu,*p1,*p2;
 int num;

 /**********   create  ************/
 printf("creat:\n");
 creat(&head);
 if(head==NULL)
   exit(0);
 print(head);

 /**********   delete  ************/
 printf("delete:");
 scanf("%d",&num);
 while(num!=0)
   {head=delete(head,num);
    printf("delete:");
    scanf("%d",&num);
   }
 print(head);

 /**********   insert  ************/
 stu=(stud*)malloc(sizeof(stud));
 while(stu!=NULL)
   {
    printf("insert:");
    scanf("%d,%d",&stu->n,&stu->score);
    if(stu->n==0)
      break;
    head=insert(head,stu);
    stu=(stud *)malloc(sizeof(stud));
   }
 if(stu!=NULL)
   free(stu);
 print(head);
 getch();
 del_list(head);
 return 0;
}

void del_list(stud *head)
{stud *p1,*p2;
 p1 = head;
 while(p1!=NULL)
   {
     p2 = p1;
     p1 = p1->next;
     free(p2);
   }
 clrscr();
 getch();
}



