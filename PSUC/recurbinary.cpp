#include <iostream>
using namespace std;
long binary(int n)
{
    if(n==0)
        return 0;
    else
        return binary(n/2)*10+n%2;

}
int main()
{
    int n;
    cout<<"Enter a number for binary equivalent\n";
    cin>>n;
    cout<<"the binary equivalent : "<<binary(n);
}
