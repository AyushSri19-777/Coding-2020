#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    gcd(b,a%b);
}
int main()
{
    int n;
    cout<<"Enter number of elements\n";
    cin>>n;
    int arr[n],temp;
    cout<<"Enter elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    temp=arr[0];
    for(int i=0;i<n;i++)
    {
        temp=gcd(temp,arr[i]);
    }
    cout<<"GCD of Array= "<<temp;
}