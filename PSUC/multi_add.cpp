#include <iostream>
using namespace std;
int multi(int n,int m)
{
    if(m==0)
        return 0;
    else
        return n+multi(n,m-1);
}
void chk()
{
    int i=5;
    int a[6]={1,2,3,8,5,7};
    cout<<a[i]<<i--<<i<<i--<<i<<i--;

}
int main()
{
    int a,b;
    cin>>a>>b;
    chk();
    cout<<"\n";
    int res=multi(a,b);
    cout<<res;
    return 0;
}
