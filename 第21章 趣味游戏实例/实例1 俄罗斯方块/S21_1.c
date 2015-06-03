#include<stdio.h>
#include<stdlib.h> 
#include<graphics.h> 
#include<bios.h>
/*下面定义了一些控制命令*/
/*重画界面命令*/
#define CMDDRAW       5 
/*消去一个满行的命令*/
#define CMDDELLINE    6 
/*自动下移一行的命令*/
#define CMDAOTODOWN   7 
/*生产新的方块*/
#define CMDGEN        8 
/*向左移动的命令，以左箭头<-控制，它的ASCII码值是75*/
#define CMDLEFTMOVE   75 
/*向右移动的命令，以右箭头->控制，它的ASCII码值是77*/
#define CMDRINGHTMOVE 77 
/*旋转方块的命令，以空格来控制*/
#define CMDROTATE     57 
/*向下移动的命令，以向下的箭头控制，它的ASCII码值是80*/
#define CMDDOWNMOVE   80 
/*退出游戏的控制命令，以esc键控制，它的ASCII码值是1*/
#define CMDESC        1 

/*定义了方块下降的时间间隔*/
#define TIMEINTERVAL  4 

/*下面定义了游戏区的大小*/
#define MAXWIDTH      15 
#define MAXHEIGHT  		30 
/*组成方块的小格子的宽度*/
#define BOXWIDTH      15 

/*用两个数组来表示新旧两个矩形游戏区*/
int oldarea[MAXHEIGHT+1][MAXWIDTH]; 
int area[MAXHEIGHT+1][MAXWIDTH]; 
/*定义一个需要改变的屏幕区域，初次之外的区域不用进行重绘*/
int actW,actH,actX,actY; 
/*当前方块的一些属性（坐标，颜色，高，宽）*/
int curX,curY,curColor,curW,curH; 
/*新的方块的一些属性（坐标，颜色，高，宽）*/
int newX,newY,newColor,newW,newH; 
/*制定方块的状态*/
int active; 
/*存储当前方块的数组*/
int box[4][4]; 
/*当前方块的颜色*/
int BOXCOLOR; 
/*控制命令*/
int CMD; 
/*定义七种基本的方块形状*/
int BOX[7][4][4]={ 
 {{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
 {{1,1,1,0},{1,0,0,0},{0,0,0,0},{0,0,0,0}},
 {{1,1,1,0},{0,0,1,0},{0,0,0,0},{0,0,0,0}},
 {{1,1,1,0},{0,1,0,0},{0,0,0,0},{0,0,0,0}},
 {{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
 {{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
 {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}} 
}; 
/*得到方块的宽度，即从右向左第一个不空的列*/
int GetWidth() 
{ 
	int i,j; 
	for(i=3;i>0;i--) 
	for(j=0;j<4;j++) 
		if(box[j][i]) return i; 
	return 0; 
} 
/*得到方块的高度，从上往下第一个不空的行*/
int GetHeight() 
{ 
	int i,j; 
 	for(j=3;j>0;j--) 
  for(i=0;i<4;i++) 
   	if(box[j][i]) return j; 
 	return 0; 
} 
/*清除原有的方块占有的空间*/
void ClearOldspace() 
{ 
 	int i,j; 
 	for(j=0;j<=curH; j++) 
  for(i=0;i<=curW; i++) 
   	if(box[j][i]) 
    	area[curY+j][curX+i]=0; 
} 
/*置位新方块的位置*/
void PutNewspace() 
{ 
 	int i,j; 
 	for(j=0;j<=newH;j++) 
  for(i=0;i<=newW;i++) 
   	if(box[j][i]) 
    	area[newY+j][newX+i]=BOXCOLOR; 
} 
/*判断方块的移动是否造成区域冲突*/
int MoveCollision(int box[][4]) 
{ 
 	int i,j; 
 	if(newX<0) return 1; 
 	if(newX+newW>=MAXWIDTH) return 1; 
 	if(newY<0) return 1; 
 	for(j=0;j<=newH;j++) 
  	for(i=0;i<=newW;i++) 
   		if(area[newY+j][newX+i]&&box[j][i]) return 1; 
 	return 0; 
} 
/*判断翻转方块是否造成区域的冲突*/
int RotateBoxCollision(int box[][4]) 
{ 
 	int i,j; 
 	if(newX+newW>=MAXWIDTH) newX=MAXWIDTH-1-newW; 
 	if(newY+newH>=MAXHEIGHT) newY=MAXHEIGHT-1-newH; 
 	if(MoveCollision(box)) return 1; 
 	for(i=0;i<=newW;i++) 
  	for(j=0;j<=newH;j++) 
   	if(area[newY+j][newX+i]) 
   	{ 
    	newX-=newW-i+1; goto L; 
   	} 
 	L: return MoveCollision(box); 
} 
/*游戏结束*/
int GameOver() 
{ 
 	if(!active &&(curY+curH>MAXHEIGHT-3)) 
 		return 1; 
 	else 
 		return 0; 
} 
/*判断是否超时，即是否超过允许的时间间隔*/
int TimeOut() 
{ 
 	static long tm,old; 
 	tm=biostime(0,tm); 
 	if(tm-old<TIMEINTERVAL) 
 		return 0; 
 	else 
 	{ 
 		old=tm; 
 		return 1; 
 	} 
} 
/*重绘游戏区*/
void DrawSpace() 
{ 
 	int row,col,x1,y1,x2,y2; 
 	for(row=actY;row<=actY+actH;row++) 
  for(col=actX;col<=actX+actW;col++) 
   	if(area[row][col]!=oldarea[row][col]) 
   	{ 
    	if(area[row][col]==0) 
     		setfillstyle(SOLID_FILL,BLACK); 
    	else 
     		setfillstyle(SOLID_FILL,BOXCOLOR); 
			x1=56+col*BOXWIDTH;
			x2=x1+BOXWIDTH; 
    	y1=464-(row+1)*BOXWIDTH; 
    	y2=y1+BOXWIDTH; 
    	bar(++x1,++y1,--x2,--y2); 
    	oldarea[row][col]=area[row][col]; 
  	} 
	CMD=0; 
} 
/*消去满行*/
void ClearFullline() 
{ 
 	int row,col, rowEnd,full,i,j; 
 	rowEnd=newY+newH; 
 	if(rowEnd>=MAXHEIGHT-1) 
 		rowEnd=MAXHEIGHT-2; 
 	for(row=newY; row<=rowEnd;) 
 	{ 
  	full=1; 
  	for(col=0;col<MAXWIDTH;col++) 
   		if(!area[row][col])
   			{full=0; break;} 
  	if(!full)
  	{
  		++row;
  		continue;
  	} 
  	for(j=row; j<MAXHEIGHT-1;j++) 
   	for(i=0;i<MAXWIDTH;i++) 
    	area[j][i]=area[j+1][i]; 
  	actX=0;
  	actY=row; 
  	actW=MAXWIDTH-1;
  	actH=MAXHEIGHT-1-row; 
  	DrawSpace(); 
  	rowEnd--; 
 	} 
 	CMD=CMDGEN; 
} 
/*向左移动方块*/
int MoveLeft() 
{ 
 	newX=curX-1; 
 	ClearOldspace(); 
 	if(MoveCollision(box)) 
 	{ 
  	newX=curX; 
  	PutNewspace(); 
  	CMD=0; 
  	return 0; 
 	} 
 	PutNewspace(); 
 	actW=curW+1; 
 	actX=curX=newX; 
 	CMD=CMDDRAW; 
 	return 1; 
} 
/*向右移动方块*/
int MoveRight() 
{ 
 	newX=curX+1; ClearOldspace(); 
 	if(MoveCollision(box)) 
 	{ 
 	 	newX=curX; 
 	 	PutNewspace(); 
  	CMD=0; 
  	return 0; 
 	} 
 	PutNewspace(); 
 	actW=curW+1; 
 	actX=curX;
 	curX=newX; 
 	CMD=CMDDRAW; 
 	return 1; 
} 
/*向下移动方块*/
int MoveDown() 
{ 
 	int i,j; 
 	newY=curY-1; 
 	ClearOldspace(); 
 	if(MoveCollision(box)) 
 	{ 
 	 	newY=curY; 
  	PutNewspace(); 
  	active=0; 
  	CMD=CMDDELLINE; 
  	return 0; 
 	} 
 	PutNewspace(); 
 	actH=curH+1; 
 	actY=newY; 
 	curY=newY; 
 	CMD=CMDDRAW; 
 	return 1; 
} 
/*按加速键后方块迅速下落到底*/
void MoveBottom() 
{ 
 	while(active) 
 	{ 
 	 	MoveDown(); 
 	 	DrawSpace(); 
 	} 
 	CMD=CMDDELLINE; 
} 
/*初始化*/
void InitialGame() 
{ 
 	int i,j,x1,y1,x2,y2; 
 	int driver=DETECT, mode=0; 
 	initgraph(&driver,&mode,""); 
 	cleardevice(); 
 	randomize(); 
 	setfillstyle(SOLID_FILL,BLUE); 
 	bar(0,0,639,479); 
 	x1=56; 
 	y1=464-BOXWIDTH*MAXHEIGHT; 
 	x2=56+MAXWIDTH*BOXWIDTH; 
 	y2=464; 
 	rectangle(--x1,--y1,++x2,++y2); 
 	setfillstyle(SOLID_FILL,BLACK); 
 	bar(++x1,++y1,--x2,--y2); 
 	y1=464-MAXHEIGHT*BOXWIDTH; y2=464; 
 	setcolor(DARKGRAY); 
 	for(i=0;i<MAXWIDTH;i++) 
 	{ 
  	x1=56+i*BOXWIDTH; 
  	line(x1,y1,x1,y2); 
 	} 
	x1=56; x2=x1+MAXWIDTH*BOXWIDTH; 
 	for(j=0;j<MAXHEIGHT;j++) 
 	{ 
  	y1=464-j*BOXWIDTH; 
 	 	line(x1,y1,x2,y1); 
 	} 
 	for(j=0;j<MAXHEIGHT;j++) 
  for(i=0;i<MAXWIDTH;i++) 
   	area[j][i]=oldarea[j][i]=0; 
 	actX=0; actY=0; actW=MAXWIDTH-1; actH=MAXHEIGHT-1; 
 	DrawSpace(); 
 	CMD=CMDGEN; 
}
/*得到控制命令*/ 
void GetCMD() 
{ 
 	if(CMD) return; 
 	if(TimeOut()) 
 	{ 
  	CMD=CMDAOTODOWN; 
  	return; 
 	} 
 	if(bioskey(1)) 
 	{ 
  	CMD=bioskey(0)>>8; 
  	return; 
 	} 
} 
/*生成一个新的方块*/
int GenerateNewbox() 
{ 
 int i,j,boxidx; 
 boxidx=random(7); BOXCOLOR=random(7)+1; 
 for(j=0;j<4;j++) 
  for(i=0;i<4;i++) 
   box[j][i]=BOX[boxidx][j][i]; 
 curW=GetWidth(); curH=GetHeight(); 
 curX=(MAXWIDTH+curW)/2; 
 if(curX+curW>=MAXWIDTH)curX=MAXWIDTH-1-curW; 
 curY=MAXHEIGHT-1-curH; 
 newX=curX; newY=curY; actX=curX;actY=curY; 
 actW=newW=curW; actH=newH=curH; 
 active=1; 
 if(MoveCollision(box)) return 0; 
 PutNewspace(); 
 DrawSpace(); CMD=0; 
 return 1; 
} 
/*翻转方块*/
int RotateBox() 
{ 
 	int newBox[4][4]; 
 	int i,j; 
 	ClearOldspace(); 
 	for(j=0;j<4;j++) 
  for(i=0;i<4;i++) 
   	newBox[j][i]=0; 
 	for(j=0;j<4;j++) 
  for(i=0;i<4;i++) 
   	newBox[curW-i][j]=box[j][i]; 
 	newW=curH; 
 	newH=curW; 
 	if(RotateBoxCollision(newBox)) 
 	{ 
  	newW=curW; 
  	newH=curH; 
  	newX=curX; 
  	newY=curY; 
  	PutNewspace(); 
  	CMD=0; 
  	return 0; 
 	} 
 	for(j=0;j<4;j++) 
  for(i=0;i<4;i++) 
   	box[j][i]=newBox[j][i]; 
 	PutNewspace(); 
 	actH=newH>curH? newH:curH; 
 	actW=curX+actH-newX; 
 	actX=newX; 
 	actY=newY; 
 	curX=newX; 
 	curY=newY; 
 	curW=newW;
 	curH=newH; 
 	CMD=CMDDRAW; 
 	return 1; 
} 
/*根据获得的命令来执行不同的操作*/
void ExecuteCMD() 
{ 
 	switch(CMD) 
 	{ 
  	case CMDLEFTMOVE:  
  		MoveLeft();
  		break; 
  	case CMDRINGHTMOVE: 
  		MoveRight();
  		break; 
  	case CMDAOTODOWN: 
  		MoveDown();
  		break; 
  	case CMDROTATE: 
  		RotateBox();
  		break; 
  	case CMDDOWNMOVE:  
  		MoveBottom(); 
  		break; 
  	case CMDDRAW:  
  		DrawSpace();
  		break; 
  	case CMDDELLINE:  
  		ClearFullline();
  		break; 
  	case CMDGEN:   
  		GenerateNewbox();
  		break; 
  	case CMDESC:   
  		closegraph();
  		return 0; 
  	default:     
  		CMD=0; 
 } 
}
/*主函数*/ 
int main() 
{ 
 	int i; 
 	InitialGame(); 
 	do 
 	{ 
  	GetCMD(); 
  	ExecuteCMD(); 
 	} 
 	while(!GameOver()); 
 	getch(); 
 	closegraph(); 
 	return 0;
} 