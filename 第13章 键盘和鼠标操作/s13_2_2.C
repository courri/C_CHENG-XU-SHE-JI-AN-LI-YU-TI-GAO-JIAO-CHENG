#include <dos.h>
#include <stdio.h>
#include <graphics.h>
int init();
int read_mouse();
void cursor(),newxy();
int main()
{
 int buttons,x,y;
 char str[100];
 int driver=VGA;
 int mode=VGAHI;
 initgraph(&driver,&mode,"");
 cleardevice();
 rectangle(0,0,639,479);
 setfillstyle(SOLID_FILL,BLUE);
 bar(1,1,638,478);
 outtextxy(3,15,"move mouse using any button.");
 outtextxy(285,15,"quit");
 setwritemode(XOR_PUT);
 if(init(2, 638, 8, 477)==0 )     /*调用init 函数对鼠标器初始化*/
   {printf("Mouse or Mouse Driver Absent,P1ease install!");
    delay(5000);
    closegraph();
    exit(1);
   }
 x=320;y=240;
 cursor(x,y);                       /*置十字光标在屏幕中心*/
 for(;;)
   {
    newxy(&x,&y,&buttons);
    if(x>=280 && x<=330 && y>=12 && y<=33 && buttons)
      {
       cleardevice();
       closegraph();
       exit(0);
      }
   }
}
void cursor(int x,int y)            /* 画十字光标函数 */
{
 int x1,x2,y1,y2;
 x1=x-4;
 x2=x+4;
 y1=y-3;
 y2=y+3;
 line(x1,y,x2,y);
 line(x,y1,x,y2);
}
int init(int xmin,int xmax,int ymin,int ymax)  /*初始化函数 */
{_AX=0;
 geninterrupt(0x33);
 if(_AX == 0)
   return 0;         /* 返回0 表示鼠标或鼠标驱动程序未安装 */
 _AX=7;
 _CX=xmin;
 _DX=xmax;
 geninterrupt(0x33);
 _AX=8;
 _CX=ymin;
 _DX=ymax;
 geninterrupt(0x33);
 return -1;         /* 表示鼠标器和驱动程序已安装 */
}
int read_mouse(int *mx,int *my,int *mbutton)
{
 int x0=*mx, y0=*my, button0=*mbutton;
 int xnew, ynew;
 do
   {_AX=3;
    geninterrupt(0x33);
    xnew=_CX;
    ynew=_DX;
    *mbutton=_BX;
   }while(xnew == x0 && ynew == y0 && *mbutton == button0);
 *mx=xnew;
 *my=ynew;
 switch(*mbutton)
   {
    case 0:   return 0;
    case 1:   return 1;
    case 2:   return 2;
    case 3:   return 3;
    default:  return 4;
   }
}

void newxy(int *mx,int *my,int *mbutt)
{
 int ch,xx0=*mx,yy0=*my;
 int xm,ym;
 ch=read_mouse(&xm,&ym,mbutt);
 cursor(xx0,yy0);
 cursor(xm,ym);
 switch(ch)
   {
    case 0:
	   break;
    case 1:
	   circle(xm,ym,6);
	   break;
    case 2:
	   rectangle(xm,ym,xm+12,ym+12);
	   break;
    default:
	   putpixel(xm,ym,7);
	   break;
   }
 *mx=xm;
 *my=ym;
}


