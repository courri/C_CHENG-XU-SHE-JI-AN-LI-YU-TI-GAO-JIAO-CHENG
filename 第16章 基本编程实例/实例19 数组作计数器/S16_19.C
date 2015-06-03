int main()
{char s[10][81];
 int i, j, count[26]={0};
 for(i = 0; i<=9; i++)
   gets(s[i]);
 for(i = 0; i<=9; i++)
   for(j = 0; s[i][j]!=0; j++)
     {
      if(s[i][j]>=65 && s[i][j]<=90)
	count[s[i][j]-65]++;
      if(s[i][j]>=97 && s[i][j]<=122)
	count[s[i][j]-97]++;
     }
 for(i = 0; i<=25; i++)
   printf("%4d", count[i]);
 printf("\n");
 return 0;
}

