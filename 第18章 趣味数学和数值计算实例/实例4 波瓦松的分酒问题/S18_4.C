#include<stdio.h>
void getti(int a,int y,int z);
int i;
void main()
{
    int a,y,z;
    printf(" >> Input Full bottle a,Empty b,c, and Get volumes:\n");
    printf(" >> ");
    scanf("%d%d%d%d",&a,&y,&z,&i);
    getti(a,y,z);
    printf("\n Press any key to quit...");
    getchar();
}
void getti(int a,int y,int z)
{
   int b=0,c=0,j=0;
   puts(" >> The division steps are as follows.\n");

   printf(" Bottle:    a<%d> b<%d> c<%d>\n",a,y,z);
   printf("-----------------------------\n");
   printf(" Step No.|\n");
   printf("   <%d>   | %4d %4d %4d\n",j++,a,b,c);

   while(a!=i&&b!=i&&c!=i)
   {
      if(!b)
      {  a-=y; b=y;}
      else if(c==z)
      {  a+=z; c=0;}     
      else if(b>z-c)     
      { b-=(z-c);c=z;}   
      else{ c+=b; b=0;}    
      printf("   <%d>   | %4d %4d %4d\n",j++,a,b,c);
   }
   printf("-----------------------------\n");
}
