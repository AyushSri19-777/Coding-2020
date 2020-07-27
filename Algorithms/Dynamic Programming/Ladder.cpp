#include <iostream>
using namespace std;
int ladderDP(int n,int k)
{
    int *dp=new int[n];
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            dp[i]+=dp[i-j];
        }
    }
    return dp[n];
}
int main()
{
    cout<<"The min no. of ways= "<<ladderDP(4,3);
}
