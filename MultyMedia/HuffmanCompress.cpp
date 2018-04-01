#include <bits/stdc++.h>
using namespace std;
map<char,string>code;
ofstream myfile;

struct MinHeapNode {

    char data;

    unsigned freq;

    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)

    {

        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {

    bool operator()(MinHeapNode* l, MinHeapNode* r)

    {
        return (l->freq > r->freq);
    }
};


void printCodes(struct MinHeapNode* root, string str)
{

    if (!root)
        return;

    if (root->data != '$')
    {
        code[root->data]=str;
        //cout << root->data << ": " << str << "\n";

        myfile << root->data << " " << str << "\n";
    }


    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(vector<char>data, vector<int>freq, int size)
{
    struct MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    while (minHeap.size() != 1) {

        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}

int countChar(string Input,char s)
{
    int temp=0;
    for(int i=0;i<Input.size();i++)
    {
        if(Input[i]==s) temp++;
    }
    return temp;
}

int main()
{
    myfile.open ("compress.txt");
    string Input;
    cout<<"Enter Your String= ";
    getline(cin,Input);

    vector<char>arr;
    vector<int>freq;
    bitset<100>bt;

    for(int i=0;i<Input.size();i++)
    {
        if(!bt[Input[i]])
        {
            bt[Input[i]] = 1;
            freq.push_back(countChar(Input,Input[i]));
            arr.push_back(Input[i]);
         }
    }

    code.clear();

    HuffmanCodes(arr, freq, freq.size());
    myfile <<"-----------\n";
    //cout<<"\nCode= ";
    for(int i=0;i<Input.size();i++)
    {
        //cout<<code[Input[i]]<<" ";
        myfile<<code[Input[i]]<<" ";
    }
    //cout<<endl;

    cout<<"SUCCESS :) "<<endl;

    myfile.close();

    return 0;
}
