#include <graphics.h>
void main()
{
	int i;
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"d:\\tc");
	cleardevice();
	printf("\noutput 'Hello world!' using 'outtext'.");
	for(i=80;i<=240;i+=40)
	{
	    moveto(30+i,i);
	    settextstyle((i-80)/40,i/40%2,(i-80)/40);
	    outtext("Hello World!");
	}
	getch();
	cleardevice();
	printf("\noutput 'Hello World!' using 'outtextxy'.");
	for(i=80;i<=160;i+=40)
	{
	    settextjustify(i/40%3,0);
	    outtextxy(200,i,"Hello World!");
	}
	getch();
	cleardevice();
	closegraph();
}