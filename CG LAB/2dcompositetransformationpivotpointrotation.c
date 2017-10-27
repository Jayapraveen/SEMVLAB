#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
void draw2d(float fs,float x[],float y[])
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
int i,gd=DETECT,gm;
float x[20],y[20],a[20],b[20],tx=1,ty,fs,ax,ay;
initgraph(&gd,&gm,"Z:\\TC\\BGI");
printf("Enter the number of sides:");
scanf("%f",&fs);
printf("Enter the corner points:\n");
for(i=0;i<fs;i++)
{
 printf("x%d y%d: ",i,i);
 scanf("%f%f",&x[i],&y[i]);
}
draw2d(fs,x,y);
printf("Enter the pivot point:(ax & ay) ");
scanf("%f%f",&ax,&ay);
for(i=0;i<fs;i++)
{
 x[i]+=ax;
 y[i]+=ay;
}
draw2d(fs,x,y);
printf("Enter the rotation angle(tx): ");
scanf("%f",&tx);
ty=tx*M_PI/180;
printf("The radian is %f",ty);
for(i=0;i<fs;i++)
{
a[i]=x[i]*cos(ty)-y[i]*sin(ty);
b[i]=x[i]*sin(ty)+y[i]*cos(ty);
}
draw2d(fs,a,b);
for(i=0;i<fs;i++)
{
 a[i]-=ax;
 b[i]-=ay;
}
draw2d(fs,a,b);
getch();
}
