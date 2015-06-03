#include<graphics.h>
#include <dos.h>
#include <stdlib.h>
int main()
{int i, gdriver, gmode;
 void *p;
 unsigned int size;
 gdriver = DETECT;
 initgraph(&gdriver,&gmode,"");
 cleardevice();
 setfillstyle(1,5);
 setcolor(1);
 circle(300,200,30);
 floodfill(300,200,1);
 size = imagesize(270,170,330,230);
 p = malloc(size);
 if(p == NULL)
   {closegraph();
    return 0;
   }

 getimage(270,170,330,230,p);
 do
   {
    for(i=0;i<50;i++)
      {
       cleardevice();
       putimage(10+i*10, 200, p, COPY_PUT);
       delay(500);
      }
   }while(!kbhit());
 free(p);
 closegraph();
 return 0;
}
