#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <alloc.h>
#include <math.h>
#define PI 3.1415926
int R=100;                        /*圆的半径*/
int DrawPieChart(double a[],int n);
int main()
{   int Gdriver=DETECT,Gmode;
    double a[]={0.1,0.2,0.3,0.4};  /*各部分的比例*/
    int n;
    n=sizeof(a)/sizeof(double);   /*计算数组中元素的个数*/
    clrscr();
    initgraph(&Gdriver,&Gmode," ");
    DrawPieChart(a,n);       /*画饼状图*/
    getch();
    closegraph();
    return 0;
}
int DrawPieChart(double a[],int n)
{
    int MX,MY,C=3,SX,SY,NX,NY,i;
    float ANG=0;

    MX=getmaxx()/2;
    MY=getmaxy()/2;
    setcolor(2);
    circle(MX,MY,R);
    SX=MX+R;
    SY=MY;
    line(MX,MY,SX,SY);

    for(i=0;i<n;i++)
    { ANG+=a[i];
      if(ANG>1) return 0;
      SX=MX+cos(ANG*2*PI)*R;
      SY=MY+sin(ANG*2*PI)*R;
      line(MX,MY,SX,SY);
      NX=MX+cos((ANG-1/2.0*a[i])*2*PI)*R*1/2.0;
      NY=MY+sin((ANG-1/2.0*a[i])*2*PI)*R*1/2.0;
      setfillstyle(1,C++);
      floodfill(NX,NY,2);
    }

    if(ANG<1)
    { NX=MX+cos((ANG+1/2.0*(1-ANG))*2*PI)*R*1/2.0;
      NY=MY+sin((ANG+1/2.0*(1-ANG))*2*PI)*R*1/2.0;
      setfillstyle(1,C++);
      floodfill(NX,NY,2);
    }
  return 1;
}
