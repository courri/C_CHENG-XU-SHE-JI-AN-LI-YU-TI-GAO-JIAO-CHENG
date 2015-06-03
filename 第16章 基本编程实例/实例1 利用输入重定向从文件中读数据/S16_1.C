#include <stdio.h>
int main()
{int m, max, score, i, k;
 scanf("%d %*s%*d,%*d,%d", &m, &max);
 for(i=2; i<=5; i++){
   scanf("%d %*s%*d,%*d,%d", &k, &score);
   if(score>max){
     m=k;
     max=score;
   }
 }
 printf("%d,%d\n", m, max);
 getch();
 return 0;
}

