#include<bits/stdc++.h>
using namespace std;
int t[101];
int solve(int arr[],int i,int n)
{
    if(i>=n-1)
        return 0;
    return 1+solve(arr,i+arr[i],n); 
}
int solveTD(int arr[],int i,int n)
{
    if(i>=n-1)
        return 0;
    for(int i=0;i<n;i++)
        t[i]=1+solveTD(arr,i+arr[i],n);    
    return t[i];
}
int main()
{
    cout<<"Enter n";
    int n;
    cin>>n;
    int arr[n];
    memset(t,-1,sizeof(t));
    cout<<"Enter "<<n<<" elements";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Total jumps= "<<solveTD(arr,0,n);
    
}