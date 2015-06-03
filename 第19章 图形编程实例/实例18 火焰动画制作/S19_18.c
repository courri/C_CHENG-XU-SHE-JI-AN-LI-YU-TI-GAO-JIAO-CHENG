# include <stdlib.h>
# include <dos.h>
# define TRUE  1
/* 获取BIOS 8*8 西文字库的段地址和偏移量 */
void GetFontAddress()
{
  struct REGPACK regs;
  regs.r_bx=0x0300;
  regs.r_ax=0x1130;
  intr(0x10,&regs);
}
/* 设置调色板 */
void SetPal(int Color,unsigned char r,unsigned char g,unsigned char b)
{
  outportb(0x3c8,Color);
  outportb(0x3c9,r);
  outportb(0x3c9,g);
  outportb(0x3c9,b);
}
/* 屏幕定位*/
void GotoXY(int x,int y)
{
  _DH=x;
  _DL=y;
  _AH=2;
  _BX=0;
  geninterrupt(0x10);
}
/* 从键盘缓冲区内直接读出扫描码 */
unsigned int GetScanKey()
{
  int  start,end;
  unsigned int key=0;
  start=peek(0,0x41a);
  end=peek(0,0x41c);
  if (start==end) return 0;
  else
  {
    key=peek(0x40,start);
    start+=2;
    if (start==0x3e) 
    	start=0x1e;
    poke(0x40,0x1a,start);
    return(key/256);
  }
}
/* 在(x,y)处绘点 */
void SetPointXY(int x,int y,unsigned char color)
{
  pokeb(0xa000,y*320+x,color);
}
/* 取(x,y)处点的颜色 */
unsigned int GetColorXY(int x,int y)
{
  	return peekb(0xa000,y*320+x);
}
void main()
{
  int i,j;
  unsigned int x,y,c;
  /* 设置VGA 13H模式 */
	_AX=0x13;
  geninterrupt(0x10);
  GetFontAddress();
	for (x=1;x<=32;x++)
  {
    SetPal(x,x*2-1,0,0);
    SetPal(x+32,63,x*2-1,0);
    SetPal(x+64,63,63,x*2-1);
    SetPal(x+96,63,63,63);
  }
  while(GetScanKey()!=1)
  {
   	for (x=0;x<320;x+=2)
   	{
     	for (y=1;y<=202;y+=2)
     	{
       	c=(GetColorXY(x,y)+GetColorXY(x+2,y)+GetColorXY(x,y+2)+GetColorXY(x+2,y+2))>>2;
       	if (c--)
       	{
	  			poke(0xa000,(y-2)*320+x,(c<<8)+c);
	  			poke(0xa000,(y-1)*320+x,(c<<8)+c);
       	}
     	}
     	y-=2;
     	SetPointXY(x,y,random(320));
   	}
  }
  /*返回文本模式*/
  _AX=0x3;
  geninterrupt(0x10);
  return;
}
