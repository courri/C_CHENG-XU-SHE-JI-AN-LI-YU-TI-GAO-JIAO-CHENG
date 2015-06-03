#include <stdio.h>
void change(char *p)
{if(*p >= 65 && *p <= 90 || *p >= 97 && *p <= 122)
   *p ^= 32;
}

int main()
{char s[20];
 int i;
 clrscr();
 gets(s);
 for(i=0; i<strlen(s); i++)
   change(s+i);
 printf("%s\n", s);
 getch();
 return 0;
}
