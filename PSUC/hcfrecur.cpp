#include<iostream>
using namespace std;
int hcf(int x,int y)
{
    if(x==0)
        return y;
    if(y==0)
        return x;
    hcf(y,x%y);
}
int main()
{
    int a,b;
    cout<<"Enter two numbers for HCF\n";
    cin>>a>>b;
    cout<<"The HCF is= "<<hcf(a,b);
    return 0;
}
