#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
/*定义按钮边的宽度*/
#define WIDTH 2
/*定义结构体来表示按钮*/
typedef struct
{  
	int x1,y1,x2,y2;
}button;	
/*按钮的初始化*/
void ButtonIntial(button *bt)
{
	int i,j;
	/*绘制柱状图来表示按钮*/
	setfillstyle(1,LIGHTGRAY);
	bar(bt->x1,bt->y1,bt->x2,bt->y2);
	setfillstyle(1,LIGHTGRAY);
	bar(bt->x1+WIDTH,bt->y1+WIDTH,bt->x2-WIDTH,bt->y2-WIDTH);
	/*绘制按钮的边框*/
	setcolor(WHITE);
	for(j=0;j<=WIDTH;j++)
		line(bt->x1,j+bt->y1,bt->x2-j,j+bt->y1);
	for(i=0;i<=WIDTH;i++)
		line(bt->x1+i,bt->y1+WIDTH,bt->x1+i,bt->y2-i);
	setcolor(BLACK);
	for(j=0;j<WIDTH;j++)
		line(bt->x2,j+bt->y2-WIDTH,bt->x1+WIDTH-j,j+bt->y2-WIDTH);
	for(i=0;i<=WIDTH;i++)
		line(bt->x2-WIDTH+i,bt->y2-WIDTH,bt->x2-WIDTH+i,bt->y1+WIDTH-i);
}
/*创建一个按钮*/
void ButtonDefine(button *bt,int x1,int y1,int x2,int y2)
{
  bt->x1=x1;
  bt->y1=y1;
  bt->x2=x2;
  bt->y2=y2;
  /*初始化按钮*/
  ButtonIntial(bt);
}
/*按下按钮函数*/
void ButtonDown(button *bt)
{
	int i,j;
	setfillstyle(1,YELLOW);
	bar(bt->x1+WIDTH,bt->y1+WIDTH,bt->x2-WIDTH,bt->y2-WIDTH);
	setcolor(BLACK);
	for(j=0;j<=WIDTH;j++)
		line(bt->x1,j+bt->y1,bt->x2-j,j+bt->y1);
	for (i=0;i<=WIDTH;i++)
		line(bt->x1+i,bt->y1+WIDTH,bt->x1+i,bt->y2-i);
	setcolor(WHITE);
	for(j=0;j<=WIDTH;j++)
		line(bt->x2,j+bt->y2-WIDTH,bt->x1+WIDTH-j,j+bt->y2-WIDTH);
	for(i=0;i<=WIDTH;i++)
		line(i+bt->x2-WIDTH,bt->y2-WIDTH,i+bt->x2-WIDTH,bt->y1+WIDTH-i);
}
void main()
{
	button *but1,*but2,*but3;
 	int ch;
 	int gdriver=DETECT,gmode;
 	initgraph(&gdriver,&gmode,"e:\\tc");
 	setbkcolor(GREEN);
 	clrscr();
 	/*设置底纹*/
 	setfillstyle(1,YELLOW);
	bar(50,50,600,400);
 	ButtonDefine(but1,150,200,200,250);
 	ButtonDefine(but2,200+10,200,250+10,250);
	ButtonDefine(but3,250+2*10,200,300+2*10,250);
 	while(ch!='q')
 	{
 		switch(ch)     
 		{
 			case'1':ButtonIntial(but1);break;
 			case'2':ButtonIntial(but2);break;
 			case'3':ButtonIntial(but3);break;
 		}
 		ch=getch();
 		if(ch=='q')break;
 		switch(ch)
 		{
  		case'1':ButtonDown(but1);break;
  		case'2':ButtonDown(but2);break;
  		case'3':ButtonDown(but3);break;
  	}
  	delay(30000);
  }
  closegraph();
}
  

		