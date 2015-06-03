#include "stdio.h"
#include "stdlib.h"
float get_num(char **);

int main()
{char a[80];
 int sign = 1;
 float result = 0;
 char *p;
 clrscr();
 gets(a);
 p=a;
 if(*p == '-')
   {sign = -1;
    p++;
   }
 while(*p!=0)
   {float  m;
    m = sign*get_num(&p);
    while( *p == '*' || *p == '/' )
      {if( *p == '*' )
	 {p++;
	  m *= get_num(&p);
	 }
       else
	 {int div;
	  p++;
	  div = get_num(&p);
	  if( div == 0 )
	    {printf("diveide by 0!\n");
	     exit(1);
	    }
	  else
	    m /= div;
	 }
      }
    if(*p !='+' && *p!='-' && *p!=0)
      {printf("illege character: %c\n",*p);
       exit(0);
      }
    result += m;
    if(*p == '+')
      {sign = 1;
       p++;
      }
    else
      if(*p =='-')
	{sign=-1;
	 p++;
	}
      else
	break;
   }
 printf("The result is %f\n", result);
 getch();
 return 0;
}

float get_num(char **p)
{float n = 0, m = 10;
 if(**p != '.' && (**p <'0' || **p >'9') )
   {printf("get num error!\n");
    exit(1);
   }
 while(**p >='0' && **p <='9')
   {n = n*10 + **p - 48;
    (*p)++;
   }
 if(**p == '.')
   {(*p)++;
    while(**p >='0' && **p <='9')
      {n += (**p - 48)/m;
       (*p)++;
       m *= 10;
      }
   }
 return n;
}
