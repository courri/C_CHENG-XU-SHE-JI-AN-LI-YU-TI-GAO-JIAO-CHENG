#include <stdio.h>
#include<dos.h>
int main()
{
 char  c;
 union REGS  inregs, outregs;
 inregs.h.ah = 0 ;      /*ʹ��0�Ź���*/
 c = int86(0x16, &inregs, &outregs);
 printf("%c\n", c);
 return 0;
}