#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements\n";
    cin>>n;
    int arr[n],sum=0,f=0;
    unordered_map<int,int> U;
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        U[sum]+=1;
    }
    unordered_map<int,int>::iterator itr;
    for(itr=U.begin();itr!=U.end();itr++)
    {
        if(itr->second>1||itr->first==0)
        {
            f=1;
            break;
        }
    }
    if(f==1)
        cout<<"Subset hai jiska sumwa 0 hai\n";
    else
    {
        cout<<"Subset with 0 sum doesn't exist\n";
    }
    
}