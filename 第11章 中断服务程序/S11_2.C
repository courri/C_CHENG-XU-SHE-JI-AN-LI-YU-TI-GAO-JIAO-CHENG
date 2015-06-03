#include "stdio.h"
#include "conio.h"
#include "dos.h"

int main()
{
 void interrupt beep();
 void install();
 void testbeep();
 char ch;
 install(beep,0x0a);
 testbeep(0x0a);
 return 0;
}

void interrupt beep(unsigned bp, unsigned di, unsigned si, unsigned ds, unsigned es, unsigned dx, unsigned cx, unsigned bx, unsigned ax)
{
 int i,j;
 char bits;
 bits=inportb(0x61);
 outportb(0x43, 0xb6);
 outportb(0x61, bits|3);
 outportb(0x42, 132);
 outportb(0x42, 3);
 getch();
 outportb(0x61, bits&0xfc);
 outportb(0x61, bits);
}

void install(void interrupt(*faddr)(), int inum)
{disable();
 setvect(inum, faddr);
 enable();
}

void testbeep(int inum)
{
 clrscr();
 printf("Press any key to exit\n");
 geninterrupt(inum);
}
