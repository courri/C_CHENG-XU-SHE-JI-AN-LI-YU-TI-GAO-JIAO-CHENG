#include <stdio.h>
#include<dos.h>
int main()
{_CX = 2012;
 _DH = 12;
 _DL = 26;
 _AH = 0x2b;
 geninterrupt(0x21);
 if(_AL == 0)
   printf("设置成功!\n");
 else
   printf("设置失败!\n");
 return 0;
}
