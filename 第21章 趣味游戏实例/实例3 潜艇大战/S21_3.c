#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <graphics.h>
/*定义宏来指定控制键的ASCII码值*/
#define ESCGAME 	1
#define SHOOT 		57
#define MOVELEFT 	75
#define MOVERIGHT 77
/*定义潜艇的移动速度*/
int  speed=300;
/*键盘操作用的变量*/
char keyState[128],keyPressed[128];
int  score=0;/*得分*/
char scorestring[10];/*输出分数的变量*/
struct bullet/*鱼雷的结构体*/
{
	int x;
	int y;
	int shoot;/*是否发射鱼雷*/
}enemyBullet[6];/*屏幕上最多有5个敌人可以发鱼雷*/

/*玩家的结构体*/
struct Player
{
	int x;
	int y;
	struct bullet bullet[6];
	int life;
}Player;

/*敌人的结构体*/
struct Enemy
{
	int x;
	int y;
	int speed;
	int color;
	int direction;
	int life;
}Enemy[6];

/*具体玩游戏*/
void PlayGame(void);	
/*画玩家*/
void DrawPlayer(void);
/*画敌人*/
void DrawEnemy(int i);
/*画子弹,0去除,1显示*/
void DrawPlayerBullet(int x,int y,int n);
/*画子弹,0去除,1显示*/
void DrawEnemyBullet(int x,int y,int n);
/*去除原来地方的物体*/
void DrawBlack(int x,int y,int color);
/*输出得分*/
void PrintScore();

/*下面是按键函数*/
int  GetKey(int ScanCode);
void interrupt far (*OldInterupt9Handler)();
void far interrupt NewInterupt9();
/*加载键盘*/
void InstallKeyboard();
/*关闭键盘*/
void ShutDownKeyboard();

void main(void)
{
 	int gd=DETECT,gm;
 	initgraph(&gd,&gm,"e:\\tc");
 	cleardevice();
 	/*加载键盘*/
 	InstallKeyboard();
 	/*具体玩游戏*/
 	PlayGame();
  /*关闭键盘*/
 	ShutDownKeyboard();
 	closegraph();
}
/*画玩家*/
void DrawPlayer(void)
{
	setfillstyle(SOLID_FILL,RED);
		bar(Player.x-20,Player.y-10,Player.x+20,Player.y);
	setfillstyle(SOLID_FILL,RED);
		bar(Player.x-20,Player.y-10,Player.x-10,Player.y);
}
/*画敌人*/
void DrawEnemy(int i)
{
	setfillstyle(SOLID_FILL,Enemy[i].color);
	bar(Enemy[i].x-20,Enemy[i].y-10,Enemy[i].x+20,Enemy[i].y);
	setfillstyle(SOLID_FILL,GREEN);
	if(Enemy[i].direction==1)
		bar(Enemy[i].x-20,Enemy[i].y-10,Enemy[i].x-10,Enemy[i].y);
	else
		bar(Enemy[i].x+10,Enemy[i].y-10,Enemy[i].x+20,Enemy[i].y);
}
/*去除原来地方的物体*/
void DrawBlack(int x,int y,int color)
{
	setfillstyle(SOLID_FILL,color);
	bar(x-20,y-10,x+20,y);
}
/*画子弹,0去除,1显示*/
void DrawPlayerBullet(int x,int y,int n)
{
	if(n==0)
		setfillstyle(SOLID_FILL,BLUE);
	else
		setfillstyle(SOLID_FILL,0);
	setcolor(BLUE);
	fillellipse(x,y,5,5);
}
/*画子弹,0去除,1显示*/
void DrawEnemyBullet(int x,int y,int n)
{
	if(n==0)
		setfillstyle(SOLID_FILL,BLUE);
	else
		setfillstyle(SOLID_FILL,YELLOW);/*敌人的炮弹是黄的*/
	setcolor(BLUE);
	fillellipse(x,y,3,3);
}
void PrintScore()/*输出得分*/
{
	setfillstyle(SOLID_FILL,8);/*把原来分数去除*/
	bar(30,0,200,40);
	setcolor(11);/*输出新得分*/
	settextstyle(0,0,2);
	sprintf(scorestring,"%d",score);
	outtextxy(30,20,scorestring);
}
void PlayGame(void)/*具体玩游戏*/
{
	int i,j;
	setfillstyle(SOLID_FILL,BLUE);
	bar(0,100,640,480);
	setfillstyle(SOLID_FILL,8);
	bar(0,0,640,99);
	Player.x=200;Player.y=99;/*玩家初始位置*/
	for(i=0;i<6;i++)
	{
		Player.bullet[i].shoot=0;/*一开始的子弹都为没发射状态*/
		enemyBullet[i].shoot=0;
		Enemy[i].life=0;
	}
	Player.life=1;
	DrawPlayer();/*玩家初始位置*/
	PrintScore();/*输出得分*/
	randomize();
	while(1)
	{
	 for(i=0;i<6;i++)/*查找玩家是否有发射的子弹*/
	 {
	  if(Player.bullet[i].shoot==1)/*发射的子弹*/
	  {
		 DrawPlayerBullet(Player.bullet[i].x,Player.bullet[i].y,0);/*去除原来子弹位置*/
	   Player.bullet[i].y+=3;
		 DrawPlayerBullet(Player.bullet[i].x,Player.bullet[i].y,1);/*显示新位置*/
	   for(j=0;j<6;j++)/*判断子弹是否击中敌人*/          
			if(Player.bullet[i].x>(Enemy[j].x-22)&&Player.bullet[i].x<(Enemy[j].x+22)&&Player.bullet[i].y>(Enemy[j].y-14)&&Player.bullet[i].y<Enemy[j].y+5)/*击中敌人*/
	    {
	     Player.bullet[i].shoot=0;/*子弹消失*/
	     Enemy[j].life=0;/*敌人生命结束*/
	     score+=10;/*得分增加*/
	     DrawPlayerBullet(Player.bullet[i].x,Player.bullet[i].y,0);/*去除原来子弹位置*/
			 DrawBlack(Enemy[j].x,Enemy[j].y,BLUE);/*去除敌人*/
	     PrintScore();
	    }
	   	if(Player.bullet[i].y>480)/*子弹超出屏幕就等于消失*/
	   	{
	    	Player.bullet[i].shoot=0;
	    	DrawPlayerBullet(Player.bullet[i].x,Player.bullet[i].y,0);
	   	}
	  }
	 }
	for(i=0;i<6;i++)/*敌人炮弹的产生*/
	{
	 
	if(Enemy[i].life==1&&Enemy[i].color<14&&enemyBullet[i].shoot==0)/*敌人发射炮弹的条件*/
	 {
	  enemyBullet[i].shoot=1;
	  enemyBullet[i].x=Enemy[i].x;
	  enemyBullet[i].y=Enemy[i].y-10;
	 }
	}
	for(i=0;i<6;i++)/*敌人炮弹移动以及移动*/
	{
	 if(enemyBullet[i].shoot==1)/*子弹存在*/
	 {
		 DrawEnemyBullet(enemyBullet[i].x,enemyBullet[i].y,0);
		 enemyBullet[i].y-=2;
		 DrawEnemyBullet(enemyBullet[i].x,enemyBullet[i].y,1);/*画敌人炮弹新位置*/
	 }
	 
	if(enemyBullet[i].x>(Player.x-14)&&enemyBullet[i].x<(Player.x+14)&&(enemyBullet[i].y+3)<100)/*击中玩家*/
	 {
		  Player.life=0;
		  enemyBullet[i].shoot=0;
		  DrawEnemyBullet(enemyBullet[i].x,enemyBullet[i].y,0);
		  DrawBlack(Player.x,Player.y,8);/*去除玩家*/
		  break;
	 }
	 if(enemyBullet[i].y<96)/*敌人炮弹超出海洋就消失*/
	 {
		 enemyBullet[i].shoot=0;
		 setfillstyle(SOLID_FILL,8);
		 setcolor(8);
		 fillellipse(enemyBullet[i].x,enemyBullet[i].y,3,3);
	 }
	}
	delay(speed*1000);/*间隔时间可以自己定*/
	if(Player.life!=1)/*玩家被击中*/
		break;
	for(i=0;i<6;i++)
	{
	 if(Enemy[i].life==0)/*出现一个敌人后就跳出循环*/
	 {
		 Enemy[i].life=1;
		 Enemy[i].color=rand()%4+10;/*敌人的颜色*/
		 Enemy[i].y=rand()%300+130;/*高度随机*/
		 Enemy[i].speed=2+rand()%10;/*敌人的移动速度随机*/
		
		 Enemy[i].direction=rand()%2;/*敌人的移动方向,0左边,1右边出来*/
		 if(Enemy[i].direction==0)
		 		Enemy[i].x=-20;
		 else
		 		Enemy[i].x=660;
		 break;
	 }
	}
	if(GetKey(ESCGAME))/*退出键*/
		break;
	if(GetKey(SHOOT))/*发射*/
	{
	 for(i=0;i<6;i++)
	 if(Player.bullet[i].shoot==0)/*发射一颗子弹后跳出循环*/
	 {
	  	Player.bullet[i].x=Player.x;
	  	Player.bullet[i].y=105;
	  	Player.bullet[i].shoot=1;
	  	break;
	 }
	}
	if(GetKey(MOVERIGHT)&&Player.x<620)/*右键盘的控制*/
	{
		DrawBlack(Player.x,Player.y,8);
		Player.x+=10;
		DrawPlayer();
	}
	if(GetKey(MOVELEFT)&&Player.x>20)/*左键的控制*/
	{
		DrawBlack(Player.x,Player.y,8);
		Player.x-=10;
		DrawPlayer();
	}
	for(i=0;i<6;i++)/*显示敌人*/
	{
	 if(Enemy[i].life==1)/*如果敌人存在*/
	 {
	  	DrawBlack(Enemy[i].x,Enemy[i].y,BLUE);/*原来位置输出海洋颜色*/
	  	if(Enemy[i].direction==0)
	  	Enemy[i].x+=Enemy[i].speed;/*敌人横坐标的变化*/
	  	else
	  	Enemy[i].x-=Enemy[i].speed;
	  	DrawEnemy(i);/*画敌人*/
	  	if(Enemy[i].x>660||Enemy[i].x<-20)/*敌人超出屏幕范围就消失*/
	  	Enemy[i].life=0;
	 }
	}
	}
	if(Player.life==0)/*被击中失败的话*/
	{
		setcolor(6);
		settextstyle(0,0,3);
		outtextxy(250,40,"GAME OVER");
	}
	while(1)
	{
		/*结束游戏按ESC*/
		if(GetKey(ESCGAME))
		break;
	}
}

void far interrupt NewInterupt9(void)
{
	 unsigned char ScanCode,temp;
	 ScanCode=inportb(0x60);
	 temp=inportb(0x61);
	 outportb(0x61,temp | 0x80);
	 outportb(0x61,temp & 0x7f);
	 if(ScanCode&0x80)
	 {
	    ScanCode&=0x7f;
	    keyState[ScanCode]=0;
	 }
	 else
	 {
	    keyState[ScanCode]=1;
	    keyPressed[ScanCode]=1;
	 }
	 outportb(0x20,0x20);
}
void InstallKeyboard(void)
{
 	int i;
 	for(i=0;i<128;i++)
 	keyState[i]=keyPressed[i]=0;
 	OldInterupt9Handler=getvect(9);         /*中断向量值*/
 	setvect(9,NewInterupt9);                
 	/*中断程序NewInterupt9地址存入指定的中断向量表中INT 09H*/
}
void ShutDownKeyboard(void)
{
 	setvect(9,OldInterupt9Handler);
}
int GetKey(int ScanCode)
{
 	int res;
 	res=keyState[ScanCode]|keyPressed[ScanCode];
 	keyPressed[ScanCode]=0;
 	return res;
}



