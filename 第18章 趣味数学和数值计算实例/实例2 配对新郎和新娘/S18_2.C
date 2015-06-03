#include<stdio.h>
void main()
{
    int x,y,z;
    puts(" >> The solutions are:");
    printf("---------------------------------------------\n");
    for(x=1;x<=3;x++)          /*穷举x的全部可能配偶*/
        for(y=1;y<=3;y++)      /*穷举y的全部可能配偶*/
            for(z=1;z<=3;z++)    /*穷举z的全部可能配偶*/
                if(x!=1&&x!=3&&z!=3&&x!=y&&x!=z&&y!=z)  /*判断配偶是否满足题意*/
                {
		    printf(" X will marry to %c.\n",'A'+x-1);    /*打印判断结果*/
		    printf(" Y will marry to %c.\n",'A'+y-1);
		    printf(" Z will marry to %c.\n",'A'+z-1);
                }
    printf("---------------------------------------------\n");
    printf(" Press any key to quit...");
    getch();
}
