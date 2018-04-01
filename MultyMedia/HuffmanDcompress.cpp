#include <bits/stdc++.h>
using namespace std;
map<string,char>code;

int main()
{
    string line;
    ifstream myfile ("compress.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line)  && line!="-----------")
        {
          char ch = line[0];
          string tm = "";
          int len = line.size();

          for (int i=2;i<len;i++) tm += line[i];
          code[tm]=ch;
        }

        cout <<"\nDecompress Text: ";
        while((myfile>>line) && line!="")
        {
           cout<<code[line];
        }
        cout<<endl;
        myfile.close();
    }

  else cout << "Unable to open file";


    return 0;
}
