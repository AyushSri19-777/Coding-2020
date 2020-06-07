#include <iostream>
#include <climits>
#include <math.h>
using namespace std;
int unbound(int wt[],int val[],int n)
{
    int t[n+1][n+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0||j==0)
                t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(wt[i-1]<=j)
                t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
            else
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][n];
}
int main() {
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    int n;
	    cin>>n;
	    int length[n],price[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>price[i];
	        length[i]=i+1;
	    }
	    cout<<unbound(length,price,n)<<"\n";
	}
	return 0;
}