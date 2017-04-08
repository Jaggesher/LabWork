/*
    Name:
    ID:
    TITLE: Best Fit Algorithm.

*/

#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define PB push_back
using namespace std;

class Block{
    public:
        int ID;
        int Size;
        bool isFree;
};

int FreeMemory,MemBlock,ProcessNo;
vector<Block>BlockInfo;
vector<int>Process;
bool compare(const Block &ob1,const Block &ob2){
    if(ob1.Size<ob2.Size) return true;
    return false;
}
void Input(){
    Block ob;
    int tm;
    pf("Enter The Number Of Memory Block:");
    sf("%d",&MemBlock);
    for(int i=1;i<=MemBlock;i++){
            pf("Enter The Size Of BLOCK%d: ",i);
        sf("%d",&tm);
        ob.ID=i;
        ob.Size=tm;
        ob.isFree=true;
        FreeMemory+=tm;
        BlockInfo.PB(ob);
    }
    pf("\nEnter The Number Of Process:");
    sf("%d",&ProcessNo);

    for(int i=1;i<=ProcessNo;i++){
        pf("Enter The Size Of PROCESS%d: ",i);
        sf("%d",&tm);
        Process.PB(tm);
    }
}

void Output(){
    pf("\n\n FileNO  |  FileSize  |  BlockNo   |   BlockSize  |  InternalFragmentation\n");
    pf(" -------------------------------------------------------------------------\n");
    for(int i=0;i<ProcessNo;i++){
        bool flag=true;
        for(int j=0;j<MemBlock;j++)
            if(BlockInfo[j].Size>=Process[i] && BlockInfo[j].isFree){
                int temp=BlockInfo[j].Size-Process[i];
                printf("  %3d    |    %3d     |    %3d     |     %3d      |         %3d        \n",(i+1),Process[i],BlockInfo[j].ID,BlockInfo[j].Size,temp);
                flag=false;
                BlockInfo[j].isFree=false;
                break;
            }
        if(flag) pf("  %3d    |    %3d     |     XXX    |     XXX      |         XXX        \n",(i+1),Process[i]);
    }
    pf(" -------------------------------------------------------------------------");
    return;
}

int main(){
    Input();
    sort(BlockInfo.begin(),BlockInfo.end(),compare);
    Output();
    return 0;
}
/*
SAMPLE INPUT:
3
300
200
400
3
100
150
250


*/

