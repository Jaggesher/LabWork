#include<bits/stdc++.h>
#define pf printf
#define sf scanf
using namespace std;

string Encript(string data,int width)
{
    int len = data.size();
    string value=data;

    for(int i=0,n=0;i<width;i++)
        for(int j=i;j<len;j+=width) value[n++]=data[j];

    return value;
}

string Decript(string data,int width)
{
    int len = data.size();
    string value=data;
    width = ceil((double)len/(double)width);

    for(int i=0,n=0;i<width;i++)
        for(int j=i;j<len;j+=width) value[n++]=data[j];

    return value;
}

int main()
{
    string value;
    int pos1,pos2;
    pf("Please Input given string: ");
    getline(cin,value);
    pf("plese Input width1: ");
    sf("%d",&pos1);
    pf("plese Input width2: ");
    sf("%d",&pos2);

    string EncrptedMsg1= Encript(value,pos1);
    string EncrptedMsg2= Encript(EncrptedMsg1,pos2);
    string DecriptedMsg1 = Decript(EncrptedMsg2,pos2);
    string DecriptedMsg2 = Decript(DecriptedMsg1,pos1);

    pf("\n\n---------------------------------------\n\n");

    pf("Encripted Message1: ");
    cout << EncrptedMsg1<<endl;

    pf("Encripted Message2: ");
    cout << EncrptedMsg2<<endl;


    pf("Decripted Message1: ");
    cout << DecriptedMsg1<<endl;

    pf("Decripted Message2: ");
    cout << DecriptedMsg2<<endl;
    return 0;
}
