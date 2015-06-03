#include <dos.h>
int main()
{union REGS inregs, outregs;
 struct SREGS segs;
 char *buffer="\\newdir";
 inregs.h.ah=0x3b;
 inregs.x.dx=(unsigned)buffer;
 segread(&segs);
 intdosx(&inregs,&outregs, &segs);
 if(outregs.x.cflag)
   printf("Error:%d\n",outregs.x.ax);
 else
  printf("Success!\n");
 getch();
 return 0;
}
