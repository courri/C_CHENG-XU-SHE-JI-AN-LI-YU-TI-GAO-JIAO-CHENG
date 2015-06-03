#include <stdio.h>
typedef  struct {
   char name[10];
   int score[3];
   int sum;
}STU;


void  input()
{FILE *fp;
 int i;
 STU s;
 if((fp=fopen("student.dat", "w"))==NULL)
   {printf("打开文件失败\n");
    exit(0);
   }
 for(i=0; i<=9;i++)
   {scanf("%s%d%d%d", s.name, &s.score[0], &s.score[1], &s.score[2]);
    fwrite(&s, sizeof(STU), 1, fp);
   }
 fclose(fp);
}
void  calculate()
{FILE *fp;
 int i;
 STU s;
 if((fp=fopen("student.dat", "r+"))==NULL)
   {printf("打开文件失败\n");
    exit(0);
   }
 for(i=0; i<=9;i++)
   {fseek(fp,sizeof(STU)*i,0);
    fread (&s, sizeof(STU), 1, fp);
    s.sum=s.score[0]+ s.score[1]+ s.score[2];
    fseek(fp, -2, 1);
    fwrite(&s.sum, 2,1, fp);
   }
 fclose(fp);
}

int  main()
{input();
 calculate();
 return 0;
}