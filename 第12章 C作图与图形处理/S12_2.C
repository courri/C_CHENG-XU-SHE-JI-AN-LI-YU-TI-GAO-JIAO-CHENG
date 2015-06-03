#include<graphics.h>
#include <dos.h>
int main()
{int i, gdriver, gmode;
 gdriver=DETECT;
 initgraph(&gdriver,&gmode,"");
 cleardevice();
 do
   {
    for(i=0;i<50;i++)
      {
       setfillstyle(1,i%15 + 1);
       setviewport( i*10, 200, i*10 +100, 280, 1);
       setcolor(1);
       bar3d(10,30,60,60,20,1);
       floodfill(50,25,1);
       floodfill(70,50,1);
       delay(500);
       clearviewport();
      }
   }while(!kbhit());
 closegraph();
 return 0;
}
