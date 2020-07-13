#include <iostream>
using namespace std;
int main()
{
    cout<<"Enter two numbers";
    int a,b;
    cin>>a>>b;
    cout<<"Before swapping a: "<<a<<" b: "<<b;
    a=a^b;
    b=b^a;
    a=a^b;
    cout<<"\nAfter swapping a: "<<a<<" b: "<<b;
    return 0;
}