#include<iostream>
using namespace std;
int isPrime(int p)
{
    static int i=2;
    if(i==p)
        return 1;
    if(p%i==0)
        return 0;
    i++;
    return isPrime(p);
}
int rev(int n)
{
    int reve=0;
    while(n!=0)
    {
        reve=(reve*10)+(n%10);
        n/=10;
    }
    return reve;
}
int main()
{
    int a,b,i;
    cout<<"Enter lower and upper limit";
    cin>>a>>b;
    cout<<isPrime(9)<<"\n"<<rev(123)<<"\n";
    for(i=a;i<=b;i++)
    {
        int k=rev(i);
        if(isPrime(i)==1)
        {
            if(isPrime(k)==1)
                cout<<i;
        }
    }
}
