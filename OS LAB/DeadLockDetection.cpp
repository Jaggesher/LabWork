/*
    Name:
    ID:
    TITLE: Banker's Algorithm

*/

#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define MAX 1000
using namespace std;
int No_Of_Process;
int No_Of_Resources;
int Available[MAX];
int Instances[MAX];
int Allocated[MAX][MAX];
int Need[MAX][MAX];
int Claim[MAX][MAX];
bitset<MAX>Done;

void Cal_Available(){
    for(int j=0;j<No_Of_Resources;j++){
         for(int i=0;i<No_Of_Process;i++)
            Available[j]+=Allocated[i][j];

         Available[j]=Instances[j]-Available[j];
    }
    return;
}

bool Is_It_Possible(int n){
    for(int i=0;i<No_Of_Resources;i++)
        if(Need[n][i]>Available[i]) return false;
    return true;
}

bool Cal_Is_Safe(){
    Done.set();
    for(int n=0;n<No_Of_Process;n++){
            bool flag=false;
        for(int i=0;i<No_Of_Process;i++){
            if(Done[i] && Is_It_Possible(i)){
                for(int j=0;j<No_Of_Resources;j++) Available[j]+=Allocated[i][j];
                Done[i]=false;
                flag=true;
                break;
            }
        }
        if(!flag) return false;
    }
    return true;
}

void Input(){
    pf("Enter The Number of Resources: ");
    sf("%d",&No_Of_Resources);
    pf("\nEnter The Number Of Instances...\n");
    for(int i=0;i<No_Of_Resources;i++){
        pf( "For Resource Type%2d: ",(i+1));
        sf("%d",&Instances[i]);
    }

    pf("\nEnter The Number Of Process: ");
    sf("%d",&No_Of_Process);

    pf("\nEnter The Resource Allocated Matrix\n");
    for(int i=0;i<No_Of_Process;i++){
            pf("For Process %2d: ",(i+1));
        for(int j=0;j<No_Of_Resources;j++){
            sf("%d",&Allocated[i][j]);
        }
    }

    pf("\nEnter The Resource Claim Matrix\n");
    for(int i=0;i<No_Of_Process;i++){
            pf("For Process %3d: ",(i+1));
        for(int j=0;j<No_Of_Resources;j++){
            sf("%d",&Claim[i][j]);
            Need[i][j]=Claim[i][j]-Allocated[i][j];
        }
    }

    return;
}

void Output(){

    pf("\nThe Resource Need Matrix\n");
    for(int i=0;i<No_Of_Process;i++){
        pf("For Process %3d: ",(i+1));
        for(int j=0;j<No_Of_Resources;j++)
            pf("%d ",Need[i][j]);
        pf("\n");
    }

    Cal_Available();
    pf("\nCurrently Available Instance Vector Is:\n");
    for(int i=0;i<No_Of_Resources;i++) pf(" %d",Available[i]);

    if(Cal_Is_Safe()){
        pf("\n\nThere is a Safe Sequence No Deadlock: ");
    }
    else{
        pf("\n\nThere Is No Safe Sequence(Deadlock)\n\n");
    }
    return;
}

int main(){
    Input();
    Output();
    return 0;
}
