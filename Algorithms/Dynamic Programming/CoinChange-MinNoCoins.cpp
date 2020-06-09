#include <iostream>
#include <climits>
using namespace std;
int minNoOfCoins(int arr[],int n,int sum)
{
    int t[n+1][sum+1];
    //Initialisation of row 1 and column 1
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
                t[i][j]=0;
            if(i==0)
                t[i][j]=INT_MAX-1;
        }
    }
    //Initialisation of row 2
    for(int j=1;j<n+1;j++)
    {
        if(j%arr[0]==0)
            t[2][j]=j/arr[0];
        else
        {
            t[2][j]=INT_MAX-1;
        }
    }
    //Creating matrix
    for(int i=2;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j]=min(t[i][j-arr[i-1]]+1,t[i-1][j]);
            else
            {
                t[i][j]=t[i-1][j];
            }            
        }
    }
    return t[n][sum];
}
int main()
{
    int n,sum;
    cout<<"Enter the number of denominations available \n";
    cin>>n;
    cout<<"Enter value of each denomination\n";
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the total expense=";
    cin>>sum;
    cout<<"The minimum number of coins needed to represent the sum "<<sum<<" is= "<<minNoOfCoins(arr,n,sum);
}