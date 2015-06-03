#include <dos.h>
#include <stdio.h>
int delete_file(char near *filename)
{
 union REGS regs; 
 int ret; 
 regs.h.ah = 0x41;                /*功能号41H，删除文件*/
 regs.x.dx = (unsigned) filename; /*dx置偏移地址*/
 ret = intdos(&regs, &regs); 
 return(regs.x.cflag ? ret : 0); 
}

int main()
{char filename[50];
 gets(filename);
 if(delete_file(filename)==0)
   printf("删除成功！\n");
 else
   printf("删除失败！\n");
 return 0;
}