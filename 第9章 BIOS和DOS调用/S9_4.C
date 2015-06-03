#include <stdio.h>
#include<dos.h>
int main()
{ char *p = "hello$";
  _DX = (unsigned)p;
  _AH = 9;
  geninterrupt(0x21);
  return 0;
}
