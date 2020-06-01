#include<iostream>
using namespace std;
int main()
{
    int n,sum;
    cout<<"Enter the number of elements and sum for subset ";
    cin>>n>>sum;
    bool t[n+1][sum+1];
    int arr[n];
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //Initialise the matrix ke 0 rows and column
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                t[i][j]=false;
            if(j==0)
                t[i][j]=true;
        }
    }
    //develop the matrix parallelto knapsack problem
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j]=(t[i-1][j-arr[i-1]])||(t[i-1][j]);
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    if(t[n][sum]==true)
        cout<<"subset exists";
    else
    {
        cout<<"subset doesn't exist";
    }
    // for(int i=0;i<n+1;i++)
    // {
    //     for(int j=0;j<sum+1;j++)
    //     {
    //         cout<<t[i][j]<<"\t";
    //     }
    //     cout<<"\n";
    // }
}