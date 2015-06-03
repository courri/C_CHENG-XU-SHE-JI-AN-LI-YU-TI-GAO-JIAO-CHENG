#include <dos.h>
int main()
{char  c;
 struct  REGPACK  p;
 clrscr();
 p.r_ds = _DS;
 p.r_es = _ES;
 p.r_ax = 0x0000;
 intr(0x16, &p);
 c = p.r_ax;
 printf("%c\n", c);
 return 0;
}
