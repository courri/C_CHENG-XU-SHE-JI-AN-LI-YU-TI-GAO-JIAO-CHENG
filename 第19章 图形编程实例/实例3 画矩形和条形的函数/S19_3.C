#include <graphics.h>
int main()
{
    int gdriver=DETECT,gmode,i,j;
    initgraph(&gdriver,&gmode,"D:\\tc");
    printf("Draw rectangle with function 'rectangle'.\n");
      rectangle(120,120,480,320);
    getch();
    cleardevice();
    printf("Draw bar with fuction 'bar'.\n");
      bar(120,120,480,320);
    getch();
    cleardevice();
    closegraph();

    return 0;
}