#include<bits/stdc++.h>
#define pf printf
#define sf scanf
using namespace std;
string Encript(string data,int pos)
{
    int len = data.size();
    string value=data;
    for(int i=0 ;i<len;i++)
    {
        if(data[i]>='a' && data[i]<='z')
        {
            int tm =((data[i]-'a') + pos )%26;
            value[i]=tm+'a';
        }else if(data[i]>='A' && data[i]<='Z')
        {
            int tm =((data[i]-'A') + pos )%26;
            value[i]=tm+'A';
        }else
        {
            value[i]=data[i];
        }
    }

    return value;
}

string Decript(string data,int pos)
{
    int len = data.size();
    string value=data;
    for(int i=0 ;i<len;i++)
    {
        if(data[i]>='a' && data[i]<='z')
        {
            int tm =((data[i]-'a') - pos + 26)%26;
            value[i]=tm+'a';
        }else if(data[i]>='A' && data[i]<='Z')
        {
            int tm =((data[i]-'A') - pos +26 )%26;
            value[i]=tm+'A';
        }else
        {
            value[i]=data[i];
        }
    }

    return value;
}

int main()
{
    string value;
    int pos;
    pf("Please Input given string: ");
    getline(cin,value);
    pf("plese Input number of position: ");
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
