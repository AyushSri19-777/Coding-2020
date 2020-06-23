#include <iostream>
#include <string.h>
using namespace std;
int LCString(string x,string y,int n,int m)
{
    int t[n+1][m+1],max=0;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0||j==0)
                t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(x[i-1]==y[j-1])
                t[i][j]=1+t[i-1][j-1];
            else
            {
                t[i][j]=0;
            }            
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(t[i][j]>max)
                max=t[i][j];
        }
    }
    return max;
}
int main()
{
    string x,y;
    cout<<"Enter the strings\n";
    cin>>x>>y;
    cout<<"The length of longest common substring= "<<LCString(x,y,x.length(),y.length());
}