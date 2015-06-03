#include <dos.h>
#include <stdio.h>
int main()
{
  char far *str = "fpoff.c";
  printf("%04x\n" , FP_OFF(str));
  return 0;
}
