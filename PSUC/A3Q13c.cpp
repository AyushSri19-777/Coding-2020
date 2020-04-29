#include <iostream>
using namespace std;
long binary(int n)
{
    if(n==0)
        return 0;
    else
        return binary(n/2)*10+n%2;

}
long rev(long n)
{
    long r=0;
    while(n!=0)
    {
        if(n%10==1)
        r=r*10+n%10;
        else
         r=r*10+n%10;
        n/=10;
    }
    return r;
}

int main()
{
    int a,b;
    long m,n,sum;
    cout<<"Enter two decimal numbers \n";
    cin>>a>>b;
    cout<<binary(a)<<"\n";
    cout<<binary(b)<<"\n";
    m=binary(a);
    n=binary(b);
    cout<<rev(m);
    cout<<"\nThe sum = ";
}
