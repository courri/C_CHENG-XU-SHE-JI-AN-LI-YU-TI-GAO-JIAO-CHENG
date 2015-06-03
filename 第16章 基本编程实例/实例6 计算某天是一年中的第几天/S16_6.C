#include<stdio.h>
int main( )
{int  year, month, day;
 int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};  /*存储12个月份的天数*/
 int  i, n=0;
 scanf("%d%d%d", &year, &month, &day);
 for(i=1; i<month; i++)
   n+=m[i];
 n+=day;
 if((year%4==0&&year%100!= 0||year%400==0)&&month>=3)
   n++;
 printf("%d\n", n);
 getch();
 return 0;
}
