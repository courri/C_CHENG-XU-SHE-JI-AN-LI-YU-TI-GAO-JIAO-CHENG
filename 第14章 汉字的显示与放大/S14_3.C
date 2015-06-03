#include "stdio.h"
#include "stdlib.h"
#include "graphics.h"
#define  S 16                      /*汉字点阵数*/
#define  HZK  "G:\\tc\\hzk16f"     /*汉字字库路径及文件名*/

void  disphz(int x, int y, char *s, int color)   /*s是汉字机内码地址*/
{
 char  far  *p;
 char  mask[]={0x01,0x02,0x04,0x08};
 int  i, j, n;
 FILE *fp;
 char qh,wh;
 long offset;
 char buffer[S*S/8];
 if ((fp = fopen(HZK,"rb")) == NULL)
   exit(0);
 qh = *s - 0xa0;                              /*计算区号*/
 wh = *(s +1) -0xa0;                          /*计算位号*/
 offset = (94L*(qh -1) + wh -1) * S * S /8;   /*计算地址码*/
 fseek(fp,offset,0);
 fread(buffer, S *S /8,1, fp);
 fclose(fp);

 outportb(0x3ce, 4);   /*使口地址0x3cf对应读位面选择寄存器*/
 outportb(0x3c4, 2);   /*使口地址0x3c5对应颜色位面写允许寄存器*/

 p = (char far*)(0xa0000000+80*y + x/8);
 for( i = 0; i<S; i++)
   for( j = 0; j<S/8; j++)
     for(n = 0; n<4; n++)             /*n表示要操作的位面号*/
	{
	 outportb(0x3cf,n);           /*使位面n可读*/
         outportb(0x3c5, mask[n]);    /*使位面n（仅位面n）可写*/
	 if((color&mask[n])!=0)
	   *(p+80*i+j)|=buffer[S*i/8+j];
	 else
	   *(p+80*i+j)&=~(buffer[S*i/8+j]);
	}
 outportb(0x3cf,0);
 outportb(0x3c5,0xf);
}

int main()
{
 int device = VGA;
 int mode = VGAHI;
 char *s = "大";
 initgraph(&device,&mode,"");   /* 初始化屏幕 */
 rectangle(250,180,355,280);    /*画一个矩形*/
 setfillstyle(1, GREEN);        /*设置填充颜色*/
 floodfill(300,200,WHITE);      /*用绿色填满一个以白色为边界的封闭区域*/
 disphz(300, 220, s, RED);      /*在指定位置用指定颜色显示指定的汉字*/
 getch();
 closegraph();
 return 0;
}

