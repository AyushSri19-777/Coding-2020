#include <iostream>
using namespace std;
int countSubset(int arr[],int n,int sum)
{
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                t[i][j]=0;
            if(j==0)
                t[i][j]=1;
        }
    }
    //matrix creation of sum
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
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
    int n,sum,sumArr=0;
    cout<<"Enter the number of elements ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" array elements";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sumArr+=arr[i];
    }
    cout<<"Enter the target sum ";
    cin>>sum;
    cout<<"The count of sets making upto target sum= "<<countSubset(arr,n,(sum+sumArr/2));
}