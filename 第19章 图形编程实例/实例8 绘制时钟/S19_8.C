#include<graphics.h>
#include<math.h>
#include<dos.h>
#define PI 3.1415926
#define mid_x 320    /*定义钟表中心坐标*/
#define mid_y 240

int main()
{
	int graphdriver=0,graphmode;
	int end_x,end_y;
 	struct time curtime;
 	float th_hour,th_min,th_sec;
	initgraph(&graphdriver,&graphmode,"");
 	setbkcolor(0);
 	while(! kbhit())/*有键盘输入时退出*/
 	{
 		/*画表盘*/
 		setcolor(14);
  		circle(mid_x,mid_y,150);
  		circle(mid_x,mid_y,2);
 		gettime(&curtime);   /*得到当前系统时间*/
    		/*以下三行计算表针转动角度，以竖直向上为起点，顺时针为正*/
   		th_sec=(float)curtime.ti_sec*0.1047197551;                 /*2π/60=0.1047197551*/
   		th_min=(float)curtime.ti_min*0.1047197551+th_sec/60.0;
   		th_hour=(float)curtime.ti_hour*0.523598775+th_min/12.0;    /*2π/12=0.5235987755*/
   		/*画时针*/
   		end_x=mid_x+70*sin(th_hour);
  		end_y=mid_y-70*cos(th_hour);
  		setcolor(5);
  		line(mid_x,mid_y,end_x,end_y);    
   		/*画分针*/
   		end_x=mid_x+110*sin(th_min);
  		end_y=mid_y-110*cos(th_min);
 		setcolor(5);
  		line(mid_x,mid_y,end_x,end_y);  
   		/*画秒针*/
   		end_x=mid_x+140*sin(th_sec);
  		end_y=mid_y-140*cos(th_sec);
  		setcolor(5);
  		line(mid_x,mid_y,end_x,end_y);
   		sleep(1);      /*延时一秒后刷新*/
   		cleardevice();
   	}
 	closegraph();
 	return 0;
}
