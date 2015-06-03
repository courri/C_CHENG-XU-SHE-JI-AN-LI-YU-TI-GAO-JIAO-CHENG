#include <stdio.h>
#include <dos.h>

int main()
{void  sound(unsigned int);
 unsigned int freq;
 do
   {
    freq=rand()%8000+1;     /*rand()%8000产生的最小数是0，不能作除数*/
    sound(freq);
   }while(!kbhit());           /*有按键时kbhit返回键值，否则返回0*/
 return 0;
}

void  sound(unsigned int freq)
{
 union
   {
    int divisor;
    char c[2];
   }count;
 char bits;
 count.divisor = 1193180/freq;
 outportb(0x43,0xb6);
 bits = inportb(0x61); 
 outportb(0x42,count.c[0]);
 outportb(0x42,count.c[1]); 
 outportb(0x61,bits|3);
 delay(5000);                /*延时*/
 outportb(0x61, bits&0xfc);
 outportb(0x61, bits);
}

