#include<iostream>
using namespace std;

int ways(int n,int m,int sum)
{
    if(m==0||sum==0)
        return 0;
    int ans=m+

}
int main()
{
    cout<<"Enter n.m and sum";
    int n,m,sum;
    cin>>n>>m>>sum;
    cout<<ways(n,m,sum);
    return 0;
}