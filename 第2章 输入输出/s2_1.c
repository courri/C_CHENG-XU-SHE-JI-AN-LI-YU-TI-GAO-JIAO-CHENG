#include <stdio.h>
int main()
{ char c1,c2;
  printf(“本软件带有x插件，安装否(y/n)？”);
  c1 = getchar();           /*应换成getch()*/
  if(c1==‘Y’||c1==‘y’)   
      /*安装x插件的代码*/
  printf(“\n本软件带有y插件，安装否(y/n)？”);
  c2 = getchar();
  if(c2==‘Y’||c2==‘y’)   
      /*安装y插件的代码*/
  return 0;
}