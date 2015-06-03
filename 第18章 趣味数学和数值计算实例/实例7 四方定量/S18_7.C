#include<stdio.h>
void verify_four_squares(int number)
{
    int i,j,k,l;
    for(i=1;i<number/2;i++)
	        for(j=0;j<i;j++)
	            for(k=0;k<j;k++)
	                for(l=0;l<k;l++)
	                    if(number==i*i+j*j+k*k+l*l)
	                    {
				printf(" >> %d=%d*%d+%d*%d+%d*%d+%d*%d\n",number,i,i,j,j,k,k,l,l);
				return;
	                    }
}
void main()
{
    int number=1;
    while(number!=0)
    {
	    printf(" >> Please input a number to verify(0 to quit): ");
	    scanf("%d",&number);
	    if(number==0)
		break;
	    printf(" >> ------ Results of verification: ------------\n");
	    verify_four_squares(number);
	    printf(" >> ---------------------------------------------\n");
    }
    puts("\n Press any key to quit...");
    getch();
}
