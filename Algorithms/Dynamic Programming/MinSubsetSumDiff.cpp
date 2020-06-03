#include <iostream>
#include <climits>
using namespace std;
int subsetSum(int arr[],int n,int sum)
{
    bool t[n+1][sum+1];
    //initialise
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
    //form the matrix
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            {
                t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
            
        }
    }
    int min=sum;
    for(int j=0;j<(sum+1)/2;j++)
    {
        if(t[n][j]==true)
        {
            if(sum-(2*j)<=min)
                min=sum-(j*2);
        }
    }
    return min;
}
int main()
{
    int n,sum=0;
    cout<<"Enter the number of elements ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<"The minimum difference of subsets= "<<subsetSum(arr,n,sum);
}