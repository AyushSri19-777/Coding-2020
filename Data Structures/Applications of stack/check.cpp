#include <iostream>
#include <vector>
using namespace std;
vector<string>getDecision(int a , int b)
{
    std::vector<string> s;
    int i=a;
    while(i!=b)
    {
        if((i*2)==(b-1))
        {
            s.push_back("eat");
            i-=1;   
        }
        else if((i*2)>b)
        {
            s.push_back("eat");
            i-=1; 
        }
        else if((i*2)==(b+1))
        {
            s.push_back("overflow");
            i*=2; 
            i-=1;
        }
        else
        {
            s.push_back("overflow");
            i*=2; 
        }        
    }
    return s;
}
int main()
{
    vector <string> p=getDecision(1,9);
    for(int i=0;i<p.size();i++)
        cout<<p[i]<<" ";
}
