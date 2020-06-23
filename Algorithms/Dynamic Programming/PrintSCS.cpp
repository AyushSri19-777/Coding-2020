#include <iostream>
#include <string.h>
using namespace std;
void LCS(string x,string y,int n,int m)
{
    int t[n+1][m+1];string s="";
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
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }            
        }
    }
    int i=n,j=m;
    while(i>0&&j>0)
    {
        if(x[i-1]==y[j-1])
        {
            s=y[j-1]+s;
            i--;
            j--;
            
        }
        else
        {
            if(t[i][j-1]>t[i-1][j])
            {
                s=y[j-1]+s;
                j--;
            }
            else
            {
                s=x[i-1]+s;
                i--;
            }
        }
    }
    while(i>0)
    {
        s=x[i-1]+s;
        i--;
    }
    while(j>0)
    {
        s=y[j-1]+s;
        j--;
    }
    cout<<s;
}
int main()
{
    string x,y;
    int n,m;
    cout<<"Enter two strings\n";
    cin>>x>>y;
    n=x.length();
    m=y.length();
   // memset(t,-1,sizeof(t));
    cout<<"The shortest common supersequence= ";
    LCS(x,y,n,m);
}