#include<bits/stdc++.h>
#define pf printf
#define sf scanf
using namespace std;
map<string,int>Dictionary;
ifstream inputFile;
ofstream outputFile;

void Compress()
{
    string s="";
    char c;
    inputFile>>c;
    s+=c;
    int code= Dictionary.size();
    while( inputFile>>c && !inputFile.eof())
    {
        string tm = s+c;
        if(Dictionary[tm]!=0) s = tm;
        else{
            outputFile<<Dictionary[s]<<" ";
            Dictionary[tm]= ++code;
            s="";
            s+=c;
        }
    }
    outputFile<<Dictionary[s]<<" ";

    pf("\nFile Compressed.... see \"lzwCompress.txt\"\n\n");
}

void MakeDictionary()
{

    Dictionary.clear();

    string STemp;
    int ITemp;
    while((inputFile>>STemp) && STemp!="" && STemp!="----")
    {
        inputFile>>ITemp;
        Dictionary[STemp]=ITemp;
    }
    //Line Feed
    getline(inputFile,STemp);

    pf("\nDictionary Generated....\n");

}

int main()
{
    inputFile.open("lzwInput.txt");
    outputFile.open("lzwCompress.txt");
    if (inputFile.is_open())
    {
        MakeDictionary();
        Compress();
        pf("\nSuccess :) \n\n");
        inputFile.close();
        outputFile.close();
    }else{
        pf("Can't find the input File.");
    }
    return 0;
}

