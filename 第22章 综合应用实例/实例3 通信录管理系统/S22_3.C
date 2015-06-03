
#include "stdio.h"    /*I/O函数*/
#include "stdlib.h" 	/*标准库函数*/
#include "string.h"		/*字符串函数*/
#include "ctype.h" 	  /*字符操作函数*/

#define MAX 50  			/*定义常数表示记录数*/

struct ADDRESS				/*定义数据结构*/
{
   char name[15]; 	  /*姓名*/
   char units[20];    /*单位*/
   char phone[15];    /*电话*/
};


int  InputRecord(struct ADDRESS r[]); /*输入记录*/
void ListRecord(struct ADDRESS r[],int n); /*显示记录*/
int  DeleteRecord(struct ADDRESS r[],int n); /*删除记录*/
int  InsertRecord(struct ADDRESS r[],int n); /*插入记录*/
void SaveRecord(struct ADDRESS r[],int n); /*记录保存为文件*/
int  LoadRecord(struct ADDRESS r[]);  /*从文件中读记录*/
int  FindRecord(struct ADDRESS r[],int n,char *s) ; /*查找函数*/
void ShowRecord(struct ADDRESS temp); 	/*显示单条记录*/

void main()
{
   int i;
   char s[128];
   struct ADDRESS address[MAX];/*定义结构体数组*/
   int num;/*保存记录数*/
   clrscr();  
   while(1)
   {
		   clrscr();
		   printf("********************MENU*******************\n\n");
		   printf("|      0: Input records                   |\n");
		   printf("|      1: List records in the file        |\n");
		   printf("|      2: Delete a record                 |\n");
		   printf("|      3: Insert a record to the list     |\n");
		   printf("|      4: Save records to the file        |\n");
		   printf("|      5: Load records from the file      |\n");
		   printf("|      6: Quit                            |\n\n");
		   printf("*******************************************\n");
		   do{
		      printf("\n	Input your choice(0~6):"); /*提示输入选项*/
		      scanf("%s",s); /*输入选择项*/
		      i=atoi(s); /*将输入的字符串转化为整型数*/
		   }while(i<0||i>6); /*选择项不在0~11之间重输*/
      switch(i)   /*调用主菜单函数，返回值整数作开关语句的条件*/
      {
				 case 0:num=InputRecord(address);break;/*输入记录*/
				 case 1:ListRecord(address,num);break; /*显示全部记录*/
				 case 2:num=DeleteRecord(address,num);break; /*删除记录*/
				 case 3:num=InsertRecord(address,num);  break;   /*插入记录*/
				 case 4:SaveRecord(address,num);break; /*保存文件*/
				 case 5:num=LoadRecord(address); break; /*读文件*/
				 case 6:exit(0); /*如返回值为11则程序结束*/
      }
   }
}

/***输入记录，形参为结构体数组，函数值返回类型为整型表示记录长度*/
int  InputRecord(struct ADDRESS t[])
{
   int i,n;
   char *s;
   clrscr(); /*清屏*/
   printf("\n please input record num you want to input. \n"); /*提示信息*/
   scanf("%d",&n); /*输入记录数*/
   printf("please input the %d records \n",n); /*提示输入记录*/
   printf("name             units                 telephone\n");
   printf("------------------------------------------------\n");
   for(i=0;i<n;i++)
   {
      scanf("%s%s%s",t[i].name,t[i].units,t[i].phone);  /*输入记录*/
      printf("----------------------------------------------\n");
   }
   getch();
   return n;  /*返回记录条数*/
}
/*显示记录，参数为记录数组和记录条数*/
void ListRecord(struct ADDRESS t[],int n)
{
   int i;
   clrscr();
   printf("\n\n*******************ADDRESS LIST*****************\n");
   printf("name               units               telephone\n");
   printf("------------------------------------------------\n");
   for(i=0;i<n;i++)
   printf("%-13s%-20s%-15s\n",t[i].name,t[i].units,t[i].phone);
   printf("************************end*********************\n");
   getch();
}
/*显示指定的一条记录*/
void ShowRecord(struct ADDRESS temp)
{
   printf("\n\n************************************************\n");
   printf("name                units              telephone\n");
   printf("------------------------------------------------\n");
   printf("%-13s%-20s%-15s\n",temp.name,temp.units,temp.phone);
   printf("**********************end***********************\n");
   getch();
}
/*删除函数，参数为记录数组和记录条数*/
int DeleteRecord(struct ADDRESS t[],int n)
{
   char s[20];  /*要删除记录的姓名*/
   int i,j;
   clrscr();
   printf("please record name:\n"); /*提示信息*/
   scanf("%s",s);/*输入姓名*/
   i=FindRecord(t,n,s); /*调用FindRecord函数*/
   if(i>n-1)  /*如果i>n-1超过了数组的长度*/
      printf("Can't found the record\n"); /*显示没找到要删除的记录*/
   else
   {
     ShowRecord(t[i]); /*调用输出函数显示该条记录信息*/
		 for(j=i+1;j<n;j++)  /*删除该记录，实际后续记录前移*/
		 {
		    strcpy(t[j-1].name,t[j].name); /*将后一条记录的姓名拷贝到前一条*/
		    strcpy(t[j-1].units,t[j].units); /*将后一条记录的单位拷贝到前一条*/
		    strcpy(t[j-1].phone,t[j].phone); /*将后一条记录的电话拷贝到前一条*/
		 }
		 n--;  /*记录数减1*/
		 printf("Delete a record successfully!\n");
   }
   getch();
   return n;  /*返回记录数*/
}
/*插入记录函数，参数为结构体数组和记录数*/
int InsertRecord(struct ADDRESS t[],int n)/*插入函数，参数为结构体数组和记录数*/
{
   struct ADDRESS temp;  /*新插入记录信息*/
   int i,j;
   char s[20]; /*确定插入在哪个记录之前*/
   clrscr();
   printf("please input record\n");
   printf("************************************************\n");
   printf("name                units              telephone\n");
   printf("------------------------------------------------\n");
   scanf("%s%s%s",temp.name,temp.units,temp.phone); /*输入插入信息*/
   printf("------------------------------------------------\n");
   printf("please input locate name \n");
   scanf("%s",s); /*输入插入位置的姓名*/
   i=FindRecord(t,n,s);  /*调用FindRecord，确定插入位置*/
   for(j=n-1;j>=i;j--)   /*从最后一个结点开始向后移动一条*/
   {
      strcpy(t[j+1].name,t[j].name); /*当前记录的姓名拷贝到后一条*/
      strcpy(t[j+1].units,t[j].units); /*当前记录的单位拷贝到后一条*/
      strcpy(t[j+1].phone,t[j].phone); /*当前记录的电话拷贝到后一条*/
   }
   strcpy(t[i].name,temp.name); /*将新插入记录的姓名拷贝到第i个位置*/
   strcpy(t[i].units,temp.units); /*将新插入记录的单位拷贝到第i个位置*/
   strcpy(t[i].phone,temp.phone); /*将新插入记录的电话拷贝到第i个位置*/
   n++;   /*记录数加1*/
   getch();
   return n; /*返回记录数*/
}
/*保存函数，参数为结构体数组和记录数*/
void SaveRecord(struct ADDRESS t[],int n)
{
   int i;
   FILE *fp;  /*指向文件的指针*/
   clrscr();
   printf("Saving the records to the file address.txt\n.............\n");
   if((fp=fopen("address.txt","wb"))==NULL)  /*打开文件，并判断打开是否正常*/
   {
      printf("can not open file\n");/*没打开*/
      exit(1);  /*退出*/
   }
   printf("\nSaving the file\n"); /*输出提示信息*/
   fprintf(fp,"%d",n);  /*将记录数写入文件*/
   fprintf(fp,"\r\n");  /*将换行符号写入文件*/
   for(i=0;i<n;i++)
   {
      fprintf(fp,"%-20s%-30s%-10s",t[i].name,t[i].units,t[i].phone);/*格式写入记录*/
      fprintf(fp,"\r\n"); /*将换行符号写入文件*/
   }
   fclose(fp);/*关闭文件*/
   
   printf("Save the records successfully!\n"); /*显示保存成功*/
   getch();
}
/*读入函数，参数为结构体数组*/
int LoadRecord(struct ADDRESS t[])
{
   int i,n;
   FILE *fp; /*指向文件的指针*/
   if((fp=fopen("address.txt","rb"))==NULL)/*打开文件*/
   {
      printf("can not open file\n");  /*不能打开*/
      exit(1);  /*退出*/
   }
   fscanf(fp,"%d",&n); /*读入记录数*/
   for(i=0;i<n;i++)
      fscanf(fp,"%20s%30s%10s",t[i].name,t[i].units,t[i].phone); /*按格式读入记录*/
   fclose(fp);  /*关闭文件*/
   printf("You have successfully load files from file!\n"); /*显示保存成功*/
   getch();
   return n; /*返回记录数*/
}
/*查找函数，参数为记录数组和记录条数以及姓名s */
int FindRecord(struct ADDRESS t[],int n,char *s)
{
   int i;
   for(i=0;i<n;i++)/*从第一条记录开始，直到最后一条*/
   {
      if(strcmp(s,t[i].name)==0)  /*记录中的姓名和待比较的姓名是否相等*/
      return i;   /*相等，则返回该记录的下标号，程序提前结结束*/
   }
   return i;  /*返回i值*/
}