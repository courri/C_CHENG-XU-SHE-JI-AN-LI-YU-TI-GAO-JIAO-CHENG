#include <stdio.h>
#include <dos.h>

void play(int*,float*);
void mysound(unsigned int, float);

int main()
{
 int song[]={5,3,5,8,6,8,6,5,5,1,2,3,2,1,2,0,5,3,5,8,7,6,8,5,5,2,3,4,-7,1,0,
	 6,8,8,7,6,7,8,6,7,8,6,6,5,3,1,2,0,5,3,5,8,7,6,8,5,5,2,3,4,-7,1,0,100};
 float div[]={4,8,8,2,4,8,8,2,4,8,8,4,8,8,2.5,4,4,8,8,4.5,8,4,4,2,4,8,8,4.5,8,2.5,4,
	 4,4,2,4,8,8,2,8,8,8,8,8,8,8,8,2.5,4,4,8,8,4.5,8,4,4,2,4,8,8,4.5,8,2.5,4,100};  /*几分音符*/
 play(song,div);
 return 0;
}

void mysound(unsigned int freq, float times)    /*times是音符演奏时间相比十六分音符的倍数*/
{
 int  i;
 union
   {
    int divisor;
    char c[2];
   }count;
 char bits;
 if(freq)
   {count.divisor=1193180/freq;
    outportb(0x43,0xb6);    
    outportb(0x42, count.c[0]);
    outportb(0x42, count.c[1]);
	bits=inportb(0x61);
    outportb(0x61, bits|3);
   }
 for(i=0; i< times; i++)
    delay(25000);                /*延时长短决定演奏速度*/
 outportb(0x61, bits&0xfc);
 outportb(0x61, bits);
 for(i=0; i<times; i++)
    delay(2500);
}

void play(int* song, float *div)
{int freq[8]={0,262,294,330,349,392,440,494};
 unsigned int f;
 float times;
 int i;
 printf("playing ...\nPress anykey to exit\n");
 for(i=0;song[i]!=100;i++)
   {if(song[i]==0)
       f=0;
    else
      if(song[i]<0)
	 f=freq[-song[i]]/2;
      else
	if(song[i]>7)
	   f=freq[song[i]%7]*2;
	else
	   f=freq[song[i]];
    f*=1.189207;             /*C调变为降E调*/
    times=16/(int)(div[i]+0.1);
    if(div[i]-(int)(div[i]+.1)>0.4)
       times*=1.5;           /*times是音符演奏时间相比十六分音符的倍数*/
    mysound(f,times);       
    if(kbhit())
      exit(0);
   }
}
