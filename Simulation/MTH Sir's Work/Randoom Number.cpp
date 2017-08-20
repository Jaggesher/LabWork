#include<bits/stdc++.h>
#define pf printf
#define sf scanf
using namespace std;

char FileName[100]="RandomNumber.text";

void  LCM(int Mod,int N)
{
     pf("\n\n--------LCM-----\n\n");
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
    pf("Number Generated\n");
    return;
}

void DefaultRandom(int Mod,int N)
{
    pf("\n\n--------Default RAND-----\n\n");
    FILE *fp;
    srand((unsigned)time(0));
    fp=fopen(FileName,"w");
    for(int i=0;i<N;i++){
        fprintf(fp,"%d\n",(rand()%Mod));
    }
    fclose(fp);
    pf("Number Generated\n");
    return;
}

void ChaiSqureTest(int Mod,int N)
{
    pf("\n\n--------Chai Squre Test-----\n\n");
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

void RunUpDownTEST(int Mod,int N)
{
    pf("\n\n--------Run Up Down TEST-----\n\n");
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

    pf("Total Runs Up=%d\n",RunUp);
    pf("Total Runs Down=%d\n",RunDown);
    pf("Total Runs=%d\n",Run);
    pf("Means=%.4lf\n",Mean);
    pf("Variance=%.4lf\n",Variance);
    pf("Z0=%.4lf\n\n",Z0);
    return;
}

void RunTEST(int Mod,int N){
    pf("\n\n--------Run Above/Below TEST-----\n");

    pf("\n\n--- INCOMPLETE---\n\n");
    /*int Number;
    FILE *fp;
    fp=fopen(FileName,"r");

    for(int i=0;i<N;i++)
    {
        fscanf(fp,"%d",&Number);
    }
    fclose(fp); */

    return;
}


void RunAboveBelowTEST(int Mod,int N){
    pf("\n\n--------Run Above/Below TEST-----\n");
    int Number,ObjAbove=0,Objbelow=0,Mean,Run=0;
    double alpha,Zalpha,calMean,CalVeri,Z0;
    bool flag;
    FILE *fp;
    fp=fopen(FileName,"r");
    Mean=((Mod-1)/2);
    fscanf(fp,"%d",&Number);

    if(Number>=Mean){
        flag=true;
        ObjAbove++;
    }else{
       flag=false;
       Objbelow++;
    }

    Run++;
    for(int i=1;i<N;i++)
    {
        bool flagTm;
        fscanf(fp,"%d",&Number);
        if(Number>=Mean){
            flagTm=true;
            ObjAbove++;
        }else{
           flagTm=false;
           Objbelow++;
        }
        if(flag!=flagTm) Run++;
        flag=flagTm;
    }
    fclose(fp);

    pf("Observed Above Mean= %d\n",ObjAbove);
    pf("Observed Below Mean= %d\n",Objbelow);
    pf("Total Runs= %d\n",Run);

    calMean=(double)( 2 * ObjAbove * Objbelow)/ (double) Number;
    calMean+=.5;
    CalVeri= (double) (2 * ObjAbove * Objbelow *( (2* ObjAbove *Objbelow) - Number));
    CalVeri/=(double)(Number * Number *((2 * Number)-1));

    Z0=((double)Run-calMean)/sqrt(CalVeri);
    pf("The value Of Z0= %.4lf\n\n",Z0);
    pf("\n Input The value Of Alpha=");
    sf("%lf",&alpha);
    pf("\n Input The Value Of Z (alpha/2)=");
    sf("%lf",&Zalpha);
    if((-Zalpha)<= Z0 && -Zalpha>=Z0)
        pf("\n\n-------Test Passed----\n\n");
    else pf("\n\n------Test Fail------\n\n");
    return;
}

void PokerTEST(int Mod,int N)
{
    pf("\n\n--------Pokers Test-----\n");

    int AllDif=0,TwoSame=0,AllSame=0,Number,a,b,c;
    double ChaiSqure, GivenChai[2];
    FILE *fp;
    fp=fopen(FileName,"r");

    for(int i=0;i<N;i++)
    {
        fscanf(fp,"%d",&Number);
        a=Number%10;
        Number/=10;
        b=Number%10;
        Number/=10;
        c=Number;
        if(a==b && b==c && c==a) AllSame++; //All Same Observed.
        else if(a==b || b==c || a==c) TwoSame++; //Any two Same Observed.
        else AllDif++; //All Different observed.
    }
    fclose(fp);

    a=(double)N * .72; //All different Expected
    b=(double)N * .27;//Any Two Same but not all
    c=N-(a+b); //All Same

    pf("\nObserved All Digits Different Numbers= %d\n", AllDif);
    pf("Observed All Digits Same Numbers= %d\n", AllSame);
    pf("Observed Two Digits Same Numbers= %d\n",TwoSame);

    pf("\nExpected All Digits Different Numbers= %d\n", a);
    pf("Expected All Digits Same Numbers= %d\n", c);
    pf("Expected Two Digits Same Numbers= %d\n", b);

    ChaiSqure= (pow((double)(a-AllDif),2)) / (double) a;
    ChaiSqure+= (pow((double)(b-TwoSame),2)) / (double) b;
    ChaiSqure+= (pow((double)(c-AllSame),2)) / (double) c;

    pf("\nObserved ChaiSqure Value= %lf\n",ChaiSqure);

    pf("Enter Chai Table Value for DOF(2)\nmin=");
    sf("%lf",&GivenChai[0]);
    pf("max=");
    sf("%lf",&GivenChai[1]);
    if(GivenChai[0]<= ChaiSqure && GivenChai[1]>= ChaiSqure)
         pf("\n\n----TEST PASSED---\n\n");
    else pf("\n\n---TEST FAIl--\n\n");

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
    pf("b.press 2 for Built In Rand Function\n");
    int choise,tm;
    sf("%d",&choise);
    if(choise==1)LCM(Mod,Number);
    else if(choise==2)DefaultRandom(Mod,Number);
    else pf("INVALID");
    system("cls");
    while(true){
        system("cls");
        pf("\nChoose Test.\n\n");
        pf("a.press 1 for Uniformity test\n");
        pf("b.press 2 for Independence test\n");
        sf("%d",&choise);
        if(choise==1){
                system("cls");
            ChaiSqureTest(Mod,Number);
            pf("\n\n\n ----Press 1 To Continue---\n");
            sf("%d",&tm);
        }
        else if(choise==2){
                system("cls");
                pf("\n Choose Independence Test.\n\n");
                pf("a.press 1 for Pokers test\n");
                pf("b.press 2 for Run Up Down test\n");
                pf("a.press 3 for Run Above Below test\n");
                pf("b.press 4 for Run test\n");
                sf("%d",&choise);
                system("cls");
                if(choise==1){
                    PokerTEST(Mod,Number);
                    pf("\n\n\n ----Press 1 To Continue---\n");
                    sf("%d",&tm);
                }else if(choise==2){
                    RunUpDownTEST(Mod,Number);
                    pf("\n\n\n ----Press 1 To Continue---\n");
                    sf("%d",&tm);
                }else if(choise==3){
                    RunAboveBelowTEST(Mod,Number);
                    pf("\n\n\n ----Press 1 To Continue---\n");
                    sf("%d",&tm);
                }else if(choise==4){
                    RunTEST(Mod,Number);
                    pf("\n\n\n ----Press 1 To Continue---\n");
                    sf("%d",&tm);
                }else{
                    pf("\n\n------INVALID-----\n\n");
                }
        }
        else{
            pf("\n\n------INVALID-----\n\n");
        }
    }

    return 0;
}
