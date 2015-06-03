#include <stdio.h>
#include<dos.h>
int main()
{ char  s[20];
  int i;
  clrscr();
  s[0] = 18;      /*最多能接受17个字符*/
  _DX = (unsigned)s;
  _AH = 10;
  geninterrupt(0x21);
  clrscr();
  for(i=0;i<=s[1]+2;i++)
    printf("%d\n",s[i]);
  return 0;
}