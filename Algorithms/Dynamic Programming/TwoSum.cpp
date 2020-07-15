#include <iostream>
#include <cstring>
using namespace std;
int ans[100];
bool oneIns(int arr[],int n)
{
    bool f=false;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            f=true ;
            break;
        }
    }
    return f;
}
void twosum(int arr[],int n,int sum)
{
    if(n==0||sum==0)
        return;
    if(arr[n-1]<sum&&oneIns(ans,n)==true)
    {
        cout<<"if xec";
        ans[n-1]=0;
        twosum(arr,n-1,sum);
    }
    else if(arr[n-1]<=sum)
    {
        cout<<"elif xec";
        ans[n-1]=1;
        twosum(arr,n-1,sum-arr[n-1]);
    }   
    else
    {
        cout<<"else xec";
        ans[n-1]=0;
        twosum(arr,n-1,sum);
    }
}
int main()
{
    int n,sum;
    cout<<"Enter n\n";
    cin>>n;
    int arr[n];
    cout<<"Enter array\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    memset(ans,0,sizeof(ans));
    cout<<"Enter target sum\n";
    cin>>sum;
    int ew[]={0,0,0,0,0};
    cout<<"onerknkef"<<oneIns(ew,5);
    twosum(arr,n,sum);
    for(int i=0;i<n;i++)
    {
        if(ans[i]==1)
            cout<<i<<"\t";
    }

}