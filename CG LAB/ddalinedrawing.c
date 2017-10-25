#include "stdio.h"
	#include "conio.h"
	#include "math.h"
	#include "graphics.h"
	main()
	{
		int gd=DETECT,gm;
		int xa,xb,ya,yb;
		int dx,dy,steps,k,xinc,yinc,x,y;
		initgraph(&gd,&gm,"c:\\tc\\bgi");
		printf("Enter the two left end pixel points(xa,ya):\n");
		scanf("%d%d",&xa,&ya);
		printf("Enter the two Right end pixel points(xb,yb):\n");
		scanf("%d%d",&xb,&yb);
		dx=xb-xa;
		dy=yb-ya;
		if(abs(dx)>abs(dy))
			steps=abs(dx);
		else
			steps=abs(dy);
		xinc=dx/steps;
		yinc=dy/steps;
		x=xa;
		y=ya;
		putpixel(x,y,6);
		for(k=1;k<=steps;k++)
		{
			x=x+xinc;
			y=y+yinc;21
			putpixel(x,y,6);
		}
		getch();
		return(0);
	    }
