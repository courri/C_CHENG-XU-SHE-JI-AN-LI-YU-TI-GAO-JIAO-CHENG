#include <stdio.h>
#include<dos.h>
int main()
{ _DL = 'A';
  _AH = 2;
  geninterrupt(0x21);
  return 0;
}
