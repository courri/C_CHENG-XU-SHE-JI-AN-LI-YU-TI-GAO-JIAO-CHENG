#include <stdio.h>
#include<dos.h>
int main()
{
 char  c;
 _AH = 0;
 geninterrupt(0x16);
 c = _AL;
 printf("%c\n", c);
 return 0;
}
