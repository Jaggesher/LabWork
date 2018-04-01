#include<bits/stdc++.h>
#define pf printf
#define sf scanf
using namespace std;
string KeySeq;
int giveActualIndex(char ch)
{
    if( ch>='a' && ch <= 'z') return (ch-'a');
    if( ch>='A' && ch <= 'Z') return (ch-'A');
}

string Encript(string data)
{
    int len = data.size();
    string value=data;
    for(int i=0,n=0 ;i<len;i++,n++)
    {
        if(data[i]>='a' && data[i]<='z')
        {
            int tm =((data[i]-'a') + giveActualIndex(KeySeq[n]))%26;
            value[i]=tm+'a'+1;
        }else if(data[i]>='A' && data[i]<='Z')
        {
            int tm =((data[i]-'A') + giveActualIndex(KeySeq[n]))%26;
            value[i]=tm+'A'+1;
        }else
        {
            value[i]=data[i];
        }
    }

    return value;
}

string Decript(string data)
{
    int len = data.size();
    string value=data;
    for(int i=0,n=0 ;i<len;i++,n++)
    {
        if(data[i]>='a' && data[i]<='z')
        {
            int tm =((data[i]-'a') - giveActualIndex(KeySeq[n]));

            if(tm<=0) value[i]=tm+'a'+ 26 -1;
            else value[i]=tm+'a'-1;

        }else if(data[i]>='A' && data[i]<='Z')
        {
            int tm =((data[i]-'A') - giveActualIndex(KeySeq[n]));

            if(tm<=0) value[i]=tm+'A'-1 + 26;
            else value[i]=tm+'A'-1;

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

    //TBFRGFARFM

    pf("Input Key Sequence: ");
    getline(cin,KeySeq);

    //ONETIMEPAD

    pf("Please Input given string: ");
    getline(cin,value);

    string EncrptedMsg= Encript(value);
    string DecriptedMsg = Decript(EncrptedMsg);

    pf("\n\n---------------------------------------\n\n");

    pf("Encripted Message: ");
    cout << EncrptedMsg<<endl;

    pf("Decripted Message: ");
    cout << DecriptedMsg<<endl;
    return 0;
}
