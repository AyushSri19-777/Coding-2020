



#include <iostream>
using namespace std;
int gcd(int x,int y)
{
    if(x==0)
        return y;
    if(y==0)
        return x;
    return gcd(x,y%x);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
      return 0;
}
