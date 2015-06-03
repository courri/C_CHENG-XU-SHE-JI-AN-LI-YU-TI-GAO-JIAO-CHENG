#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<alloc.h>　

#define WIDTH_R  20 /*定义火箭柱体宽度*/
#define HEIGHT_R 80 /*定义火箭柱体高度*/

#define WIDTH_H  10 /*定义头部的半宽 = WIDTH_R/2*/
#define HEIGHT_H 20 /*定义头部高度*/

#define WIDTH_B  10 /*定义尾部延伸的宽度*/
#define HEIGHT_B 10 /*定义尾部高度*/

#define START_X  200
#define START_Y  400


void DrawRocket(int x,int y)
{
	int x1,y1,x2,y2;
	x1 = x;y1 = y;
	x2 = x;y2 = y - HEIGHT_R;
	line(x1,y1,x2,y2);
	x1 = x;y1 = y;
	x2 = x + WIDTH_R;y2 = y;
	line(x1,y1,x2,y2);
	x1 = x + WIDTH_R;y1 = y;
	x2 = x + WIDTH_R;y2 = y - HEIGHT_R;
	line(x1,y1,x2,y2);
	x1 = x;y1 = y - HEIGHT_R;
	x2 = x + WIDTH_H;y2 = y - HEIGHT_R - HEIGHT_H;
	line(x1,y1,x2,y2);
	x1 = x + WIDTH_R;y1 = y - HEIGHT_R;
	x2 = x + WIDTH_H;y2 = y - HEIGHT_R - HEIGHT_H;
	line(x1,y1,x2,y2);
	x1 = x;y1 = y;
	x2 = x - WIDTH_B;y2 = y + HEIGHT_B;
	line(x1,y1,x2,y2);
	x1 = x + WIDTH_R +WIDTH_B;y1 = y +HEIGHT_B;
	x2 = x + WIDTH_R;y2 = y;
	line(x1,y1,x2,y2);
	x1 = x + WIDTH_R +WIDTH_B;y1 = y +HEIGHT_B;
	x2 = x - WIDTH_B;y2 = y + HEIGHT_B;
	line(x1,y1,x2,y2);
	x1 = x;y1 = y - HEIGHT_R;
	x2 = x + WIDTH_R;y2 = y - HEIGHT_R;
	line(x1,y1,x2,y2);
	x1 = x;y1 = y + HEIGHT_B;
	x2 = x;y2 = y + HEIGHT_B +4;
	line(x1,y1,x2,y2);
	x1 = x +4 ;y1 = y + HEIGHT_B +4;
	x2 = x;y2 = y + HEIGHT_B +4;
	line(x1,y1,x2,y2);
	x1 = x + 4;y1 = y + HEIGHT_B +4;
	x2 = x + 4;y2 = y + HEIGHT_B;
	line(x1,y1,x2,y2);
	x1 = x + WIDTH_R;y1 = y + HEIGHT_B +4;
	x2 = x + WIDTH_R;y2 = y + HEIGHT_B;
	line(x1,y1,x2,y2);
	x1 = x + WIDTH_R;y1 = y + HEIGHT_B +4;
	x2 = x + WIDTH_R - 4;y2 = y + HEIGHT_B + 4;
	line(x1,y1,x2,y2);
	x1 = x + WIDTH_R - 4;y1 = y + HEIGHT_B;
	x2 = x + WIDTH_R - 4;y2 = y + HEIGHT_B + 4;
	line(x1,y1,x2,y2);
}
void Play()
{
	int x,y;
	int s = 4;
	int delaytime = START_Y/s;
	for(x = START_X,y = START_Y;y>=0;y -= s)
	{
		cleardevice();
		DrawRocket(x,y);
		delay(delaytime);
		delaytime --;
	}
}
int main()
{
    
    char ch;
    int x,y;
    int grdriver=DETECT;
    int grmode;
    initgraph(&grdriver,&grmode,"");
    setbkcolor(BLACK);
    cleardevice();
	setcolor(WHITE);
    settextstyle(TRIPLEX_FONT,0,2);
    outtextxy(200,100,"Press any key to begin!");
    DrawRocket(START_X,START_Y);
	getch();
    Play();
    getch();
    closegraph();
    return 0;

}

