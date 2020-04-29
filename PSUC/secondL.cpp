#include <iostream>
using namespace std;
int main()
{
    int a,n,i,sl=0,l=0;
    cout<<"Enter the limit\n";
    cin>>n;
    cout<<"Enter the values\n";
    for(i=1;i<=n;i++)
    {
        sl=l=0;
        cin>>a;
        if(a>l)
        {
            l=a;
            sl=l;

        }
        if(a>sl)
        {
            sl=a;
        }
    }
    cout<<"\nThe second largest = "<<sl;
}
