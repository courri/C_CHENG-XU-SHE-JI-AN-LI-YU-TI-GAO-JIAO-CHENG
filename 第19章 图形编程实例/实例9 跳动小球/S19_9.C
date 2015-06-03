 #include <graphics.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <conio.h>
    #include <math.h>
    #define ESC 0x1b;
    #define MAXNUM 100

    main()
    {   char *buf;
	char sign,sign1[MAXNUM],sign2[MAXNUM];
        int i,size,a;
        int x[MAXNUM],y[MAXNUM],r[MAXNUM][MAXNUM];
        int gd = DETECT,gm;
        clrscr();
        printf("please input the number of ball you want:\n");
        scanf("%d",&a);
	initgraph(&gd,&gm,"");
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL,9);
        rectangle(0,0,getmaxx(),getmaxy());
        rectangle(1,1,getmaxx()-1,getmaxy()-1);
        bar(2,2,getmaxx()-2,getmaxy()-2);
        for(i = 8;i >=0;i --)
        {   setcolor(i + 7);
	    circle(11,getmaxy() - 11,i);
        }
        size = imagesize(2,getmaxy() - 20,20,getmaxy() - 2);
        buf = malloc(size);
        getimage(2,getmaxy()-20,20,getmaxy() - 2,buf);
        for(i = 8;i >= 0;i --)
        {   setcolor(9);
	    circle(11,getmaxy() - 11,i);
        }
        randomize();
        for(i = 0;i < a;i ++)
	{  x[i] = random(600) + 20;
	   y[i] = random(400) + 32;
	   sign1[i]=random(2);
	   sign2[i]=random(2);
        }

        while(1)
        {   if(kbhit())
        {   sign = getch();
            if(sign == 0x1b)
        {   free(buf);
            break;
        }
        }
     else
        {
            for(i = 0;i < a;i ++){
            putimage((sign1[i] == 1  ? x[i] ++ : x[i] --),
	       (sign2[i] == 1  ? y[i] ++ : y[i] --),buf,COPY_PUT);

	    if(x[i] > getmaxx() - 21)
	      sign1[i] = 0;
	    if(x[i] < 3)
	      sign1[i] = 1;
            if(y[i] > getmaxy() - 21)
	      sign2[i] = 0;
	    if(y[i] < 3)
	      sign2[i] = 1;}
        }
        }
        free(buf);
        closegraph();
        return 0;
    }