#define M sizeof(unsigned int)*8
#include <stdio.h>

int trans(unsigned n, int d, char *s)
{char digits[] ="0123456789ABCDEF";
 char buf[M+1];
 int j, i = M;
 buf[i]='\0';
 do{
   buf[--i]=digits[n%d];
   n/=d;
 }while(n);
 for(j=0; buf[i]!='\0'; j++,i++)
   s[j]=buf[i];
 s[j]='\0';
 return j;
}

/*附：主函数，用于测试trans函数 */
int main()
{unsigned int num,d;
 char s[33];
 scanf("%d%d", &num, &d);
 trans(num, d, s);
 printf("%d=%s(%d)\n", num,s,d);
 getch();
 return 0;
}
