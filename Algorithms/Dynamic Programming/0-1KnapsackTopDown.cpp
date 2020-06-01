#include <iostream>
using namespace std;
int main()
{
    int n,W;
    cout<<"Enter number of elements and maximum Knapsack capacity ";
    cin>>n>>W;
    cout<<"Enter the weight and values of "<<n<<" items";
    int wt[n],val[n],t[n+1][W+1];
    for(int i=0;i<n;i++)
        cin>>wt[i]>>val[i];
    //Initialise the row 0 and column 0 and store other values in matrix
    for(int i=0;i<n+1;i++)
        for(int j=0;j<W+1;j++)
            if(i==0||j==0)
                t[i][j]=0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            if(wt[i-1]<=j)
            {
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
            
        }
    }
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            cout<<t[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"The maximum profit is: "<<t[n][W];

}