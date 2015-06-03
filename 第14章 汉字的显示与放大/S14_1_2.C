#include "stdio.h"
#include "stdlib.h"
#include "graphics.h"
#define S 16                 /* S:汉字点阵数 */
#define HZK  "G:\\tc\\hzk16f"  /*汉字字库路径及文件名*/

void disphz(int x,int y,char *p,int color)
 /* x,y是汉字显示的坐标, p: 汉字串的首址,color:颜色*/
{int  i, j;
 FILE *fp;
 char  qh, wh;
 long  offset;
 char  buffer[S*S/8];
 char  mask[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};

 if (( fp = fopen(HZK,"rb")) == NULL)
   exit(0);
 while(*p!='\0')
   {
    qh = *p - 0xa0;          /*计算区号*/
    p++;
    wh = *p - 0xa0;          /*计算位号*/
    p++;
    offset = (94L * (qh -1) + wh - 1) * S * S / 8;   /*计算地址码*/
    fseek(fp,offset,0);
    fread(buffer,S*S/8,1,fp);
    for ( i = 0; i <= S -1; i++)
      {
       for ( j = 0; j <= S -1; j++)
	 if (((buffer[S/8*i+j/8]) & mask[j%8]) != 0)
	    putpixel(x+j, y+i, color);

      }
    x+=S+5;      /*下一个汉字的坐标（横向显示），字间距为5像素*/
   }
 fclose(fp);
}

int main()
{char s[]="汉字显示程序";
 int mode,driver=DETECT;
 initgraph(&driver,&mode,"");
 disphz(250,200,s,RED);
 getch();
 closegraph();
 return 0;
}