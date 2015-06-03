#include<stdio.h>
int main()
{int n, count = 0; 
printf(">>Please input a number to verify(0 to quit):");
 scanf("%d",&n);     
while(n != 0){  	   
	   printf(">>------Results of verification:-------\n");
	   do{
	      if(n % 2){
	        n = n*3 + 1;           
		        printf(">>Step No.%d: %d*3+1=%d\n",++count,(n-1)/3,n);
	      }
	      else {
	        n /= 2;               
		        printf(">>Step No.%d: %d/2=%d\n",++count,2*n,n);
	      }
	   }while(n != 1);             
	   printf(">> -----------------------  ----------\n");
  printf(">>Please input a number to verify(0 to quit):");
   scanf("%d",&n);     
 }
 puts("\n Press any key to quit...");
 getch();
 return 0;
}
