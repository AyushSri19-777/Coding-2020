#include <iostream>
#include <cstring>
using namespace std;
int t[102][1002];
int knapsack(int wt[],int val[],int W,int n)
{
    if(W==0||n==0)
        return 0;
    if(t[n][W]!=-1)
        return t[n][W];
    if(wt[n-1]<=W)
        return t[n][W]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
    else
    {
        return t[n][W]=knapsack(wt,val,W,n-1);
    }    
}
int main()
{
    int W,n;
    cout<<"Enter the number of items";
    cin>>n;
    int wt[n],val[n];
    cout<<"Enter the maximum capacity";
    cin>>W;
    cout<<"Enter the weight and values of "<<n<<" items";
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    memset(t,-1,sizeof(t));
    cout<<"The maximum profit is= "<<knapsack(wt,val,W,n);
}