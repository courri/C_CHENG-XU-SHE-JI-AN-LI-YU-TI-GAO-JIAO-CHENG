#include <stdio.h>
int main()
{char c;
 int n=0;
while( (c = getchar()) !='\n')   
   if(c>=65 && c<=90)
     n++;
 printf("%d\n", n);
 return 0;
}


