#include <stdio.h>
#include<dos.h>
int main()
{ char  c;
  _AH = 1;
  geninterrupt(0x21);
  c = _AL;          /*AL中存储的是字符的ASCII码*/
  printf("%c\n", c);
  return 0;
}
