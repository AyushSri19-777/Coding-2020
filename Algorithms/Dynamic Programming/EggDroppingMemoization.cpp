#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int t[101][101];
int solve(int e,int f)
{
    if(e==1||f==0||f==1)
        return t[e][f]=f;
    if(t[e][f]!=-1)
        return t[e][f];
    int mn=INT_MAX;
    for(int k=1;k<=f;k++)
    {
        int temp=1+max(solve(e-1,k-1),solve(e,f-k));
        mn=min(mn,temp);
    }
    return t[e][f]=mn;
}
int main()
{
    cout<<"Enter the number of eggs and floors\n";
    int e,f;
    cin>>e>>f;
    memset(t,-1,sizeof(t));
    cout<<"The minimum number of attempts= "<<solve(e,f);
}