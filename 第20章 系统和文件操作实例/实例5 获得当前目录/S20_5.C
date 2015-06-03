#include <dos.h>
int main()
{union REGS inregs, outregs;
 struct SREGS segs;
 char buffer[64];
 inregs.h.ah=0x47;
 inregs.x.si=(unsigned)buffer;
 inregs.h.dl=0;
 segread(&segs);
 intdosx(&inregs,&outregs, &segs);
 if(outregs.x.cflag)
   printf("Error:%d\n",outregs.x.ax);
 else
  printf("Current directory \\%s\n", buffer);
 getch();
 return 0;
}
