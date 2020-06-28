#include <iostream>
#include <string.h>
using namespace std;
bool scramble(string a,string b)
{
    if(a.length()<1||b.length()<1)
        return false;
    if(a.compare(b)==true)
        return true;
    bool flag=false;
    int n=a.length();
    for(int i=1;i<n;i++)
    {
        if( ( (scramble(a.substr(0,i),b.substr(n-i,i))==true) && (scramble(a.substr(i,n-i),b.substr(0,n-i))==true)) || ( (scramble(a.substr(0,i),b.substr(0,i))==true) && (scramble(a.substr(i,n-i),b.substr(i,n-i))==true)) )
        {
            flag=true;
            break;
        }
    }
    return flag;
}
int main()
{
    cout<<"Enter 2 strings ";
    string a,b;
    cin>>a>>b;
    if(a.length()!=b.length())
    {
        cout<<"The lengths are different ";
        return 0;
    }
    else if(a.length()==0 && b.length()==0)
    {
        cout<<"The strings are scambled";
        return 0;
    }
    else
    {
        if(scramble(a,b)==true)
            cout<<"SCRAMBLED STRINGS";
        else
        {
            cout<<"Not Scrambled Strings";
        }   
    }
}