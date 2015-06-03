#include <stdio.h>
#include <string.h>
int palindrome(char *p)
{
 int  i,n;
 n = strlen(p);
 for(i=0; i<n/2; i++)
   {
    if(*(p+i)!=*(p+n-i-1))
      return 0;
   }
 return 1;
}

int main()
{char s[20];
 gets(s);
 if(palindrome(s) == 1)
   printf("是回文\n");
 else
   printf("不是回文\n");
 getch();
 return 0;
}
