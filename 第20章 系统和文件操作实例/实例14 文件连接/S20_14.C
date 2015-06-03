#include <stdio.h>
int main(int argc, char* argv[])
{FILE *fp1,*fp2;
 int ch;
 if(argc!=3)
   {printf("参数个数不对！");
    exit(0);
   }
 if((fp1=fopen(argv[1], "r"))==NULL)
   {printf("打开文件：%s失败\n", argv[1]);
    exit(1);
   }
 if((fp2=fopen(argv[2], "a"))==NULL)
   {printf("打开文件：%s失败\n", argv[2]);
    exit(1);
   }
 /*fseek(fp2,0L,SEEK_END);*/
 while((ch=fgetc(fp1)) != EOF)
   fputc(ch,fp2);
 fclose(fp1);
 fclose(fp2);
 return 0;
}

