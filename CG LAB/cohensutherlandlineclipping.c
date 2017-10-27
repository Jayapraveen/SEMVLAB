#include<stdio.h>
#include<conio.h>
#include<graphics.h>

#define LEFT 0x1
#define RIGHT 0x2
#define BOTTOM 0x4
#define TOP 0x8
float wxmin,wymin,wxmax,wymax;

struct line
{
float x1,y1,x2,y2,done,draw;
unsigned char code1,code2;
float m;
}s[20];

unsigned char encode(float x,float y)
{
unsigned char code=0x00;
if(x<wxmin)
	code=code | LEFT;
else if(x>wxmax)
	code=code | RIGHT;
if(y<wymin)
	code=code | TOP;
else if(y>wymax)
	code=code | BOTTOM;
return (code);
 }

void process(struct line *temp)
{
float t;
unsigned char ct;
if(temp->x1 != temp->x2)
	temp->m=(float)(temp->y2-temp->y1)/(temp->x2-temp->x1);
temp->code1=encode(temp->x1,temp->y1);
temp->code2=encode(temp->x2,temp->y2);
if(!(temp->code1 | temp->code2))
{
  temp->done=1;
}
else if(temp->code1 & temp->code2)
{
  temp->done=1;
  temp->draw=0;
}
else
{
  if(!temp->code1)
  {
    t=temp->x1;
    temp->x1=temp->x2;
    temp->x2=t;
    t=temp->y1;
    temp->y1=temp->y2;
    temp->y2=t;
    ct=temp->code1;
    temp->code1=temp->code2;
    temp->code2=ct;
  }
  if(temp->code1 & LEFT)
  {
    temp->y1+=(wxmin-temp->x1)*temp->m;
    temp->x1=wxmin;
  }
  else if(temp->code1 & RIGHT)
  {
    temp->y1+=(wxmax-temp->x1)*temp->m;
    temp->x1=wxmax;
  }
  else if(temp->code1 & TOP)
  {
    if(temp->x1 != temp->x2)
    temp->x1+=(wymin-temp->y1)/temp->m;
    temp->y1=wymin;
  }
  else if(temp->code1 & BOTTOM)
  {
    if(temp->x1 != temp->x2)
    temp->x1+=(wymax-temp->y1)/temp->m;
    temp->y1=wymax;
  }
}
}

void main()
{
int i,j,gd=DETECT,gm,n;
printf("Enter the window details(xmin,xmax,ymin,ymax): ");
scanf("%f%f%f%f",&wxmin,&wxmax,&wymin,&wymax);
printf("Enter the number of lines: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
  printf("Enter the end points(x1,y1,x2,y2) of line%d: ",i+1);
  scanf("%f%f%f%f",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
  s[i].code1=0x00;
  s[i].code2=0x00;
  s[i].draw=1;
  process(&s[i]);
}
initgraph(&gd,&gm,"Z:\\TC\\BGI");
line(wxmin,wymin,wxmin,wymax);
line(wxmin,wymin,wxmax,wymin);
line(wxmin,wymax,wxmax,wymax);
line(wxmax,wymin,wxmax,wymax);
for(i=0;i<n;i++)
{
  printf("The slope is %f....x1 = %f, y1 = %f, x2 = %f, y2 = %f", s[i].m, s[i].x1, s[i].y1, s[i].x2, s[i].y2);
  printf("\nThe clipped line is ");
  if(s[i].draw)
	line((int)s[i].x1,(int)s[i].y1,(int)s[i].x2,(int)s[i].y2);
}
getch();
}
