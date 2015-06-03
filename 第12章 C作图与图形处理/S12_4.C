#include <stdio.h>
#include <graphics.h>

void save_pic();
void load_pic();

int main()
{int  i, k, graphdriver = DETECT, graphmode;
 initgraph(&graphdriver,&graphmode,"");
 circle(320,240,50);
 save_pic();
 getch();
 cleardevice();
 getch();
 load_pic();
 getch();
 closegraph();
 return 0;
}

void save_pic()
{FILE *fp;
 int i;
 long j;
 char far *p;
 fp=fopen("pic.dat","wb");
 for(i=0;i<4;i++)
   {
    outportb(0x3ce,4);
    outportb(0x3cf,i);
    p=(char far*)0xa0000000L;
    for(j=0;j<38400L;j++)
      {
       putc(*p,fp);
       p++;
      }
   }
 fclose(fp);
 outportb(0x3cf,0);
}

void load_pic()
{FILE *fp;
 int  i, k = 1;
 long j;
 char far *p;
 fp = fopen("pic.dat","rb");
 for( i = 0; i<4; i++)
   {
    outportb(0x3c4,2);
    outportb(0x3c5,k);
    p = (char far*)0xa0000000L;
    for( j = 0; j<38400; j++)
      {
       *p = getc(fp);
       p++;
      }
    k *= 2;
   }
 fclose(fp);
 outportb(0x3c5,0xf);
}