#include <stdio.h>
#include <dos.h>

void  mysound(unsigned int freq, int times)    /*times是音符演奏时间相比十六分音符的倍数*/
{
 int  i;
 union
   {
    int divisor;
    char c[2];
   }count;
 char bits;

 count.divisor =1193180/freq;

 outportb(0x43, 0xb6);
 outportb(0x42, count.c[0]);
 outportb(0x42, count.c[1]);
 
 bits=inportb(0x61);
 outportb(0x61, bits|3);
 for( i = 0; i<times; i++ )
    delay(25000);     /*延时长短决定演奏速度*/
 outportb(0x61, bits&0xfc);
 outportb(0x61, bits);
}

int main()
{
 int freq[8] = {0,262,294,330,349,392,440,494};
 int song[] = {5,3,5,8,6,8,6,5,5,1,2,3,2,1,2,5,3,5,8,8,7,6,8,5,5,2,3,4,4,-7,1, 0};
 int div[] = {4,8,8,2,4,8,8,2,4,8,8,4,8,8,1,4,8,8,4,8,8,4,4,2,4,8,8,4,8,8,1,0};  /*几分音符*/
 unsigned int f;
 int times,i;
 for( i = 0; song[i] ; i++)
   {
    if(song[i] < 0)
      f = freq[-song[i]]/2;
    else
      if(song[i] > 7)
	f = freq[song[i] % 7]*2;
      else
	f = freq[song[i]];
    times =16/div[i];      /*times是音符演奏时间相比十六分音符的倍数*/
    mysound(f,times);      
 }
 return 0;
}
