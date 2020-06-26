#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
int t[101][101];
int solve(int arr[],int i,int j)
{
    int min=INT_MAX;
    if(i>=j)
        return 0;
    if(t[i][j]!=-1)
        return t[i][j];
    for(int k=i;k<j;k++)
    {
        int temp_ans=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(temp_ans<min)
            min=temp_ans;
    }
    return t[i][j]=min;
}
int main()
{
    cout<<"Enter the number of matrices ";
    int n;
    cin>>n;
    n++;
    int arr[n];
    memset(t,-1,sizeof(t));
    cout<<"Enter the dimension array ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"The minimum number of multiplications required= "<<solve(arr,1,n-1);
}
