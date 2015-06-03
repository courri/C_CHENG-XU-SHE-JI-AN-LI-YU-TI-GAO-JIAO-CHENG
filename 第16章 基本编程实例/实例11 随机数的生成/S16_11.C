#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
 int i, j, n[11],k,t;
 randomize();
 for(i=1; i<=10; i++)
   {
    n[i] = random(200)+1;
    for(j=1; j<i; j++)
      if(n[i] == n[j])
	{
	 i--;
	 break;
	}
   }


 for(i=1; i<=9; i++)
   {
    k=i;
    for(j=i+1; j<=10; j++)
      if(n[j]<n[k])
	k=j;
    t=n[i];
    n[i]=n[k];
    n[k]=t;
   }
 for(i=1; i<=10; i++)
   printf("%5d", n[i]);
 printf("\n");
 getch();
 return 0;
}


