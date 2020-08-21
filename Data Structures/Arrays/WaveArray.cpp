#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of array elements\n";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i+=2)
    {
        if(i-1>0&&arr[i-1]>arr[i])
        {
            arr[i-1]=arr[i-1]^arr[i];
            arr[i]=arr[i]^arr[i-1];
            arr[i-1]=arr[i-1]^arr[i];
        }
        if(arr[i+1]>arr[i])
        {
            arr[i+1]=arr[i+1]^arr[i];
            arr[i]=arr[i]^arr[i+1];
            arr[i+1]=arr[i+1]^arr[i];
        }       
    }
    cout<<"The wave form array\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"\t";
}