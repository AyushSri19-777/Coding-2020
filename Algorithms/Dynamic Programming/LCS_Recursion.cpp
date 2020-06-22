#include <iostream>
#include <string.h>
using namespace std;
int LCS(string x,string y,int n,int m)
{
    if(n==0||m==0)
        return 0;
    if(x[n-1]==y[m-1])
    {
        return 1+LCS(x,y,n-1,m-1);
    }
    else
    {
        return max(LCS(x,y,n-1,m),LCS(x,y,n,m-1));
    }    
}
int main()
{
    string x,y;
    int n,m;
    cout<<"Enter two strings";
    cin>>x>>y;
    n=x.length();
    m=y.length();
    cout<<"The length of longest common subsequence= "<<LCS(x,y,n,m);
}