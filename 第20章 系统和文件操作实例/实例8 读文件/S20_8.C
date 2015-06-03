#include <dos.h>
int main()
{union REGS inregs, outregs;
 struct SREGS segs;
 char *filename="d:\\abc\\a.txt";
 int handle;
 inregs.h.ah=0x3d;
 inregs.h.al=0;
 inregs.x.dx=(unsigned)filename;
 segread(&segs);
 intdosx(&inregs,&outregs, &segs);
 if(outregs.x.cflag)
   printf("Error:%d\n",outregs.x.ax);
 else
   {char buffer[100]={'\0'};
    handle=outregs.x.ax;
    inregs.h.ah=0x3f;
    inregs.x.bx=handle;
    inregs.x.cx=10;
    segread(&segs);
    inregs.x.dx=(unsigned)buffer;
    intdosx(&inregs,&outregs, &segs);
    if(outregs.x.cflag)
        printf("Error:%d\n",outregs.x.ax);
    else
      printf("%s\n", buffer);
 }
 getch();
 return 0;
}

