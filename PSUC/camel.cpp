
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int sum(int n)
{
    if(n==0)
        return 0;
    else

            return sum(n/10)+n%10;


}
int main()
{
    int k,p;
    cin>>k;
    p=sum(k);
    while(p>9)
    {
        p=sum(p);
    }
    cout<<"\n"<<p;
    return 0;
}
