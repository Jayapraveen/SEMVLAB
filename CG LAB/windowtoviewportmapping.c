#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
main()	
  {
		float sx,sy;
		int w1,w2,w3,w4,x1,x2,x3,x4,y1,y2,y3,y4,v1,v2,v3,v4;
		int gd=DETECT,gm;
		initgraph(&gd,&gm,"c:\\tc\\bgi");
		printf("Enter The Coordinate x1,y1,x2,y2,x3,y3\n");
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		cleardevice();
		w1=5;
		w2=5;
		w3=635;
		w4=465;
		rectangle(w1,w2,w3,w4);
		line(x1,y1,x2,y2);
		line(x2,y2,x3,y3);
		line(x3,y3,x1,y1);
		getch();
		v1=425;
		v2=75;
		v3=550;
		v4=250;
		sx=(float)(v3-v1)/(w3-w1);
		sy=(float)(v4-v2)/(w4-w2);
		rectangle(v1,v2,v3,v4);
		x1=v1+floor(((float)(x1-w1)*sx)+.5);
		x2=v1+floor(((float)(x2-w1)*sx)+.5);
		x3=v1+floor(((float)(x3-w1)*sx)+.5);
		y1=v2+floor(((float)(y1-w2)*sy)+.5);
		y2=v2+floor(((float)(y2-w2)*sy)+.5);
		y3=v2+floor(((float)(y3-w2)*sy)+.5);
		line(x1,y1,x2,y2);
		line(x2,y2,x3,y3);
		line(x3,y3,x1,y1);
		getch();
		return 0; }
