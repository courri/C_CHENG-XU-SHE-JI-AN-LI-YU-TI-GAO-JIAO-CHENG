#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define N 30000
void main()
{
   double e=1.0,b=0.5,c,d;
   long int i;                
   float x,y;
   int c2=0,d2=0;
   puts("\n >> Result of Regular Polygon Approximating:");
   for(i=6;;i*=2)            /*正多边形边数加倍*/
   {
      d=1.0-sqrt(1.0-b*b);     
      b=0.5*sqrt(b*b+d*d);
      if(2*i*2*b-i*e<1e-15) break;         /*精度达1e-15则停止计算*/
      e=2*b;      /*保存本次正多边形的边长作为下一次精度控制的依据*/
   }
   printf("---------------------------------------------------------\n");
   printf(" >> pi=%.15lf\n",2*i*b);       
   printf(" >> The number of edges of required polygon:%ld\n",i);/*输出正多边形的边数*/
   printf("---------------------------------------------------------\n");
   randomize();
   while(c2++<=N)
   {
        x=random(101);      /*x:坐标。产生0到100之间共101个的随机数*/
        y=random(101);      /*y:坐标。产生0到100之间共101个的随机数*/
        if(x*x+y*y<=10000)     /*利用圆方程判断点是否落在圆内*/
            d2++;
   }
   puts("\n >> Result of Random Number Method:");
   printf("---------------------------------------------------------\n");
   printf(" >> pi=%f\n",4.*d2/N);    /*输出求出的π值*/
   printf("---------------------------------------------------------\n");
   puts("\n Press any key to quit...");
   getch();
}
