#include <stdio.h>
#include <stdlib.h>
int main()
{
 int a;
 FILE *fp;
 if((fp = fopen("text.txt","w+")) == NULL) 
    exit(1);
 fprintf(fp, "%d\n", 10000);         /*text.txt文件长度是5+2=7*/
 rewind(fp);                         /*使读写指针指向文件头*/
 a = getw(fp);  
 printf("%d\n", a);                 /*输出结果：12337*/
 return 0;
}
