#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n";
    cin>>n;
    int k=1,h=n,t=1,i;
    for(i=1;i<=n;i++)
    {
        for(int sp=1;sp<=h;sp++)
            cout<<" ";
        for(int j=1;j<=t;j++)
        {
            if(j%2!=0)
               cout<<k++;
            else
                cout<<" ";

        }
        t+=2;
        cout<<"\n";
        h--;
    }
}
