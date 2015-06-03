#include <stdio.h>
#include <conio.h>
#include <string.h>
void dwframe()
{
	window(1,1,25,80);
	textbackground(LIGHTBLUE);
	textcolor(YELLOW);
	clrscr();
	gotoxy(2,2);
	printf(" -------------------------------------------------------------------------");
	gotoxy(2,3);
	printf("|");
	gotoxy(76,3);
	printf("|");
	gotoxy(2,4);
	printf("|");
	gotoxy(76,4);
	printf("|");
	gotoxy(2,5);
	printf("|");
	gotoxy(76,5);
	printf("|");
	gotoxy(2,6);
	printf("|");
	gotoxy(76,6);
	printf("|");
	gotoxy(2,7);
	printf("|");
	gotoxy(76,7);
	printf("|");
	gotoxy(2,8);
	printf("|");
	gotoxy(76,8);
	printf("|");
	gotoxy(2,9);
	printf("|");
	gotoxy(76,9);
	printf("|");
	gotoxy(2,10);
	printf("|");
	gotoxy(76,10);
	printf("|");
	gotoxy(2,11);
	printf("|");
	gotoxy(76,11);
	printf("|");
	gotoxy(2,11);
	printf("|");
	gotoxy(76,11);
	printf("|");
	gotoxy(2,12);
	printf("|");
	gotoxy(76,12);
	printf("|");
	gotoxy(2,14);
	printf("|");
	gotoxy(76,14);
	printf("|");
	gotoxy(2,15);
	printf("|");
	gotoxy(76,15);
	printf("|");
	gotoxy(2,16);
	printf("|");
	gotoxy(76,16);
	printf("|");
	gotoxy(2,17);
	printf("|");
	gotoxy(76,17);
	printf("|");
	gotoxy(2,18);
	printf("|");
	gotoxy(76,18);
	printf("|");
	gotoxy(2,19);
	printf("|");
	gotoxy(76,19);
	printf("|");
	gotoxy(2,20);
	printf("|");
	gotoxy(76,20);
	printf("|");
	gotoxy(2,21);
	printf("|");
	gotoxy(76,21);
	printf("|");
	gotoxy(2,22);
	printf("|");
	gotoxy(76,22);
	printf("|");
	gotoxy(2,23);
	printf("|");
	gotoxy(76,23);
	printf("|");
	gotoxy(2,24);
        printf(" -------------------------------------------------------------------------");
}
void helpf()
{
	dwframe();
	gotoxy(25,4);
	printf("^_^ Welcome to the game! ^_^");
	gotoxy(4,6);
	printf("Game description:");
	gotoxy(5,7);
	printf(" 3 men take 3 retainers and goods to pass the river,");
	gotoxy(5,8);
	printf("the boat carrys 2 persons each time.In passing the river,");
	gotoxy(5,9);
	printf("at any bank number of men must be more than  the number");
	gotoxy(5,10);
	printf(" the retainers,or the retainers will kill the men and take the goods.\n");
	gotoxy(5,11);
	printf("Game operations: (1)Input the number of men and retainers in turn;");
	gotoxy(5,12);
	printf("                   (2)Input error keys,the fame will restart.");
	gotoxy(2,13);
	printf(" -------------------------------------------------------------------------");
}
char a[6];
char b[6];
void printcase(char a[],char b[])
{
	int i,j,xa,xb,x0,ya,yb,y0;
 	xa=xb=x0=ya=yb=y0=0;
 	gotoxy(11,14);
 	printf("This bank:                   That bank:\n");
  	for(i=0;i<6;i++)
  	{
	   	if(a[i]=='A')
	    		xa++;
	   	else if (a[i]=='B')
	    		xb++;
	   	else if(a[i]=='0')
	    		x0++;
  	}
  	gotoxy(11,15);
  	for(i=1;i<=xa;i++) 
  		printf("man ");
 	gotoxy(11,16);
  	for(i=1;i<=xb;i++)
  		printf("Retainer ");
 	gotoxy(11,17);
 	for(i=1;i<=x0;i++)
  		printf("   ");
	
 	for(j=0;j<6;j++)
 	{
	  	if(b[j]=='A')
	   		ya++;
	  	else if(b[j]=='B')
	   		yb++;
	 	else if(b[j]=='0')
	   		y0++;
 	}
	gotoxy(41,15);
	for(j=1;j<=ya;j++)
	  	printf("man ");
	gotoxy(41,16);
	for(j=1;j<=yb;j++)
	  	printf("Retainer  ");
	gotoxy(31,17);
	for(j=1;j<=y0;j++)
	   	printf("   ");
	if(xa==0 && xb==0 && ya==3 && yb==3)
	{
	  	gotoxy(15,21);
	  	printf("congratulation.You have passed this game,press any key to continue!");
	  	getch();
	  	window(1,1,25,80);
		textbackground(BLACK);
		textcolor(LIGHTGRAY);
		clrscr();
	  	exit(0);
	}
}

void main()
{
	int i,x,y,key,ca,cb,j,aA,aB,bA,bB;
	char ch;
Start:
	helpf();
	gotoxy(15,16);
	printf("press any key to start game!(press Q or q to quit)");
	ch=getch();
	if(ch=='Q'||ch=='q')
	{
		window(1,1,25,80);
		textbackground(BLACK);
		textcolor(LIGHTGRAY);
		clrscr();
		exit(0);
	}
	helpf();

	for(i=0;i<3;i++)
		a[i]='A';
	for(i=3;i<6;i++)
		a[i]='B';
	for(i=0;i<6;i++)
		b[i]='0';
	printcase(a,b);
	while(1)
	{
		gotoxy(20,18);
		printf("Please input the number of man to that bank.... ");
		scanf("%d",&x);
		gotoxy(20,18);
		printf("Please input the number of Restainer to that bank.... ");
		scanf("%d",&y);
		for(ca=0,cb=0,i=0;i<6;i++)
		{
			if(a[i]=='A')
	    			ca++;
			else if(a[i]=='B')
	    			cb++;
		}
		if(x<0 || x>ca || y<0 || y>cb || x+y<1 ||x+y>2)
		{
			gotoxy(15,21);
			printf("input error! press anykey to continue...");
			getch();
			goto Start;
		}
		for(i=1;i<=x;i++)
		{
	  		for(j=0;j<6;j++)
	   			if(a[j]=='A')
	   			{
	    				a[j]='0';
	    				break;
	   			}
		}
		for(i=1;i<=x;i++)
		{
	  		for(j=0;j<6;j++)
	   			if(b[j]=='0')
	   			{
	    				b[j]='A';
	       				break;
	   			}
		}
		for(i=1;i<=y;i++)
		{
	  		for(j=0;j<6;j++)
	   			if(a[j]=='B')
	   			{
	    				a[j]='0';
	    				break;
	   			}
		}
		for(i=1;i<=y;i++)
		{
	  		for(j=0;j<6;j++)

				if(b[j]=='0')
	   			{
	    				b[j]='B';
	    				break;
				}
		}
		for(aA=0,aB=0,i=0;i<6;i++) 
		{
	  		if(a[i]=='A')
	   			aA++;
	  		else if(a[i]=='B')
	   			aB++;
		}
		for(bA=0,bB=0,i=0;i<6;i++) 
		{
	  		if(b[i]=='A')
	   			bA++;
	  		else if(b[i]=='B')
	   			bB++;
		}   
	 
		if((aA==3) ||(bA==3) || (aA==aB) || (bA==bB))  
		{
	      		helpf();
	      		printcase(a,b);
	         }
		else
		{
			gotoxy(15,21);
			printf("The man has been killed,press any key to continue...");
			getch();
			goto Start;
		}
		gotoxy(20,18);
		printf("Please input the number of man to this bank....");
		scanf("%d",&x);
		gotoxy(20,18);
		printf("Please input the number of Restainer to this bank.... ");
		scanf("%d",&y);
		for(ca=0,cb=0,i=0;i<6;i++)
		{
	  		if(b[i]=='A')
	   			ca++;
	  		else if(b[i]=='B')
	   			cb++;
		}
		if(x<0 || x>ca || y<0 || y>cb || x+y<1 || x+y>2) 
		{
			gotoxy(15,21);
	   		printf("input error! press anykey to continue...");
	   		getch();
	  		goto Start;
		}
		for(i=1;i<=x;i++) 
		{
	  		for(j=0;j<6;j++)
	   			if(b[j]=='A') 
	   			{
	    				b[j]='0';
	    				break;
	   			}
		}
		for(i=1;i<=x;i++) 
		{
	  		for(j=0;j<6;j++)
	   			if(a[j]=='0') 
	   			{
	    				a[j]='A';
	    				break;
				}
		}
		for(i=1;i<=y;i++) 
		{
	  		for(j=0;j<6;j++)
	   		if(b[j]=='B') 
	   		{
	    			b[j]='0';
	    			break;
	   		}
		}
		for(i=1;i<=y;i++) 
		{
	  		for(j=0;j<6;j++)
	   		if(a[j]=='0') 
	   		{
	    			a[j]='B';
				break;
	   		}
		}
		for(aA=0,aB=0,i=0;i<6;i++) 
		{
	  		if(a[i]=='A')
	   			aA++;
	  		else if(a[i]=='B')
	   			aB++;
		}
		for(bA=0,bB=0,i=0;i<6;i++) 
		{
	  		if(b[i]=='A')
	   			bA++;
	  		else if(b[i]=='B')
	   			bB++;
		}
	 	if((aA==3) ||(bA==3) || (aA==aB) || (bA==bB))
	 	{
	  		helpf();
	  		printcase(a,b);
		}
		else 
		{
 	  		gotoxy(15,21);
	   		printf("The man has been killed,press any key to continue...");
	        	getch();
	        	goto Start;
	  	}
	}
}