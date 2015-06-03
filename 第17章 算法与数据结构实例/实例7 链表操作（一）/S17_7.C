#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 10

typedef struct node
{
  char name[20];
  struct node *link;
}stud;

void del_list(stud *head);

stud *create()
{
 stud *p,*h,*s;
 int i,n;
 puts("\nPlease input the number of linklist:");
 scanf("%d",&n);
 if((h=(stud *)malloc(sizeof(stud)))==NULL)
   {
     printf("no space!");
     return NULL;
   }
 h->name[0]='\0';
 h->link=NULL;
 p=h;
 for(i=0;i<n;i++)
   {
     if((s= (stud *) malloc(sizeof(stud)))==NULL)
       {
	printf("no space!");
	del_list(h);
	return NULL;
       }
     p->link=s;
     printf("please input %d student's name: ",i+1);
     scanf("%s",s->name);
     s->link=NULL;
     p=s;
   }
 return(h);
}

stud * search(stud *h,char *x)
{
 stud *p;
 p=h->link;
 while(p!=NULL)
   {
     if(strcmp(p->name,x)==0)
       return(p);
     else
       p=p->link;
   }
 printf("data not find!");
 return NULL;
}

stud * search2(stud *h,char *x)
{
 stud *p,*s;
 p=h->link;
 s=h;
 while(p!=NULL)
   {
    if(strcmp(p->name,x)==0)
      return(s);
    else
      { s=p;
	p=p->link;
      }
   }
 printf("data not find!");
 return NULL;
}

int insert(stud *p)
{char stuname[20];
 stud *s;
 if((s= (stud *) malloc(sizeof(stud)))==NULL)
    {
     printf("no space!");
     return 0;
    }
 printf("\nplease input the student's name: ");
 scanf("%s",stuname);
 strcpy(s->name,stuname);
 s->link=p->link;
 p->link=s;
 return 1;
}

void del(stud *x,stud *y)
{ x->link=y->link;
  free(y);
}

void print(stud *h)
{ stud *p;
  p=h->link;
  printf("Now the link list is:\n");
  while(p!=NULL)
    {
      printf("%s ",p->name);
      p=p->link;
    }
  printf("\n");
}

void del_list(stud *head)
{
 stud *p1,*p2;
 p1=head;
 while(p1!=NULL)
   { p2=p1;
     p1=p1->link;
     free(p2);
   }

 clrscr();
 puts("\n Thanks!\n Press any key to quit...");
 getch();
}

void menu(void)
{
 clrscr();
 printf("       simple linklise realization of c\n");
 printf("    ||=====================================||\n");
 printf("    ||                                     ||\n");
 printf("    || [1]  create linklist                ||\n");
 printf("    || [2]  seach                          ||\n");
 printf("    || [3]  insert                         ||\n");
 printf("    || [4]  delete                         ||\n");
 printf("    || [5]  print                          ||\n");
 printf("    || [6]  exit                           ||\n");
 printf("    ||                                     ||\n");
 printf("    || if no list exist, create list first ||\n");
 printf("    ||                                     ||\n");
 printf("    ||=====================================||\n");
 printf("      Please input your choose(1-6): ");
}

int main()
{int choose;
 stud *head = NULL, *searchpoint, *forepoint;
 char fullname[20];
 while(1)
   {
    menu();
    scanf("%d",&choose);
    switch(choose)
      {
       case 1:  clrscr();
		if(head!=NULL)
		  {puts("Linklist already exist!\nPress any key to return...\n");
		   getch();
		   break;
		  }
		if((head=create()) != NULL)
		  puts("Linklist created successfully! \nPress any key to return...");
            	getch();
		break;
       case 2:
            	clrscr();
                printf("Input the student's name which you want to find:\n");
                scanf("%s",fullname);
                if((searchpoint=search(head,fullname)) != NULL)
		printf("The stud name is:%s", searchpoint->name);
                printf("\nPress any key to returen...");
		getch();
                break;
       case 3:
                clrscr();
		if(head == NULL)
		  {
		   printf("no list.\n");
		   printf("\nPress any key to returen...");
		   getch();
		   break;
		  }
                if(insert(head))
                  print(head);
                printf("\nPress any key to returen...");
		getch();
                break;
       case 4:
                clrscr();
                print(head);
                printf("\nInput the student's name which you want to delete:\n");
                scanf("%s",fullname);
                searchpoint=search(head,fullname);
                if(searchpoint)
		  {
		   forepoint = search2(head,fullname);
		   del(forepoint, searchpoint);
		   print(head);
		   puts("\nsuccessfully!");
		  }
                printf("\nPress any key to returen...");
		getch();
                break;
       case 5:  print(head);
                printf("\nPress any key to return...");
		getch();
                break;
       case 6:  del_list(head);
                exit(0);
       default:
                clrscr();
                printf("Illegal letter! Press any key to return...");
                menu();
                getchar();
      }
   }
 return 0;
}

