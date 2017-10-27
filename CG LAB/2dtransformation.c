#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

void display(int n, float c[][3])
{
 float maxx,maxy;
 int i;
 maxx=getmaxx();
 maxy=getmaxy();
 maxx=maxx/2;
 maxy=maxy/2;
 i=0;
 while(i<n-1)
 {
  line(maxx+c[i][0],maxy-c[i][1],maxx+c[i+1][0],maxy-c[i+1][1]);
  i++;
 }
 i=n-1;
 line(maxx+c[i][0],maxy-c[i][1],maxx+c[0][0],maxy-c[0][1]);
 setcolor(GREEN);
 line(0,maxy,maxx*2,maxy);
 line(maxx,0,maxx,maxy*2);
 setcolor(WHITE);
}

void mul(int n,float b[][3],float c[][3],float a[][3])
{
 int i,j,k;
 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
   a[i][j]=0;
 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 for(k=0;k<n;k++)
   {
    a[i][j]=a[i][j]+(c[i][k]*b[k][j]);
   }
}

void translation(int n,float c[][3],float tx,float ty)
{
 int i;
 for(i=0;i<n;i++)
 {
  c[i][0]=c[i][0]+tx;
  c[i][1]=c[i][1]+ty;
 }
}

void scaling(int n,float c[][3],float sx,float sy)
{
 float b[10][3],a[10][3];
 int i=0,j;
 for(i=0;i<3;i++)
 	for(j=0;j<3;j++)
   b[i][j]=0;
 b[0][0]=sx;
 b[1][1]=sy;
 b[2][2]=1;
 mul(n,b,c,a);
 setcolor(RED);
 display(n,a);
   }

void rotation(int n,float c[][3],float ra)
{
 int i=0,j;
 float b[10][3],xp,yp,a[10][3];
 xp=c[0][0];
 yp=c[0][1];
 for(i=0;i<3;i++)
 for(j=0;j<3;j++)
   b[i][j]=0;
 b[0][0]=b[1][1]=cos(ra*3.14/180);
 b[0][1]=sin(ra*3.14/180);
 b[1][0]=-sin(ra*3.14/180);
 b[2][0]=(-xp*cos(ra*3.14/180))+(yp*sin(ra*3.14/180))+xp;
 b[2][1]=(-xp*sin(ra*3.14/180))-(yp*cos(ra*3.14/180))+yp;
 b[2][2]=1;
 mul(n,b,c,a);
 setcolor(RED);
 display(n,a);
 getch();
}

void reflection(int n,float c[][3])
{
float b[10][3],a[10][3];
int i=0,ch,j;
cleardevice();
printf("\nabout X-axis");
display(n,c);
for(i=0;i<3;i++)
for(j=0;j<3;j++)
{
b[i][j]=0;
if(i==j)
b[i][j]=1;
}
b[1][1]=-1;
mul(n,b,c,a);
setcolor(RED);
display(n,a);
getch();
}

void shearing(int n,float c[][3])
{
float b[10][3],sh,a[10][3];
int i=0,ch,j;
cleardevice();
printf("\nX-shearing");
printf("\nEnter the val for shear : ");
scanf("%f",&sh);
clrscr();
cleardevice();
for(i=0;i<3;i++)
for(j=0;j<3;j++)
b[i][j]=0;
for(i=0;i<3;i++)
b[i][i]=1;
b[1][0]=sh;
mul(n,b,c,a);
setcolor(RED);
display(n,a);
}

void main()
{
int i,j,k,cho,n;
int gd=DETECT,gm;
float c[10][3],tx,ty,sx,sy,ra;
initgraph(&gd,&gm,"Z:\\tc\\bgi");
printf("\nEnter no. of vertices : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
 printf("\nEnter coordinates of %d vertex : ",i+1);
 scanf("%f%f",&c[i][0],&c[i][1]);
 c[i][2]=1;
}
do
{
 clrscr();
 cleardevice();
 printf("\n1.Translation\n2.Scaling\n3.Rotation\n4.Reflection\n5.Shearing\n6.Exit");
 printf("\nEnter UR choice : ");
 scanf("%d",&cho);
 switch(cho)
 {
 case 1:
  printf("\nTranslation factor for x and y-axis : ");
  scanf("%f%f",&tx,&ty);
  clrscr();
  cleardevice();
  setcolor(BLUE);
  display(n,c);
  getch();
  translation(n,c,tx,ty);
  setcolor(RED);
  display(n,c);
  getch();
  break;

case 2:
  printf("\nScaling factor for x and y-axis : ");
  scanf("%f%f",&sx,&sy);
  clrscr();
  cleardevice();
  setcolor(BLUE);
  display(n,c);
  getch();
  scaling(n,c,sx,sy);
  getch();
  break;

  case 3:
  printf("\nEnter angular rotation : ");
  scanf("%f",&ra);
  clrscr();
  cleardevice();
  setcolor(BLUE);
  display(n,c);
  getch();
  rotation(n,c,ra);
  setcolor(RED);
  break;

  case 4:
  clrscr();
  cleardevice();
  setcolor(BLUE);
  display(n,c);
  getch();
  reflection(n,c);
  getch();
  break;

  case 5:
  clrscr();
  cleardevice();
  setcolor(BLUE);
  display(n,c);
  getch();
  shearing(n,c);
  getch();
  break;

  case 6:
  exit(0);

  default :
  printf("Invalid choice!!!");
  break;
 }
} while(cho!=6);
getch();
closegraph();
}

 
