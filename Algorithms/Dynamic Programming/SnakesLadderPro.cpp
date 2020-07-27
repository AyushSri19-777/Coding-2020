#include<bits/stdc++.h>
using namespace std;
bool checkLadder(int i,int j,unordered_map U)
{
    if(U[i]<=j)
        return true;
    return false;
}
int minMoves(int start,int end,int i,int j,unordered_map U)
{
    if(start==n)
        return 0;
    if(checkLadder(i,j,U)==true)
        start+=U[i];
}
int main()
{
    int m,n,h;
    unordered_map<int,int> U;
    cout<<"Enter matrix size";
    cin>>n;
    cout<<"Enter the max value";
    cin>>m;
    cout<<"Enter moves";
    cin>>h;
    for(int i=0;i<h;h++)
    {
        int x,y;
        cin>>x>>y;
        U[x]=y;
    }
    cout<<minMoves()

}
