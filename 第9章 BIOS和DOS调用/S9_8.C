#include <stdio.h>
#include<dos.h>
int main()
{
 char  c;
 union REGS  inregs, outregs;
 inregs.h.ah = 0 ;      /*使用0号功能*/
 c = int86(0x16, &inregs, &outregs);
 printf("%c\n", c);
 return 0;
}