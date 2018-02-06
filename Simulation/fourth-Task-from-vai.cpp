#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int EvenNum=0;
    for(int i=0; i<=14; i++)
    {
        if(i&1) printf("%d\n",(i*i));
        else
        {
            printf("%-8d%-16s\n",(i*i),"Even number!!!");
            EvenNum++;
        }
    }
    printf("\nTotal count of even numbers is: %d",EvenNum);
    return 0;
}
