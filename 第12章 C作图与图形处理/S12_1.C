#include  <graphics.h>
int main()
{
 int gmode, gdriver = DETECT;
 int gerror;
 initgraph(&gdriver,&gmode,"");
 gerror = graphresult();
 if(gerror < 0)         /*如果出错，打印错误信息*/
   {
    printf("Graphics initialization error.");
    printf("%s", grapherrormsg(gerror));
    return 1 ;
   }
 cleardevice();
 setcolor(RED);      /*设置颜色*/
 circle(320,240,50); /*画圆*/
 getch();            /*等待用户输入一个键后继续*/
 closegraph();
 return 0;
}
