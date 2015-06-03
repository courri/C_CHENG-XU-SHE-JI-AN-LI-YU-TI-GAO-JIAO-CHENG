#include <stdio.h>
#include <dos.h>
#include <conio.h>
int main()
{struct time curtime;
 float cur_hour, cur_min, cur_sec;
 clrscr();
 do
   {
    printf("The current time is:\n");
    gettime(&curtime);
    if(curtime.ti_hour<12)
      printf("AM ");
    else{
      printf("PM ");
      if(curtime.ti_hour>=13)
	 curtime.ti_hour-=12;
    }

    if(curtime.ti_hour<10)
      printf("0");
    printf("%d:",curtime.ti_hour);
    if(curtime.ti_min<10)
      printf("0");
    printf("%d:",curtime.ti_min);
    if(curtime.ti_sec<10)
      printf("0");
    printf("%d",curtime.ti_sec);
    sleep(1);
    clrscr();
   }while(!kbhit());
 return 0;
}
