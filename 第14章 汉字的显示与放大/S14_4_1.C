#include <stdio.h>
#include "stdlib.h"
#include <graphics.h>
#define S 16                   /*  S:汉字点阵数  */
#define HZK  "g:\\tc\\hzk16f"  /*汉字字库路径及文件名*/

void  disphz(int x, int y, char *s, int color)    /*s是汉字内码的首地址*/
{char  far  * p;
 int  i, j;
 FILE *fp;
 char qh,wh;
 long offset;
 char buffer[S*S/8];
 if (( fp = fopen(HZK,"rb")) == NULL)
   exit(0);
 qh = *s - 0xa0;                               /*计算区号*/
 wh = *(s +1) - 0xa0;                          /*计算位号*/
 offset = (94L*(qh -1) + wh -1) * S * S / 8;   /*计算地址码*/
 fseek(fp,offset,0);
 fread(buffer, S*S/8,1,fp);
 fclose(fp);
 p = (char far*)(0xa0000000 + 80*y + x/8);
 for( i = 0; i<S; i++)
    for( j = 0; j<S/8; j++)
      {int t;
       t=*(p + 80*i + j);
       outportb(0x3ce,5);
       outportb(0x3cf,2);
       outportb(0x3ce,8);
       outportb(0x3cf, buffer[S/8*i + j ]);
       *(p + 80*i + j) = color;
      }
 outport(0x3ce,0x0005);   /*恢复默认的写方式0，其中高字节0x00送入0x3cf寄存器*/
 outport(0x3ce,0xff08);   /*位屏蔽寄存器不再屏蔽*/
}


int main()
{
 int device = VGA;
 int mode = VGAHI;
 char *s1 = "大",*s2="小";
 initgraph(&device,&mode,"");   /* 初始化屏幕 */
 cleardevice();
 disphz(300, 220, s1, RED);      /*在指定位置用指定颜色显示指定的汉字*/
 disphz(305, 222, s2, GREEN);
 getch();
 closegraph();
 return 0;
}

