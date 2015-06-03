#include <dos.h>
int main()
{union REGS inregs, outregs;
 inregs.h.ah=0x19;
 intdos(&inregs,&outregs);
 printf("The current drive is %c\n", outregs.h.al+'A');
 inregs.h.ah=0x0e;
 inregs.h.dl=2;
 intdos(&inregs,&outregs);
 inregs.h.ah=0x19;
 intdos(&inregs,&outregs);
 printf("Now the current drive is %c\n", outregs.h.al+'A');
 getch();
 return 0;
}
