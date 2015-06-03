#include <dos.h>
int main()
{union REGS inregs, outregs;
 struct SREGS segs;
 char *filename="d:\\abc\\a.txt";
 int handle;
 inregs.h.ah=0x3c;
 inregs.x.cx=3;
 inregs.x.dx=(unsigned)filename;
 segread(&segs);
 intdosx(&inregs,&outregs, &segs);
 if(outregs.x.cflag)
   printf("Error:%d\n",outregs.x.ax);
 else
   {handle=outregs.x.ax;
    printf("Success! handle=%d\n",handle);
   }
 getch();
 return 0;
}

