#include <iostream>
#include<Math.h>
using namespace std;
int IsArms(int n)
{
    int m=n,sum=0;
    while(n!=0)
    {
        sum+=(n%10)*(n%10)*(n%10);
        n/=10;
    }
    if(sum==m)
        return 1;
    return 0;
}
int main()
{
    int a,b,i;
    cout<<"Enter the lower and upper limit\n";
    cin>>a>>b;
     for(i=a;i<=b;i++)
    {
        if(IsArms(i)==1)
        cout<<i<<"\n";
    }

}
