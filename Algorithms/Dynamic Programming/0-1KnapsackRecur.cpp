#include <iostream>
using namespace std;
int knapsack(int wt[],int val[],int W,int n)
{
    if(n==0||W==0)
        return 0;
    else if(wt[n-1]<=W)
        return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
    else
    {
        return knapsack(wt,val,W,n-1);
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
    cout<<"The maximum profit is= "<<knapsack(wt,val,W,n);
}
