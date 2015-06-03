#include <dos.h>
int main(int argc, char far **argv)
{union REGS inregs, outregs;
 struct SREGS segs;
 if(*argv[1]&&*argv[2])
   {
    inregs.h.ah=0x56;
    inregs.x.dx=(unsigned)argv[1];
    inregs.x.di=(unsigned)argv[2];
    segs.ds=FP_SEG(argv[1]);
    segs.es=FP_SEG(argv[2]);
    intdosx(&inregs,&outregs, &segs);
    if(outregs.x.cflag)
      printf("Not rename %s, error code %d\n", argv[1],outregs.x.ax);
    else
     printf("OK\n");
   }
 else
   printf("Must specify source and target filename!\n");
 getch();
 return 0;
}
