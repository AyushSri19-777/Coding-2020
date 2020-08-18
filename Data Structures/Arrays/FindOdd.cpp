#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter array size\n";
    int n,xv=0;
    cin>>n;
    cout<<"Enter the array with duplicate and unique value\n";
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        xv^=arr[i];
    }
    cout<<xv;    
}