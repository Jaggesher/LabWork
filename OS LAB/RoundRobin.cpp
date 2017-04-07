/*
    Name:
    ID:
    TITLE: Round Robin

*/

#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
using namespace std;

int Number_Of_Process;
double Sum_Of_Waiting_Time;
double Sum_Of_Turnaround_Time;
int Time_Quantum;

class Process{
public:
    int Process_ID;
    int Burst_Time=0;
    int Burst_Time_Cpy=0;
    int Waiting_Time=0;
    int Turnaround_Time=0;
};

vector<Process>All_Process;

void Input(){
    Process ob;
    All_Process.pb(ob);
    int Tm;

    pf("Please Enter The Number Of Process=");
    sf("%d",&Number_Of_Process);
    for(int i=1;i<=Number_Of_Process;i++){
        pf("Burst Time For Process %d=",i);
        sf("%d",&Tm);

        ob.Process_ID=i;
        ob.Burst_Time=Tm;
        ob.Burst_Time_Cpy=Tm;
        All_Process.pb(ob);
    }
    pf("Enter The Time Quantum: ");
    sf("%d",&Time_Quantum);
    return;
}

void Calculate(){
    bool flag=true;
    int CurrentTime=0;
    while(flag){
        flag=false;
        for(int i=1;i<=Number_Of_Process;i++){
            if(All_Process[i].Burst_Time_Cpy==0) continue;
            if(All_Process[i].Burst_Time_Cpy>=Time_Quantum){
                All_Process[i].Burst_Time_Cpy-=Time_Quantum;
                int Tm=CurrentTime-All_Process[i].Turnaround_Time;
                CurrentTime+=Time_Quantum;
                All_Process[i].Turnaround_Time=CurrentTime;
                All_Process[i].Waiting_Time+=Tm;

                flag=true;
            }
            else{

                int Tm=CurrentTime-All_Process[i].Turnaround_Time;
                CurrentTime+=All_Process[i].Burst_Time_Cpy;
                All_Process[i].Turnaround_Time=CurrentTime;
                All_Process[i].Waiting_Time+=Tm;
                All_Process[i].Burst_Time_Cpy=0;
                flag=true;
            }
        }
    }

    for(int i=1;i<=Number_Of_Process;i++)
    {
        Sum_Of_Waiting_Time+=All_Process[i].Waiting_Time;
        Sum_Of_Turnaround_Time+=All_Process[i].Turnaround_Time;
    }

    return;
}

void Output(){
    pf("\n\nHere We Assume All Process Arrive At Time= 0\n");
    pf("............................................................\n");
    pf("| Process ID | Burst Time | Waiting Time | Turnaround Time |\n");
    pf("|..........................................................|\n");
    for(int i=1;i<=Number_Of_Process;i++){
        pf("|    %3d     |     %3d    |      %3d     |      %3d        |\n",
           All_Process[i].Process_ID,All_Process[i].Burst_Time,All_Process[i].Waiting_Time,
           All_Process[i].Turnaround_Time);
    }
    pf("------------------------------------------------------------\n");
    pf("\nAverage Waiting Time: %lf\n",(Sum_Of_Waiting_Time/Number_Of_Process));
    pf("Average Turnaround Time: %lf\n",(Sum_Of_Turnaround_Time/Number_Of_Process));
    return;
}

int main(){
    Input();
    Calculate();
    Output();
    return 0;
}
