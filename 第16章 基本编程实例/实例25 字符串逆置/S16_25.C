#include <string.h>
#include <stdio.h>
void reverse(char *p)
{int  n, i, t;
 n = strlen(p);
 for(i=0; i<n/2; i++)
   {
    t = p[i];
    p[i] = p[n-i-1];
    p[n-i-1] = t;
   }
}

int main()
{char s[50];
 gets(s);
 reverse(s);
 puts(s);
 getch();
 return 0;
}