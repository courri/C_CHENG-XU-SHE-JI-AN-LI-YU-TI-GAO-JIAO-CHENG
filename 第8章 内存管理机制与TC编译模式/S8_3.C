#include <dos.h>
#include <stdio.h>
int main()
{
  char far *p;
  unsigned seg, off;
  p = MK_FP(0xb000, 0x20);
  seg = FP_SEG(p);
  off = FP_OFF(p);
  printf("far p:%Fp,  seg:%04X, off:%04X\n",  p, seg, off);
  return 0;
}

