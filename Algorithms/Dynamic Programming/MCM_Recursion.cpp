#include <iostream>
#include <climits>
using namespace std;
int solve(int arr[],int i,int j)
{
    int min=INT_MAX;
    if(i>=j)
        return 0;
    for(int k=i;k<j;k++)
    {
        int temp=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(temp<min)
            min=temp;
    }
    return min;
}
int main()
{
    cout<<"Enter the number of matrices ";
    int n;
    cin>>n;
    n++;
    int arr[n];
    cout<<"Enter the dimension array ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"The minimum number of multiplications required= "<<solve(arr,1,n-1);
}
