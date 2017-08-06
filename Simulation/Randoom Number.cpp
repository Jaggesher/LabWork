#include<bits/stdc++.h>
#define pf printf
#define sf scanf
using namespace std;

char FileName[100]="RandomNumber.text";

void  LCM(int Mod,int N)
{
    FILE *fp;
    int a,c,x0,Temp;
    pf("Enter The Multiplier=");
    sf("%d",&a);
    pf("Enter The Increment=");
    sf("%d",&c);
    pf("Enter The Value Of X0=");
    sf("%d",&x0);
    fp=fopen(FileName,"w");
    for(int i=0;i<N;i++){
        Temp=((a*x0)+c)% Mod;
        fprintf(fp,"%d\n",Temp);
        x0=Temp;
    }
    fclose(fp);
    return;
}

void DefaultRandom(int Mod,int N)
{
    FILE *fp;
    srand((unsigned)time(0));
    fp=fopen(FileName,"w");
    for(int i=0;i<N;i++){
        fprintf(fp,"%d\n",(rand()%Mod));
    }
    fclose(fp);
    return;
}

void ChaiSqureTest(int Mod,int N)
{
    int cls,Range,Number,Expected;
    double GivenChai[2],Observed[100],ObserveChai=0;
    FILE *fp;

    pf("Enter The Number Of Classes=");
    sf("%d",&cls);
    Range=Mod/cls;
    for(int i=0;i<cls;i++) Observed[i]=0;

    fp=fopen(FileName,"r");
    for(int i=0;i<N;i++)
    {
        fscanf(fp,"%d",&Number);
        for(int j=0,Temp=0;j<cls;j++,Temp+=Range)
            if(Number>=Temp && Number<(Temp+Range))  Observed[j]++;
    }
    fclose(fp);

    pf("\n\nObserved HISTOGRAM\n");
    for(int i=0,Temp=0 ;i<cls; i++,Temp+=Range) pf("%d to %d = %.0lf\n",Temp,(Temp+Range),Observed[i]);
    Expected=N/cls;
    for(int i=0;i<cls;i++){
        double tmp=pow((Observed[i]-Expected),2.00);
            ObserveChai+=(tmp/Expected);
    }
    pf("\nObserved Chai-Squre Value=%.4lf\n",ObserveChai);

    pf("Enter Chai Table Value for DOF(%d)\nmin=",cls-1);
    sf("%lf",&GivenChai[0]);
    pf("max=");
    sf("%lf",&GivenChai[1]);
    if(GivenChai[0]<= ObserveChai && GivenChai[1]>= ObserveChai)
         pf("TEST PASSED");
    else pf("TEST FAIl");
    return;
}

void RunTEST(int Mod,int N)
{
    int RunUp=0,RunDown=0,Run=0,Number,Tmp;
    double Mean,Variance,Z0;
    bool flag,flagTm;
    FILE *fp;
    fp=fopen(FileName,"r");

    fscanf(fp,"%d",&Tmp);
    fscanf(fp,"%d",&Number);

    if(Tmp<=Number){
        RunUp++;
        flag=true;
    }else{
        RunDown++;
        flag=false;
    }

    Run++;

    for(int i=2;i<N;i++){
        Tmp=Number;
        fscanf(fp,"%d",&Number);
        if(Tmp<=Number){
        RunUp++;
            flagTm=true;
        }else{
            RunDown++;
            flagTm=false;
        }
        if(flag!=flagTm) Run++;
        flag=flagTm;
    }

    Mean=(double)((2*N)-1)/(double)3;
    Variance=(double)((16*N)-29)/(double)90;
    Z0=((double)Run-Mean)/sqrt(Variance);

    pf("\n\nTotal Runs Up=%d\n",RunUp);
    pf("Total Runs Down=%d\n",RunDown);
    pf("Total Runs=%d\n",Run);
    pf("Means=%.4lf\n",Mean);
    pf("Variance=%.4lf\n",Variance);
    pf("Z0=%.4lf\n\n",Z0);
    return;
}

void PokerTEST(int Mod,int N)
{
    pf("\n\nUNCOMPLETE 404 ERR\n\n");
    return;
}

int main()
{
    int Number,Mod;
    pf("Enter How Many Number=");
    sf("%d",&Number);
    pf("Enter The Modulus Value=");
    sf("%d",&Mod);
    pf("Choose The Method For Random Number Generate.\n");
    pf("a.press 1 for LCM\n");
    pf("b.press 2 for Built In Rand Function");
    char ch=getch();
    if(ch=='1')LCM(Mod,Number);
    else if(ch=='2')DefaultRandom(Mod,Number);
    else pf("INVALID");

    ChaiSqureTest(Mod,Number);
    RunTEST(Mod,Number);
    PokerTEST(Mod,Number);
    return 0;
}
