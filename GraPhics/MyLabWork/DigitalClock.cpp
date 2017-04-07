/*
    LabWork: 02
    Title: Digital Clock.
    Name: Jaggesher Mondal
    Roll: 14025423
*/
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main(){
    int gd=DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    time_t rawTime;
    struct tm * currentTime;
    char TxtTIme[100],hr[3],mnt[3],sec[3],St[3];

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 5);
    outtextxy(100, 90, "Current Time...");

    while(true){
        rawTime=time(NULL);
        currentTime=localtime(&rawTime);
        strftime(TxtTIme,100,"%I.%M.%S",currentTime);//Current Time to text
        strftime(St,3,"%p",currentTime);//AM/PM

        hr[0]=TxtTIme[0];
        hr[1]=TxtTIme[1];
        hr[2]='\0';

        mnt[0]=TxtTIme[3];
        mnt[1]=TxtTIme[4];
        mnt[2]='\0';

        sec[0]=TxtTIme[6];
        sec[1]=TxtTIme[7];
        sec[2]='\0';

        setcolor(CYAN);
        settextstyle(8,HORIZ_DIR,8);
        outtextxy(60,150,hr);

        setcolor(RED);
        settextstyle(8,HORIZ_DIR,8);
        outtextxy(155,145,":");

        setcolor(LIGHTGREEN);
        settextstyle(8,HORIZ_DIR,8);
        outtextxy(200,150,mnt);

        setcolor(WHITE);
        settextstyle(8,HORIZ_DIR,8);
        outtextxy(295,145,":");

        setcolor(LIGHTBLUE);
        settextstyle(8,HORIZ_DIR,8);
        outtextxy(340,150,sec);

        setcolor(WHITE);
        settextstyle(8,HORIZ_DIR,8);
        outtextxy(440,150,St);

        delay(1000);
    }
    getch();
    closegraph();
    return 0;
}
