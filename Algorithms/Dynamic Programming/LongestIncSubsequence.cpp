#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the number of elements\n";
    int n,maxi=0;
    cin>>n;
    int arr[n],b[n];
    cout<<"Enter elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Calculating lengths\n";
    for(int i=0;i<n;i++)
        b[i]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j]&&b[i]<=b[j])
                b[i]=1+b[j];
        }
    }
    vector <int> v;
    for(int i=0;i<n;i++)
        maxi=max(b[i],maxi);
    cout<<"Length of LIS= "<<maxi;
    cout<<"The subsequence is\n";
    for(int i=n-1;i>=0;i--)
    {
        if(b[i]==maxi)
        {
            v.push_back(arr[i]);
            maxi--;
        }
    }
    for(int i=v.size()-1;i>=0;i--)
        cout<<v.at(i)<<"\t";
}