#include <bios.h>
#include <stdio.h>
int main()
{int key;
 union{
   int key;
   char c[2];
 }u;
 char flag;
 u.key=bioskey(0);
 while(u.c[1]!=1)
   {
    printf("code:0x%x  ",u.c[1]);
    if(u.c[0]!=0)
      printf("ASCII:%d   char:%c", u.c[0], u.c[0]);
    printf("\n");
    key=bioskey(2);
    if(key&64)
      printf("Caps LOCK On\n");
    else
      printf("Caps LOCK Off\n");
    if(key&1||key&2)
      printf("Use Shift\n");
    else
      printf("Not use Shift\n");
    if(key&8)
      printf("Use Alt\n");
    else
      printf("Not use Alt\n");

    u.key=bioskey(0);
   }
 return 0;
}
