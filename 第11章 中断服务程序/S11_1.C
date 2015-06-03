#include "stdio.h"
#include "conio.h"
#include "dos.h"
unsigned intsp,intss;
unsigned ss;

void interrupt(*oldtimer)();
void interrupt newtimer();
void install();
void on_timer();
void goxy();
void prt();

int main()
{
 char ch;
 clrscr();
 printf("\nPlease select:\n");
 printf("0-----old interrupt\n");
 printf("1-----new interrupt\n");
 printf("q-----quit\n");

 on_timer();

 while(1)
   {
    ch=getch();
    switch(ch)
      {
       case '0':
		install(oldtimer);
		break;
       case '1':
		install(newtimer);
		break;
       case 'q':
		install(oldtimer);
		system("cls");
		exit(1);
       default:
		printf("%c",ch);
      }
   }
 return 0;
}

void on_timer()
{
 ss=_SS;
 oldtimer=getvect(0x1c);
}

void install(void interrupt(*faddr)())
{
 disable();
 setvect(0x1c,faddr);
 enable();
}

void interrupt newtimer()
{
  static int n=0, sec=0;
  (*oldtimer)();
  disable();
  intsp=_SP;
  intss=_SS;
  _SP=1500*16;
  _SS=ss;
  enable();
  window(50,1,54,3);
  textcolor(YELLOW);
  textbackground(RED);
  n+=1;
  if(n==18)
    {
     sec++;
     n=0;
     if(sec>9)
       sec=0;
     clrscr();
     gotoxy(3,2);
     prt(sec+48);
    }
  disable();
  _SP=intsp;
  _SS=intss;
  enable();
}

void goxy(int x,int y)
{
 union REGS rg;
 rg.h.ah=2;
 rg.h.dl=y;
 rg.h.dh=x;
 rg.h.bh=0;
 int86(0x10,&rg,&rg);
}

void prt(char c)
{
 union REGS rg;
 rg.h.al=c;
 rg.h.ah=14;
 int86(0x10,&rg,&rg);
}

