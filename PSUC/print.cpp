#include <iostream>
using namespace std;
void print(int n)
{
    static int a=1;
    if(a==n)
        cout<<n;
    else
    {
       cout<<a;
       a++;
       print(n);
    }

}
int main()
{
    int n;
    cin>>n;
    print(n);
}
