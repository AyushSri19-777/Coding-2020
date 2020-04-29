#include<iostream>
#include <math.h>
using namespace std;
int fact(int n)
{
    if(n<=1)
        return 1;
    else
        return n*fact(n-1);

}
int main()
{
    int n;
    double x;
    cout<<"Enter the value of x";
    cin>>x;
    cout<<"Enter the limit";
    cin>>n;
    int i,c=1;
    double si=0.0;
    for(i=1;i<=n;i++)
    {
        if(i%2==1)
           si=si + (pow(x,c)/fact(c));
       else
          si= si- (pow(x,c)/fact(c));
          c+=2;

    }
    cout<<"sin x="<<si;

}
