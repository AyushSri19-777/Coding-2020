#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,f=0;
    cout<<"Enter the number of elements\n";
    cin>>n;
    int arr[n],sum=0;
    unordered_map<int,int>U;
    cout<<"Enter the binary array\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==0)
            arr[i]=-1;
        sum+=arr[i];
        U[sum]++;
    }
    unordered_map<int,int>::iterator itr;
    for(itr=U.begin();itr!=U.end();itr++)
    {
        if(itr->first==0||itr->second>1)
        {
            f=1;
            break;
        }
    }
    if(f==1)
        cout<<"Yes there is a subset having equal 0s and 1s\n";
    else
    {
        cout<<"No\n";
    }
    


}