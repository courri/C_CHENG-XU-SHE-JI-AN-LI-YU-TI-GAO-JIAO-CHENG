#include <graphics.h>
main()
{
	int i,graphdriver,graphmode,size;
	void *buffer;
	graphdriver=DETECT;
	initgraph(&graphdriver,&graphmode,"");
	setbkcolor(BLUE);
	cleardevice();
	setcolor(YELLOW);
	setlinestyle(0,0,1);
	setfillstyle(1,5);
	circle(100,200,30); 
	floodfill(100,200,YELLOW);                /* 填充圆 */             
	size=imagesize(69,169,131,231);            /*指定图像占字节数    */ 
	buffer=malloc(size);			          /*分配缓冲区(按字节数)	*/ 
	getimage(69,169,131,231,buffer);	         /*存图像	*/ 
	putimage(500,169,buffer,COPY_PUT); 	/*重新复制	*/ 
        do{
		for(i=0;i<185;i++)
		{
			putimage(70+i,170,buffer,COPY_PUT);	/*左边球向右运动*/ 
			putimage(500-i,170,buffer,COPY_PUT);	/*右边球向左运动*/ 
		}/*两球相撞后循环停止*/ 
		for(i=0;i<185;i++)
		{
			putimage(255-i,170,buffer,COPY_PUT);	/*左边球向左运动*/ 
			putimage(315+i,170,buffer,COPY_PUT);	/*右边球向右运动*/ 
		}
	}while (!kbhit());/*当不按键时重复上述过程*/ 
	getch();
	closegraph();
}
