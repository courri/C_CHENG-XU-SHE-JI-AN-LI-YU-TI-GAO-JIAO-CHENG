#include <stdio.h>
float  myatof(char *p)
{float x = 0;
 while(*p != '\0'&&*p != '.')
   {
    x = x*10+*p-48;
    p++;
   }
 if(*p == '.')
   {
    int k=10;
    p++;
    while(*p != '\0')
      {x += (float) (*p-48)/k;
       k *= 10;
       p++;
      }
   }
 return x;
}

int main()
{char s[20];
 float x;
 gets(s);
 x=myatof(s);
 printf("%f\n",x);
 getch();
 return 0;
}