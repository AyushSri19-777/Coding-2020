/*It is sam as 0/1 knapsack the only difference is that if an element is chosen,
it can be chosen again and again. So we need to iterrate over all n elements if nth element is chosen.
*/
#include <iostream>
using namespace std;
int unbound(int wt[],int val[],int W,int n)
{
    int t[n+1][W+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0||j==0)
                t[i][j]=0;
        }
    }
    //creating matrix
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            if(wt[i-1]<=j)
                t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);//changes t[i-1]-->t[i]
            else
            {
                t[i][j]=t[i-1][j];
            }            
        }
    }
    return t[n][W];
}
int main()
{
    int n,W;
    cout<<"Enter the number of elements ";
    cin>>n;
    int wt[n],val[n];
    cout<<"Enter the weight and values of "<<n<<" itmes";
    for(int i=0;i<n;i++)
        cin>>wt[i]>>val[i];
    cout<<"Enter the capacity ";
    cin>>W;
    cout<<"The maximum profit= "<<unbound(wt,val,W,n);
}
