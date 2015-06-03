#include<stdio.h>
int main( )
{int  year, month, day;
 int  d=0;
 scanf("%d%d%d", &year, &month, &day);
 switch(month)
   {
    case 12:  d += 30;           /*加上11月的30天*/
    case 11:  d += 31;           /*加上10月的31天*/
    case 10:  d += 30;           /*加上 9月的30天*/
    case  9:  d += 31;
    case  8:  d += 31;
    case  7:  d += 30;
    case  6:  d += 31;
    case  5:  d += 30;
    case  4:  d += 31;
    case  3:  d += 28;            /*先按平年算，加上2月的28天，最后再考虑闰年*/
    case  2:  d += 31;            /*加上 1月的31天*/
    case  1:  d += day;           /*加上当月天数*/
   }
 if((year%4==0&&year%100!=0||year%400==0)&&month>=3)  /*闰年且在3月后*/
   d++;
 printf("%d\n", d);
 return 0;
}
