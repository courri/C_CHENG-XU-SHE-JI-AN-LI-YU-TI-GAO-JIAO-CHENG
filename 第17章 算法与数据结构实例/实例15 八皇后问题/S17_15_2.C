#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

int nQueens_nonrecursive(int *a,int n)
{
	int top,i,j,conflict;
	if(n<=0) return FALSE;
	top=-1;
	i=0;
	do
	{
		conflict=FALSE;
		for(j=0;j<top+1;j++)
			if(i==a[j]||top+1-j==i-a[j]||top+1-j==a[j]-i)
				conflict=TRUE;
			if(conflict==FALSE)
			{
				a[++top]=i;
				if(top==n-1) return TRUE;
				i=0;
			}
			else
			{
				while(i==n-1&&top>=0) i=a[top--];
				  i++;
			}

	}while(i<n);
	return FALSE;
}
void printsolution(int *a,int n)
{
	int i,j;
	printf("\nPlace queens in the following positions:\n");
	for(i=0;i<n;i++)
	{
		printf("Row%3d--Col%3d:|",i,a[i]);
		for(j=0;j<a[i];j++)printf(" |");
		  printf("Q|");
		for(j=a[i]+1;j<n;j++) printf(" |");
		  printf("\n");
	}
}
int main()
{
	int n,*a;
	printf("Please enter an integer as the size of the problem.\nn=");
	scanf("%d",&n);
	if(n>0)
		a=(int *)malloc(n*sizeof(int));
	else
	{
		printf("Error!Invalid input.\n");
		return 0;
	}
	if(nQueens_nonrecursive(a,n)==TRUE)
		printsolution(a,n);
	else
		printf("Sorry!\nThere is no solution for %d Queens Problem!\n",n);
	free(a);
	return 1;
}