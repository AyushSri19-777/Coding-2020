#include<iostream>
using namespace std;
int main()
{
    int D;string P;
    cin>>D>>P;
    int k=1,dam=1;;
    for(int i=0;i<P.length();i++)
    {
        if(P[i]=='C')
            k*=2;
        if(P[i]=='D')
        {
            k-=k;
            dam++;
        }
        if(dam>=D)
            break;
    }
    cout<<k;
}