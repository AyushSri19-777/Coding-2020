#include <iostream>
using namespace std;
int main()
{
    int a[10][10],b[10][10],c[10][10];
    int m,n;
    cout<<"Enter the rows and column";
    cin>>m>>n;
    cout<<"Enter elements of 1st array";
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
          cin>>a[i][j];
     cout<<"Enter elements of 1st array";
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
          cin>>b[i][j];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
          c[i][j]=a[i][j]+b[i][j];
         cout<<"elements of 1st array";
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
          cout<<[i][j];
          cout<<"Enter elements of 1st array";
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
          cin>>a[i][j];

}
