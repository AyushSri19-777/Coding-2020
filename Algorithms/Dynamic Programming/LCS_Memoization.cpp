#include <iostream>
#include <string.h>
using namespace std;
int t[101][101];
int LCS(string x,string y,int n,int m)
{
    if(m==0||n==0)
        return 0;
    if(t[n][m]!=-1)
        return t[n][m];
    if(x[n-1]==y[m-1])
        return t[n][m]=1+LCS(x,y,n-1,m-1);
    else
    {
        return t[n][m]=max(LCS(x,y,n-1,m),LCS(x,y,n,m-1));
    }    
}
int main()
{
    string x,y;
    int n,m;
    cout<<"Enter two strings\n";
    cin>>x>>y;
    n=x.length();
    m=y.length();
    memset(t,-1,sizeof(t));
    cout<<"The length of longest common subsequence= "<<LCS(x,y,n,m);
}