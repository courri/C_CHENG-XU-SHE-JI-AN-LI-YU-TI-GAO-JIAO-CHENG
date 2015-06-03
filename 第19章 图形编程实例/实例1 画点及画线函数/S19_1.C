#include <graphics.h>
#include <stdio.h>
int main()
{
	  int gdriver = DETECT;
	  int gmode,i;
	  initgraph(&gdriver, &gmode,"D:\\tc");
	  cleardevice();
	  printf("\n draw lines with fuction 'putpixel'.");
	  for(i=160;i<=480;i=i+2)
	      putpixel(i,120,4);
	  for(i=120;i<=360;i=i+2)
	      putpixel(480,i,1);
	  for(i=160;i<=480;i=i+2)
	      putpixel(i,360,2);
	  for(i=120;i<=360;i=i+2)
	      putpixel(160,i,3);
	  getch();
	  cleardevice();
	  getch();
	  printf("\nDraw lines with fuction 'line'.");
	  line(160,120,480,120);
	  line(480,120,480,360);
	  line(480,360,160,360);
	  line(160,360,160,120);
	  getch();
	  cleardevice();
	  getch();
	  printf("\nDraw lines with fuction 'lineto'.");
	  moveto(160,120);
	  lineto(480,120);
	  lineto(480,360);
	  lineto(160,360);
	  lineto(160,120);
	  getch();
	  cleardevice();
	  getch();
	  printf("\nDraw lines with fuction 'linerel'.");
	  moveto(160,120);
	  linerel(320,0);
	  linerel(0,240);
	  linerel(-320,0);
	  linerel(0,-240);
	  getch();
	  cleardevice();
	  getch();


	  closegraph();
	  return 0;
}
