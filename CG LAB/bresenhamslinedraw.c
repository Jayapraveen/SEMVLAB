#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "graphics.h"

main()
{
		int gd=DETECT,gm;
		int xa,xb,ya,yb;
		int dx,dy,x,y,xend,p;
		initgraph(&gd,&gm,"c:\\tc\\bgi");
		printf("Enter The Two Left Endpoints(xa,ya):\n");
		scanf("%d%d",&xa,&ya);
		printf("Enter The Two Right Endpoints(xb,yb):\n");
		scanf("%d%d",&xb,&yb);
		dx=abs(xa-xb);
		dy=abs(ya-yb);
		p=2*dy-dx;
		if(xa>xb)
		{
			x=xb;
			y=yb;
			xend=xa;
		}
	else
{
			x=xa;
			y=ya;
			xend=xb;
}
      putpixel(x,y,6);
    while(x<xend)
      {
      x=x+1;
      if(p<0)
      {
      p=p+2*dy;
      }
      else
      {
      y=y+1;
      p=p+2*(dy-dx);
      }
      putpixel(x,y,6);
      }
   getch();
   return(0);
}
