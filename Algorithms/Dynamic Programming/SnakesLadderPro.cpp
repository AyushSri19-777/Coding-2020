#include<bits/stdc++.h>
using namespace std;
bool check(int i,int j,unordered_map<int,int> U)
{
    if(U[i]<=j)
        return true;
    return false;
}
int minMoves(int i,int j,unordered_map<int,int> U,int m)
{
    int result=INT_MAX;
    if(i>=j)
        return 0;
    if(check(i,j,U)==true)
    {
        if(U[i]<i)
          return minMoves(i-U[i],j,U,m);
        else
        {
            return minMoves(i+U[i],j,U,m);
        }        
    }
    for(int k=1;k<=m;k++)
    {
        int temp_ans=minMoves(i+k,j,U,m);
        result=min(result,temp_ans);
    }        
}
int main()
{
    int m,n,h,start,end,x,y;
    unordered_map<int,int> U;
    cout<<"Enter matrix size";
    cin>>n;
    cout<<"Enter the max value";
    cin>>m;
    cout<<"Enter no. of moves";
    cin>>h;
    cout<<"Enter moves";
    for(int i=0;i<h;i++)
    {
        cout<<"Enter starting";
        cin>>x;
        cout<<"Enter end";
        cin>>y;
        U[x]=y;
    }
    cout<<"Enter start and end";
    cin>>start>>end;
    cout<<minMoves(start,end,U,m);
}
