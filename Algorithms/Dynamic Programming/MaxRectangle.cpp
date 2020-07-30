#include <bits/stdc++.h>
using namespace std;
int maxi=0;
int getLowest(int arr[],int n)
{
    int mini=INT_MAX;
    for(int i=0;i<n;i++)
    {
        mini=min(arr[i],mini);
    }
    return mini;
}
int getArea(int arr[],int i,int j)
{
    if(i>=j)
        return 0;
    int b[j-i],y=0,area=0;
    for(int h=i;h<=j;h++)
        b[y++]=arr[h];
    area=getLowest(b,j-i)*(j-i);
    //cout<<i<<"\t"<<j<<"\t"<<area<<"\n";
    for(int k=i;k<j;k++)
    {
        maxi=max(area,maxi);
        getArea(arr,i,k);
        getArea(arr,k+1,j);
    }
    return maxi;
}
int main()
{
    cout<<"Enter T";
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cout<<"Enter n= ";
        cin>>n;
        int arr[n];
        cout<<"Enter elements";
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<"Max area= "<<getArea(arr,0,n);
        maxi=0;        
    }
}