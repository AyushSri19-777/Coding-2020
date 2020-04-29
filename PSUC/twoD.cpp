#include<iostream>
using namespace std;
void change(int n,int ar[100][100])
{
    int sum[10],i,j,k=0,s=0;
    for(int i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            s+=ar[i][j];
        }
        sum[k++]=s;
        s=0;
    }
     for(int i=0;i<n;i++)
        cout<<sum[i]<<" ";
    k=0;
    for(int i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((i+j)==(n-1))
            {
                ar[i][j]=sum[k];
                k++;
            }
        }

    }
}
int main()
{
    int a[100][100],n,i,j;
    cout<<"Enter the size of matrix\n";
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        cin>>a[i][j];
    cout<<"The Original matrix\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }
    change(n,a);
    cout<<"The Changed matrix\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }

}

