#include <stdio.h>
#include<dos.h>
int main()
{ 
  printf("Press anykey to exit");
  _AL=0;
  while(!_AL) {
    _AH=0xB;
    geninterrupt(0x21);
  } 
  return 0;
}