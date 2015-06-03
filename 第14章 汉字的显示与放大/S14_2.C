#include "stdio.h"
#include "stdlib.h"
#include "graphics.h"

#define S 16                 /*  S:汉字点阵数*/
#define HZK  "G:\\tc\\hzk16f"  /*汉字字库路径及文件名*/

void disphz(int x,int y,char *p,int color,int m)   /*m是放大倍数*/
{int  i, j, n, k;
 FILE *fp;
 char qh,wh;
 long offset;
 char buffer[S*S/8];
 char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};

 if ((fp = fopen(HZK,"rb")) == NULL)
   exit(0);
 while(*p != '\0'){
    qh = *p - 0xa0;          /*计算区号*/
    p++;
    wh =*p - 0xa0;          /*计算位号*/
    p++;
    offset = (94L* (qh -1) + wh -1) * S * S / 8;   /*计算地址码*/
    fseek(fp,offset,0);
    fread(buffer, S * S / 8, 1, fp);
    for ( i = 0 ;i<S; i++){
      for( j = 0; j<S; j++){
	 if (( buffer[S/8*i+j/8] & mask[j%8]) != 0)
	    for( n = 0; n<m; n++)
	       for( k = 0; k<m; k++)
		 putpixel( x+j*m+n, y+i*m+k, color);
      }
    }
    x += S *m + 5;
 }
 fclose(fp);
}

int main()
{
 int device = VGA;
 int mode = VGAHI;
 char *p = "汉字的放大";
 initgraph(&device,&mode,"");
 disphz(250,200,p,YELLOW,2);
 getch();
 closegraph();
 return 0;
}
