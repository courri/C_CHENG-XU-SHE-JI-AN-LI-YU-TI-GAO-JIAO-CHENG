#include <stdio.h>
int main()
{ union{
    long m;
    float x;
  }a;
  clrscr();
  a.x = 30;
  printf("%lx\n",a.m);
  return 0;
}
