/*To check if an array can be divided into 2 subsets which have their sum equal to each other
Example: {1,5,11,5}
Subset 1->{1,5,5}->Sum=11
Subset 2->{11}->Sum=11
Output-True
*/
#include <iostream>
using namespace std;
bool checkEqualPartition(int arr[],int sum,int n)
{
    bool t[n+1][sum+1];
    //Initialise
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
    //Making matrix
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
    return t[n][sum];
}
int main()
{
    int n;
    cout<<"Enter the number of elements ";
    cin>>n;
    int arr[n],sum=0;
    cout<<"Enter the values of array ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<sum/2;
    bool ans=checkEqualPartition(arr,sum/2,n);
    if(ans==1)
        cout<<"Equal sum partition is possible";
    else
        cout<<"Equal sum partition is not possible";    
}
