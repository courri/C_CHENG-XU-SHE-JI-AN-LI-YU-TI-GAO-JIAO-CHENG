#include<string.h>
#include<bios.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

#define  MAX  2   /*游戏中总关数*/
#define  STARTX   180
#define  STARTY    80
#define  BKCOLOR  BLACK
#define  MANCOLOR RED
#define  OBJECTCOLOR  YELLOW

#define STEPMAX  5
#define Key_R 0x1372
#define Key_Up  0x4800
#define Key_Enter 0x1c0d
#define Key_Down  0x5000
#define Key_P     0x1970
#define Key_Esc   0x11b
#define Key_Right  0x4d00
#define Key_Left  0x4b00

typedef struct c
{
	int x;
	int y;
}Add;

typedef struct a
{
	int x;
	int y;
}Player;
Player p;

/*一些全局变量定义*/
int MissionNum;   /*玩家正在玩的关数*/
int BoxNum;    	  /*目的地的个数*/
int Key;          /*玩家按键*/
int map[10][10];  /*地图.(空=0),(人=1),(箱子=2),(墙=3),(目的地=4),(人+目的地=5),(箱子+目的地=6)*/
int StepNum;
int BoxMove[STEPMAX];
int Step[STEPMAX];

/*一些函数定义*/
void Init();
void Game();
void InitMission(int );
void NextMission();
void InitPic(int ,int ,int );
int  Move(Add );
void DrawWall(int ,int );
void DrawBack(int ,int );
void DrawBox(int ,int );
void DrawObject(int ,int );
void DrawMan(int ,int );
int JudgeWin();
void game1();
void game2();

int main()
{
	Init();/*初始化图形模式*/
	Game();
	return 0;
}

void Init()
{  	/*设置图形驱动和模式*/
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
}

void Game()/*游戏开始*/
{
	int i,j,flag;
	Add ad;
	MissionNum=0;
	NextMission();
	do
   	{
   		flag=0;
   		Key=bioskey(0);/*获取一个键盘输入*/
   		switch(Key)
  		{
   			case Key_Enter:{NextMission();break;}/*键入ENTER键进入下一关*/
   			case Key_Up:{ad.x=-1;ad.y=0;flag=1;break;}/*键入四个方向建移动*/
   			case Key_Down:{ad.x=1;ad.y=0;flag=1;break;}
   			case Key_Left:{ad.x=0;ad.y=-1;flag=1;break;}
   			case Key_Right:{ad.x=0;ad.y=1;flag=1;break;}
   			case Key_R:{MissionNum--;NextMission();break;}/*键入R重新开始这一关*/
   			case Key_Esc:{exit(1);}/*键入ESC键退出*/
  		}
   		if(flag==1)
        	{
        		if(Move(ad))/*移动后改变二维数组值*/ 
        		{
        			if(JudgeWin()) 
        			{ 
        				/*游戏结束给出提示*/
        				gotoxy(10,3);
  					printf("\t\tWell done!!");
  					gotoxy(10,4);
					printf("\t\tpress any key continue...");
					getch();
					getch();
        				NextMission();
        			}
        		}
        	}
   	}while(1);
}
/*初始化关卡*/
void InitMission(int n)
{
	int i,j;
	for(i=0;i<10;i++)
  		for(j=0;j<10;j++)
    			map[i][j]=0;
	switch(n)
   	{
    		case 1:game1();break;  /*第一关*/
    		case 2:game2();break;  /*第二关*/
   	}
}
/*初始化整个游戏图像和重绘整个游戏图像*/
void InitPic(int n,int i,int j)
{
	switch(n)
   	{
   		case 0:DrawBack(i,j);break;
   		case 1:DrawMan(i,j);break;
   		case 2:DrawBox(i,j);break;
   		case 3:DrawWall(i,j);break;
   		case 4:DrawObject(i,j);break;
   		case 5:DrawMan(i,j);break;
   		case 6:DrawBox(i,j);break;
   	}
}
/*选择下一关*/
void NextMission()
{
	int i,j;
	if(MissionNum+1>MAX)  
		MissionNum=1;
	else 
		MissionNum++;
	InitMission(MissionNum);
	setbkcolor(BKCOLOR);
	cleardevice();
	for(i=0;i<10;i++)
  		for(j=0;j<10;j++)
    			InitPic(map[i][j],i,j);
	switch(MissionNum)
  	{
  		case 1:outtextxy(300,330,"game 1");break;
  		case 2:outtextxy(300,330,"game 2");break;
  	}
	for(i=0;i<STEPMAX;i++)
  	{
  		Step[i]=BoxMove[i]=0;
  	}
	StepNum=0;
}
/*移动后改变整个二维数组的值*/
int Move(Add a)
{
	int flag;
	int i=StepNum%STEPMAX;
	switch(map[p.x+a.x][p.y+a.y])  /*看下一位置为什么，改变二维数组的值，重绘整个游戏画面*/
    	{
    	case 0:{map[p.x][p.y]-=1;InitPic(map[p.x][p.y],p.x,p.y);
    		p.x=p.x+a.x;p.y=p.y+a.y;
    		map[p.x][p.y]+=1;InitPic(map[p.x][p.y],p.x,p.y);flag=1;break;}
    	case 2:{if(map[p.x+2*a.x][p.y+2*a.y]==0||map[p.x+2*a.x][p.y+2*a.y]==4)
       		{
       			map[p.x][p.y]-=1;map[p.x+a.x][p.y+a.y]=1;map[p.x+2*a.x][p.y+2*a.y]+=2;
       			InitPic(map[p.x][p.y],p.x,p.y);
       			InitPic(map[p.x+a.x][p.y+a.y],p.x+a.x,p.y+a.y);
       			InitPic(map[p.x+2*a.x][p.y+2*a.y],p.x+2*a.x,p.y+2*a.y);
       			p.x=p.x+a.x;p.y=p.y+a.y;flag=1;BoxMove[i]=1;
       		}
     		else flag=0;
     		break;}
    	case 3:flag=0;break;
    	case 4:{map[p.x][p.y]-=1;InitPic(map[p.x][p.y],p.x,p.y);
    		p.x=p.x+a.x;p.y=p.y+a.y;
    		map[p.x][p.y]+=1;InitPic(map[p.x][p.y],p.x,p.y);flag=1;break;}
    	case 6:{if(map[p.x+2*a.x][p.y+2*a.y]==0||map[p.x+2*a.x][p.y+2*a.y]==4)
       		{
       			map[p.x][p.y]-=1;map[p.x+a.x][p.y+a.y]=5;map[p.x+2*a.x][p.y+2*a.y]+=2;
       			InitPic(map[p.x][p.y],p.x,p.y);
       			InitPic(map[p.x+a.x][p.y+a.y],p.x+a.x,p.y+a.y);
       			InitPic(map[p.x+2*a.x][p.y+2*a.y],p.x+2*a.x,p.y+2*a.y);
       			p.x=p.x+a.x;p.y=p.y+a.y;flag=1;BoxMove[i]=1;
       		}
     		else flag=0;
     		break;}
    	}
	return flag;
}
/*画出墙壁*/
void DrawWall(int i,int j)
{
	DrawBack(i,j);
	setfillstyle(9,2);
	bar(STARTX+20*j-9,STARTY+20*i-9,STARTX+20*j+9,STARTY+20*i+9);
}
/*画出搬运工*/
void DrawMan(int i,int j)
{
	DrawBack(i,j);
	setcolor(MANCOLOR);
	circle(STARTX+20*j,STARTY+20*i,9);
	arc(STARTX+20*j-3,STARTY+20*i-2,20,160,3);
	arc(STARTX+20*j+4,STARTY+20*i-2,20,160,3);
	arc(STARTX+20*j,STARTY+20*i-2,220,320,7);
}
/*背景设置*/
void DrawBack(int i,int j)
{
	setfillstyle(1,BKCOLOR);
	bar(STARTX+20*j-9,STARTY+20*i-9,STARTX+20*j+9,STARTY+20*i+9);
}
/*画出目的地*/
void DrawObject(int i,int j)
{
	DrawBack(i,j);
	setcolor(OBJECTCOLOR);
	line(STARTX+20*j-9,STARTY+20*i,STARTX+20*j+9,STARTY+20*i);
	line(STARTX+20*j-9,STARTY+20*i-9,STARTX+20*j+9,STARTY+20*i+9);
	line(STARTX+20*j-9,STARTY+20*i+9,STARTX+20*j+9,STARTY+20*i-9);
}
/*画出箱子*/
void DrawBox(int i,int j)
{
	DrawBack(i,j);
	setfillstyle(9,3);
	bar(STARTX+20*j-9,STARTY+20*i-9,STARTX+20*j+9,STARTY+20*i+9);
}
/*判断游戏是否结束*/
int JudgeWin()
{
	int n=0,i,j;
	for(i=0;i<10;i++)
  		for(j=0;j<10;j++)
    			if(map[i][j]==6) n++;
	if(n==BoxNum)  
		return 1;
	else 
		return 0;
}
void game1()  /*第一关*/
{
	int i,j;
	for(i=0;i<10;i++)
  		for(j=0;j<10;j++)
     			map[i][j]=0;
	for(i=5;i<=9;i++)
  		map[0][i]=3;
	for(i=0;i<=4;i++)
  	{
  		map[i][5]=map[i][9]=3;
  	}
	for(i=2;i<=7;i++)
  		map[i][1]=3;
  	for(i=4;i<=8;i++)
  		map[i][8]=3;
  	for(i=4;i<=7;i++)
  		map[8][i]=3;
	map[2][2]=map[2][3]=map[3][3]=map[4][3]=map[4][4]=map[4][5]=map[6][4]=map[7][2]=map[7][3]
	=map[7][4]=map[4][7]=map[4][9]=3;
	map[2][6]=map[2][7]=map[3][7]=2;
	map[3][2]=map[4][2]=map[5][2]=4;
	p.x=1;p.y=8;
	map[1][8]=1;
	BoxNum=3;
}

void game2()     /*第二关*/
{
	int i,j;
	for(i=0;i<10;i++)
  		for(j=0;j<10;j++)
     			map[i][j]=0;
	for(i=1;i<=5;i++)
   	{
   		map[0][i]=map[6][i]=3;
   	}
	for(i=2;i<=4;i++)
   	{
   		map[1][i+3]=map[i][7]=map[i+2][5]=map[i][0]=3;
   	}
	map[1][1]=map[2][1]=map[5][0]=map[5][5]=map[4][6]=map[6][0]=3;
	map[2][4]=map[3][3]=map[4][2]=map[4][3]=2;
	map[2][3]=map[3][2]=map[3][4]=map[4][4]=4;
	p.x=1;p.y=3;
	map[1][3]=1;
	BoxNum=4;
}
