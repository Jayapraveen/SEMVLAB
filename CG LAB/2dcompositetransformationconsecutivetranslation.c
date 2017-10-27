//Consecutive Translation
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void draw2d(int x[],int y[],int fs)
{
int i;
for(i=0;i<fs;i++)
{
if(i!=(fs-1))
line(x[i],y[i],x[i+1],y[i+1]);
else
 line(x[i],y[i],x[0],y[0]);
}
}
void main()
{
 int gd=DETECT,gm,fs,x[10],y[10],tx,ty,ax,ay,i;
 initgraph(&gd,&gm,"Z:\\TC\\BGI");
 printf("Enter the number of sides: ");
 scanf("%d",&fs);
 printf("Enter the points\n");
 for(i=0;i<fs;i++)
{
  printf("x[%d] y[%d]:",i,i);
  scanf("%d%d",&x[i],&y[i]);
 }
draw2d(x,y,fs);
printf("Enter the 1st translation:(tx & ty)  ");
scanf("%d%d",&tx,&ty);
for(i=0;i<fs;i++)
{
  x[i]+=tx;
  y[i]+=ty;
}
draw2d(x,y,fs);
printf("Enter the second translation:(ax & ay)  ");
scanf("%d%d",&ax,&ay);
for(i=0;i<fs;i++)
{
  x[i]+=ax;
  y[i]+=ay;
 }
draw2d(x,y,fs);
getch();
}
