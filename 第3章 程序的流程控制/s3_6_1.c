#include<stdio.h>
int main()
{int i=0, count=0;
 char s[80];
 gets(s);
 while( s[i]!='\0'){
   if(s[i]>=65&&s[i]<=90)
     count++;
   i++;
 }
 printf("%d\n", count);
 return 0;
}