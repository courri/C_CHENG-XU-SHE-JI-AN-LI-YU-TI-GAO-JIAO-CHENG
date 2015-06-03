#include <dos.h>
int main(int argc, char **argv)
{union REGS inregs, outregs;
 struct SREGS segs;
 if(*argv[1])
   {
    inregs.h.ah=0x41;
    inregs.x.dx=(unsigned)argv[1];
    segread(&segs);
    intdosx(&inregs,&outregs, &segs);
    if(outregs.x.cflag)
      printf("Error:%d\n",outregs.x.ax);
    else
      printf("%s deleted\n", argv[1]);
   }
 else
   printf("Must specify filename to delete!\n");
 getch();
 return 0;
}
