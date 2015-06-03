#include <dos.h>
#include <string.h>
int main()
{union REGS inregs, outregs;
 struct SREGS segs;
 char *filename="d:\\abc\\a.txt";
 int handle;
 inregs.h.ah=0x3d;
inregs.h.al=1;
inregs.x.dx=(unsigned)filename;
 segread(&segs);
 intdosx(&inregs,&outregs, &segs);
 if(outregs.x.cflag)
   printf("Error:%d\n",outregs.x.ax);
 else
   {char str[]="ABCD123";
    handle=outregs.x.ax;
    inregs.h.ah=0x40;
    inregs.x.bx=handle;
    inregs.x.cx=strlen(str);
    segread(&segs);
    inregs.x.dx=(unsigned)str;
    intdosx(&inregs,&outregs, &segs);
    if(outregs.x.cflag)
        printf("Error:%d\n",outregs.x.ax);
    else
      printf("bytes_written:%d\n", outregs.x.ax );
}
 getch();
 return 0;
}
