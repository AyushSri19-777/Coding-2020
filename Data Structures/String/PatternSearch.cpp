#include <bits/stdc++.h>
using namespace std;
int getHash(string s)
{
    unordered_map <char,int> U;
    int sum=0;
    for(int i=1;i<=26;i++)
    {
        U[char(i+96)]=i;
    }

    for(int i=0;i<s.length();i++)
    {
        sum+=U[s[i]]*pow(10,s.length()-i-1);
    }
    return sum;
}
int main()
{
    string s,p,w;
    cout<<"Enter the string and pattern\n";
    cin>>s>>p;
    int pat=getHash(p),count=0,i;
    cout<<s.substr(0,3)<<"char\n";
    for(int j=0;j<s.length()-2;j++)
    {
        w=s.substr(j,p.length());
        cout<<w<<"\t"<<getHash(w)<<"\n";
        if(pat==getHash(w))
            count++;
    }
    cout<<"No. of pattern matches= "<<count;
}