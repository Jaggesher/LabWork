/*
    Name:
    ID:
    TITLE: LRU Page Replacement Algorithm.

*/

#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define PB push_back
#define MAX 1000
using namespace std;
int No_Of_Pages,No_Of_Frame;
int Pages[MAX],Frame[MAX],FrameInfo[MAX];

int VictimFrame(){
    int tm=FrameInfo[0];
    int indx=0;
    for(int i=1;i<No_Of_Frame;i++)
    if(tm>FrameInfo[i]){
        indx=i;
        tm=FrameInfo[i];
    }
    return indx;
}

int IsPageAlreadyIn(int tm){
    for(int i=0;i<No_Of_Frame;i++) if(Frame[i]==tm) return i;
    return -1;
}

void Input(){

    pf("Enter The Number Of Pages: ");
    sf("%d",&No_Of_Pages);
    pf("Enter Page Ref String: ");
    for(int i=0;i<No_Of_Pages;i++)sf("%d",&Pages[i]);
    pf("Enter The Number Of Frame: ");
    sf("%d",&No_Of_Frame);
}

void Output(){
    int Fault=0;
    pf("\nAt The Beginning The Status Of Frames: ");
    for(int i=0;i<No_Of_Frame;i++) {
            pf("-1 ");
            Frame[i]=FrameInfo[i]=-1;
    }

    pf("\n\nStatus Of FRAME In Main Memory: \n");
    for(int i=0;i<No_Of_Pages;i++){
        pf(" %2d :",i+1);

        int flag=IsPageAlreadyIn(Pages[i]);

        if(flag!=-1){
             FrameInfo[flag]=(i+1);
             for(int i=0;i<No_Of_Frame;i++) pf("%2d ",Frame[i]);
             pf("\n");
        }else{
            int tm=VictimFrame();
            Frame[tm]=Pages[i];
            FrameInfo[tm]=(i+1);
            Fault++;
            for(int i=0;i<No_Of_Frame;i++) pf("%2d ",Frame[i]);
            pf("->Fault\n");
        }
    }

    pf("\n\nTotal Number Of Page Fault: %d\n\n",Fault);
    return;
}

int main(){
    Input();
    Output();
    return 0;
}
/*
SAMPLE INPUT:
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
3
*/

