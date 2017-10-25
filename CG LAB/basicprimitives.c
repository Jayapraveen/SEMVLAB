#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 setcolor(BLACK);
 circle(300,300,100);
 circle(250,280,10);
 circle(350,280,10);
 line(300,300,290,330);
 line(290,330,310,330);
 arc(300,300,240,300,70);
 getch();
}

    
