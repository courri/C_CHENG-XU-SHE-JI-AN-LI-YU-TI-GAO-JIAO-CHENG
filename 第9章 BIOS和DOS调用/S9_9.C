#include <stdio.h>
#include<dos.h>
void  movetoxy(int x, int y)
{
 union REGS regs;
 regs.h.ah = 2;
 regs.h.dh = y;
 regs.h.dl = x;
 regs.h.bh = 0;
 int86(0x10, &regs, &regs);
}

int main()
{
 clrscr();
 putchar('A');
 movetoxy(10,10);
 putchar('B');
 movetoxy(5,5);
 putchar('C');
 return 0;
}
