#include <stdio.h>
void reverse(char *s)
{if(*s)
   {
    reverse (s+1);
    printf("%c",*s);
   }
}

int main()
{char s[50];
 gets(s);
 reverse(s);
 printf("\n");
 getch();
 return 0;
}