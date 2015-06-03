#include <stdio.h>
#include <stdlib.h>
int main()
{
 int  a;
 FILE *fp;
 if((fp = fopen("text.dat","w+")) == NULL)
   exit(1);
 putw(12337,fp);              /* 存为00110001  00110000  (先低后高)*/
 rewind(fp);
 fscanf(fp, "%d",&a);
 printf("%d\n",a);             /* 输出结果：10 */
 return 0;
}