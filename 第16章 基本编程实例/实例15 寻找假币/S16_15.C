#include "time.h"
#include <stdio.h>
#include "stdlib.h"
int main()
{int i,j,k,m,s1,s2,c[81];
 for(i=1;i<=80;i++)
    c[i]=1;
 randomize();
 c[random(80)+1]=0;
 k=1;
 m=27;
 for(i=1;i<=4;i++)
    {s1=s2=0;
     for(j=k;j<m+k;j++)
	{s1+=c[j];
	 s2+=c[j+m];
	}
     if(s1>s2)
       k+=m;
     if(s1==s2)
       k+=2*m;
     m/=3;
    }
 printf("%d\n",k);
 getch();
 return 0;
}