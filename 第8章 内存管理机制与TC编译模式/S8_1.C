#include <dos.h>
#include <stdio.h>
int main()
{
  char far *filename = "fpseg.c";
  printf("%04x\n", FP_SEG(filename));     /*本行中的0表示用0补足4位*/
  return(0);
}
