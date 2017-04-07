// Program using graphics
#include<iostream>
// for cout
#include<stdlib.h>
//for itoa()
#include<dos.h>
// for gettime();
#include<conio.h>
//for clrscr();
#include<graphics.h>
int main()
{
struct time t;
char hr[5],min[5],sec[5];
int gd=DETECT,gm;
//initialing graph
initgraph(&gd,&gm,"c:\tc\bgi");
while(1)
{
gettime(&t);
// clrscr();
if(kbhit())
break;
itoa(t.ti_hour,hr,10);
itoa(t.ti_min,min,10);
itoa(t.ti_sec,sec,10);
setcolor(CYAN);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,11);
outtextxy(60,150,hr);
setcolor(RED);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,11);
outtextxy(215,135,":");
setcolor(LIGHTGREEN);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,11);
outtextxy(230,150,min);
setcolor(WHITE);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,11);
outtextxy(390,135,":");
setcolor(LIGHTBLUE);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,11);
outtextxy(405,150,sec);
sleep(1);
cleardevice();
}
closegraph();
}
