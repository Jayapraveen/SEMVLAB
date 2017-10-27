//Consecutive Scaling
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void draw2d(int fs,int x[],int y[],int tx,int ty)
{
int i;
for(i=0;i<fs;i++)
{
if(i!=(fs-1))
line(x[i]*tx,y[i]*ty,x[i+1]*tx,y[i+1]*ty);
else
line(x[i]*tx,y[i]*ty,x[0]*tx,y[0]*ty);
}
}

void main()
{
int i,gd=DETECT,gm,x[20],y[20],tx=1,ty=1,ax[10],ay[10],fs,n;
initgraph(&gd,&gm,"Z:\\TC\\BGI");
printf("Enter the number of sides:");
scanf("%d",&fs);
printf("Enter the corner points:\n");
for(i=0;i<fs;i++)
{
 printf("x%d y%d: ",i,i);
 scanf("%d%d",&x[i],&y[i]);
}
printf("Enter the number of scaling transformation: ");
scanf("%d",&n);
draw2d(fs,x,y,tx,ty);
for(i=0;i<n;i++)
{
printf("Enter the scaling unit%d(tx and ty): ",i);
scanf("%d%d",&ax[i],&ay[i]);
}
for(i=0;i<n;i++)
{
tx*=ax[i];
ty*=ay[i];
}
draw2d(fs,x,y,tx,ty);
getch();
}
