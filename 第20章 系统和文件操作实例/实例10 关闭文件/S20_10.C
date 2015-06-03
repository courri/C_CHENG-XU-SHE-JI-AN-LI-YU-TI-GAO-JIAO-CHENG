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
   {printf("Open file error:%d\n",outregs.x.ax);
    exit(1);
   }
 else
   handle=outregs.x.ax;
 /*以下代码关闭文件*/
 inregs.h.ah=0x3e;
 inregs.x.bx=handle;
 intdosx(&inregs,&outregs, &segs);
 if(outregs.x.cflag)
   printf("Close file Error:%d\n",outregs.x.ax);
 else
  printf("Close Success!");
 getch();
 return 0;
}
