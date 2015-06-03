#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define IMAGE_SIZE 10
void draw_image(int x,int y);
void putstar(void);
main()
{
   int driver=DETECT;
   int mode,color;
   void *pt_addr;
   int x,y,maxy,maxx,midy,midx,i;
   unsigned size;
   initgraph(&driver,&mode,"");
   maxx=getmaxx();  
   maxy=getmaxy();  
   midx=maxx/2;
   x=0;
   midy=y=maxy/2;
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   outtextxy(midx,400,"AROUND THE WORLD");
   setbkcolor(BLACK);
   setcolor(RED);
   setlinestyle(SOLID_LINE,0,THICK_WIDTH);
   ellipse(midx,midy,130,50,160,30);
   draw_image(x,y);      size=imagesize(x,y-IMAGE_SIZE,x+(4*IMAGE_SIZE),y+IMAGE_SIZE);
   pt_addr=malloc(size);
   getimage(x,y-IMAGE_SIZE,x+(4*IMAGE_SIZE),y+IMAGE_SIZE,pt_addr);
   putstar();
   setcolor(WHITE);
   setlinestyle(SOLID_LINE,0,NORM_WIDTH);
   rectangle(0,0,maxx,maxy);   while (!kbhit())
   {
     putstar(); 
     setcolor(RED);
     setlinestyle(SOLID_LINE,0,THICK_WIDTH);
     ellipse(midx,midy,130,50,160,30);
     setcolor(BLACK); 
     ellipse(midx,midy,130,50,160,30);
     for (i=0;i<=13;i++)
     {
       setcolor(i%2==0 ? LIGHTBLUE:BLACK);
       ellipse(midx,midy,0,360,100-8*i,100);
       setcolor(LIGHTBLUE);
       ellipse(midx,midy,0,360,100,100-8*i);
     }
     putimage(x,y-IMAGE_SIZE,pt_addr,XOR_PUT);
     x=x>=maxx?0:x+6;
     putimage(x,y-IMAGE_SIZE,pt_addr,COPY_PUT);
   }
   free(pt_addr);
   closegraph();
   return;
}
void draw_image(int x,int y)
{
int arw[11];
 arw[0]=x+10;  arw[1]=y-10;
 arw[2]=x+34;  arw[3]=y-6;
 arw[4]=x+34;  arw[5]=y+6;
 arw[6]=x+10;  arw[7]=y+10;
 arw[8]=x+10;  arw[9]=y-10;
 moveto(x+10,y-4);
 setcolor(14);
 setfillstyle(1,4);
 linerel(-3*10,-2*8);
 moveto(x+10,y+4);
 linerel(-3*10,+2*8);
 moveto(x+10,y);
 linerel(-3*10,0);
 setcolor(3);
 setfillstyle(1,LIGHTBLUE);
 fillpoly(4,arw);
}
void putstar(void)
{
 int seed=1858;
 int i,dotx,doty,h,w,color,maxcolor;
  maxcolor=getmaxcolor();   
 w=getmaxx();
 h=getmaxy();
 srand(seed);
 for(i=0;i<250;++i)
 {
  dotx=i+random(w-1);
  doty=1+random(h-1);
  color=random(maxcolor);
  setcolor(color);
  putpixel(dotx,doty,color);
  circle(dotx+1,doty+1,1);
 }
 srand(seed);
}

