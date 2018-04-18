#include<bits/stdc++.h>
#define pf printf
#define sf scanf
using namespace std;
map<int,string>Dictionary;

bool MakeDictionary()
{
    ifstream inputFile ("lzwInput.txt");

    if (!inputFile.is_open())
    {
        pf("Cant Open File.\n\n");
        return false;
    }

    Dictionary.clear();

    string STemp;
    int ITemp;
    while((inputFile>>STemp) && STemp!="" && STemp!="----")
    {
        inputFile>>ITemp;
        Dictionary[ITemp]=STemp;
    }
    //Line Feed
    getline(inputFile,STemp);

    pf("\nDictionary Generated....\n");
    inputFile.close();
    return true;
}

int main()
{
    int k;
    string s="";

    ifstream myfile ("lzwCompress.txt");
    if (myfile.is_open() && MakeDictionary())
    {
        int code = Dictionary.size();
        pf("Decompress Text: \n");
        while( myfile>>k && !myfile.eof())
        {
            string entry = Dictionary[k];
            cout<<entry;
            if(s!="")
                Dictionary[++code] = s+entry[0];
            s=entry;
        }
        myfile.close();
    }
   else cout << "Unable to open file";
    return 0;
}

