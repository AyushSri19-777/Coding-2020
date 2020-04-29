#include<iostream>
using namespace std;
int *pass(int ar[100][100],int n)
{
    int a[100],j,k=1;
    int *ptr=a;
     for(int i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(ar[i][j]%2==0)
            {
                a[k++]=ar[i][j];
            ar[i][j]=0;
            }

        }
    }
    a[0]=k;
    return ptr;
}
int main()
{
    int arr[100][100],n,i,j,sum=0;;
    cout<<"Enter the size of matrix";
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        cin>>arr[i][j];
    cout<<"The Original matrix\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<"\n";
    }
    int *p1=pass(arr,n);
    int c=*p1;
    for(i=1;i<c;i++)
    sum+=*(p1+i);
    cout<<"\nThe sum="<<sum;
    cout<<"\nThe Changed matrix\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
