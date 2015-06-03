#include <stdio.h>
int main()
{void count(char*, int*);
 char s[80];
 int num;
 clrscr();
 gets(s);
 count(s, &num);
 printf("%d\n", num);
 getch();
 return 0;
}

void count(char*str, int *p)
{int i;
 *p=0;
 for(  ; *str!='\0'; str++)
   if(*str>=65&&*str<=90||*str>=97&&*str<=122)
     (*p)++;
}

