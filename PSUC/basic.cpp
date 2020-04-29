#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;


int main() {
    string st="",a="";
    cin>>st;
    int i,sum=0,b;
    for(i=0;i<st.length();i++)
    {
        if(st[i+1]==' '&&st[i]!=' ')
        {
            a=st.substr(0,i);
            stringstream geek(a);
            geek>>b;
            cout<<b;
            sum+=b;
            st=st.substr(0,i);
        }
    }
    cout<<sum;
    return 0;
}
