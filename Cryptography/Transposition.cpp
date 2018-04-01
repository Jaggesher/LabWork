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
    int pos;
    pf("Please Input given string: ");
    getline(cin,value);
    pf("plese Input width: ");
    sf("%d",&pos);

    string EncrptedMsg= Encript(value,pos);
    string DecriptedMsg = Decript(EncrptedMsg,pos);

    pf("\n\n---------------------------------------\n\n");

    pf("Encripted Message: ");
    cout << EncrptedMsg<<endl;

    pf("Decripted Message: ");
    cout << DecriptedMsg<<endl;
    return 0;
}
