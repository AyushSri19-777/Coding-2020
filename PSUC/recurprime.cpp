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
int main()
{
    int n;
    cin>>n;
    if(isPrime(n)==1)
        cout<<"Prime";
     else
     cout<<"Not Prime";
}
