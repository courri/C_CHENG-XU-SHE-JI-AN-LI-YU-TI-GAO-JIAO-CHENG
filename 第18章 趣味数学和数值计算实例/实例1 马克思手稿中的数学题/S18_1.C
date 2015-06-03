#include <stdio.h>
void main()
{
      int x,y,z,count=0;

      puts(" >> The solutions are:");
      printf("   No.        Men       Women     Children\n");
      printf("---------------------------------------------\n");
      for(x=1;x<=10;x++)
      {
           y=20-2*x;                   /*x定值据(3)式求y*/
           z=30-x-y;                   /*由(1)式求z */
	   if(3*x+2*y+z==50 && y && z)           /*当前得到的一组解是否满足式(2) */
	       printf(" <%2d>    |    %2d    |    %2d    |    %2d\n",++count,x,y,z);
      }
      printf("---------------------------------------------\n");
      printf(" Press any key to quit...");
      getch();
}
