/*
    LabWork: 03
    Title: HSV To RGB.
    Name: Jaggesher Mondal
    Roll: 14025423
*/
#include<bits/stdc++.h>
#define pf printf
#define sf scanf
using namespace std;

int R,G,B;

void HSVtoRGB(double H, double S,double V){
   double R1,G1,B1,C,X,m,Tm;

   C=V*S;
   Tm=int(H/60);
   Tm=(H/60)-Tm;
   X=C*(1-fabs(((int)(H/60)%2)+Tm-1));
   m=V-C;

   if(H>=0 && H<60){
    R1=C;
    G1=X;
    B1=0;
   } else if(H>=60 && H<120){
    R1=X;
    G1=C;
    B1=0;
   } else if(H>=120 && H<180){
    R1=0;
    G1=C;
    B1=X;
   } else if(H>=180 && H<240){
    R1=0;
    G1=X;
    B1=C;
   } else if(H>=240 && H<300){
    R1=X;
    G1=0;
    B1=C;
   }else{
    R1=C;
    G1=0;
    B1=X;
   }

   R=round((R1+m)*255);
   G=round((G1+m)*255);
   B=round((B1+m)*255);
   return;
}

int main(){
    double H,S,V;
    pf("Enter The Color Code IN HSV.\n");
    pf("H=");
    sf("%lf",&H);
    pf("S=");
    sf("%lf",&S);
    pf("V=");
    sf("%lf",&V);

    HSVtoRGB(H,S,V);

    pf("RGB: (R=%d ,G=%d ,B=%d)",R,G,B);
    return 0;
}
