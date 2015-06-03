#include <stdio.h>
int main()
{int x, s;
 scanf("%d", &x);
 s = (x%3==0) + (x%5 == 0) * 2 + (x%7 == 0) * 4;
 switch(s)
   {
    case 0:  printf("none\n"); break;
    case 1:  printf("3\n"); break;
    case 2:  printf("5\n"); break;
    case 3:  printf("3,5\n"); break;
    case 4:  printf("7\n"); break;
    case 5:  printf("3,7\n"); break;
    case 6:  printf("5,7\n"); break;
    case 7:  printf("3,5,7\n"); break;
    default:  printf("error!\n");
   }
 getch();
 return 0;
}
