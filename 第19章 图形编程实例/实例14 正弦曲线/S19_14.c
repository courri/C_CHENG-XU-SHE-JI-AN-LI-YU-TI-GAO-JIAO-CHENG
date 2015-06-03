#include   <stdio.h>
#include   <graphics.h>
#include   <math.h>
#define   PI   3.14159
#define   SCALEX   30
#define   SCALEY   60
#define   OFFSETX   0
#define   OFFSETY   200
#define   INTEVAL   0.1
int   main()
{
double   x,y,originX,originY;
int   gdriver=DETECT,gmode;
/*   initialize   graphics   mode   */
initgraph(&gdriver,   &gmode,   " ");
for(x = 0;   x<8*PI;   x+=INTEVAL)
line(SCALEX*x+OFFSETX,   SCALEY*sin(x)+OFFSETY,
          SCALEX*(x+INTEVAL)+OFFSETX,   SCALEY*sin(x+INTEVAL)+OFFSETY);
getch();
closegraph();
return   0;
}
