#include "stdio.h"
#include "stdlib.h"
float get_num(char **), calculate(char **);
int main()
{char a[80];
 float result;
 char *p;
 clrscr();
 gets(a);
 p=a;
 result=calculate(&p);
 printf("%f\n", result);
 getch();
 return 0;
}


float calculate(char **p)
{float result = 0;
 int sign = 1;
 if(**p == '-')
   {sign = -1;
    (*p)++;
   }
 while(**p!=0 && **p!=')')
   {float  m;
    if(**p=='(')
      {(*p)++;
       m=sign*calculate(p);
      }
    else
      m = sign*get_num(p);
    while( **p == '*' || **p == '/' )
      {if( **p == '*' )
	 {(*p)++;
	  if(**p=='(')
	    {(*p)++;
	     m *= calculate(p);
	    }
	  else
	    m *= get_num(p);
	 }
       else
	 {int div;
	  (*p)++;
	  if(**p=='(')
	    {(*p)++;
	     div=calculate(p);
	    }
	  else
	    div = get_num(p);
	  if( div == 0 )
	    {printf("diveide by 0!\n");
	     exit(1);
	    }
	  else
	    m /= div;
	 }
      }
    if(**p !='+' && **p!='-' && **p!=0 && **p!=')')
      {printf("illege character: %c\n",**p);
       exit(0);
      }
    result += m;
    if(**p == '+')
      {sign = 1;
       (*p)++;
      }
    else
      if(**p =='-')
	{sign=-1;
	 (*p)++;
	}
      else
	if(**p==')')
	  {(*p)++;
	   break;
	  }
	else
	  break;
   }

 return result;
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