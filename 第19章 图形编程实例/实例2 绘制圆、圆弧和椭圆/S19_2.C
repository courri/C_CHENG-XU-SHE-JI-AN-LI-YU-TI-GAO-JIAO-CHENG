#include <graphics.h>
int main()
{
    int gdriver=DETECT,gmode,i,j;
    initgraph(&gdriver,&gmode,"D:\\tc");
    printf("Draw circle with function 'circle'.\n");
    for(i=10;i<=140;i+=10)
       circle(320,240,i);
    getch();
    cleardevice();
    printf("Draw arc with fuction 'arc'.\n");
    for(i=10;i<=140;i+=10)
       arc(320,240,0,150,i);
    getch();
    cleardevice();
    printf("Draw ellipse with function 'ellipse'.");
    j=150;
    for(i=10;i<=140;i+=10,j+=10)
      ellipse(320,240,0,360,j,i);
    getch();
    cleardevice();
    closegraph();

    return 0;
}