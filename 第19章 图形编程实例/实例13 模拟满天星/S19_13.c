#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void putstar(void);
main()
{
   int driver=DETECT;
   int mode,color;
   initgraph(&driver,&mode,"");
   putstar();
   getch();
   closegraph();
   return;
}
void putstar(void)
{
 int seed=1858;
 int i,dotx,doty,h,w,color,maxcolor;
  maxcolor=getmaxcolor();
 w=getmaxx();
 h=getmaxy();
 srand(seed);
 for(i=0;i<250;++i)
 {
  dotx=i+random(w-1);
  doty=1+random(h-1);
  color=random(maxcolor);
  setcolor(color);
  putpixel(dotx,doty,color);
  circle(dotx+1,doty+1,1);
 }
 srand(seed);
}
