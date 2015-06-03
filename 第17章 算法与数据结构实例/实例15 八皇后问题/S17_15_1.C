#include <math.h>
#include <stdio.h>
#define  MAX  8         /* 棋子数及棋盘大小MAXxMAX */
int board[MAX];
int count=0;

/* 印出結果 */
void show_result()
{int i;
 for(i=0;i<MAX;i++)
    printf("(%d,%d),",i+1,board[i]+1);
 printf("\n");
}

/* 检查是否在同一直橫斜线上有其它棋子 */
int check_cross(int n)
{int i;
 for(i=0;i<n;i++)
   if(board[i]==board[n] || (n-i)==abs(board[i]-board[n]))
      return 1;
 return 0;
}

/* 放棋子到棋盘上 */
void put_chess(int n)
{int i;
 for(i=0;i<MAX;i++)
   {board[n]=i;
    if(!check_cross(n))
      {
       if(n==MAX-1)
	 {count++;
	  printf("%3d: ", count);
	  show_result();  /* 找到其中一种放法了...印出結果 */
	  if(count%24==0)   /*每24行一屏暂停*/
	    {getch();
	     clrscr();
	    }
	 }
       else
	 put_chess(n+1);
      }
   }
}

void main()
{clrscr();
 puts("The possible placements are:");
 put_chess(0);
 puts("\n Press any key to quit...");
 getch();
 return;
}

