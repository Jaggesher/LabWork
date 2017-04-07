/*
    LabWork: 01
    Title: The Flag of Bangladesh.
    Name: Jaggesher Mondal
    Roll: 14025423
*/
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main(){
    int gd=DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3);
    outtextxy(200, 50, "The Flag of Bangladesh.");

    rectangle(100,100,600,400);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(101,101,WHITE);

    circle(325,250,100);
    setfillstyle(SOLID_FILL,RED);
    floodfill(325,250,WHITE);

    getch();
    closegraph();
    return 0;
}
