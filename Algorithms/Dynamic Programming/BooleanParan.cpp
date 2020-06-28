#include <iostream>
#include <string.h>
using namespace std;
int solve(string s,int i,int j,bool isTrue)
{
    if(i>j)
        return 0;
    if(isTrue==true)
        return s[i]=='T';
    else
    {
        return s[i]=='F';
    }
    int ans=0;
    for(int k=i+1;k<j;k+=2)
    {
        int lT=solve(s,i,k-1,true);
        int lF=solve(s,i,k-1,false);
        int rT=solve(s,k+1,j,true);
        int rF=solve(s,k+1,j,false);
        if(s[k]=='&')
        {
            if(isTrue==true)
                ans+=lT*rT;
            else
            {
                ans+=lT*rF+lF*rT+lF*rF;
            }
        }
        if(s[k]=='|')
        {
            if(isTrue==true)
                ans+=lT*rT+lT*rF+lF*rT;
            else
            {
                ans+=lF*rF;
            }
        }
        if(s[k]=='^')
        {
            if(isTrue==true)
                ans+=lT*rF+lF*rT;
            else
            {
                ans+=lT*rT+lF*rF;
            }
        }
    }
    return ans;    
}
int main()
{
    cout<<"Enter the expression= ";
    string s;
    cin>>s;
    cout<<"Minimum number of ways= "<<solve(s,0,s.length()-1,true);
}