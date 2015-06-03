#include <stdio.h>
int main()
{char s[80];
 int i, n = 0;
 gets(s);
 for(i =0; s[i]!='\0'; i++)    
   if(s[i]>=65 && s[i]<=90)
     n++;
 printf("%d\n", n);
 return 0;
}


