#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int n,e;
    cout<<"Enter the number of vertices and edges\n";
    cin>>n>>e;
    vector <int> graph[n];
    int v[n];
    memset(v,0,sizeof(v));
    cout<<"Enter the edges\n";
    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    stack <int> stk;
    int s=0,j;
    stk.push(s);
    v[s]=1;
    cout<<s<<"\t";
    while(stk.empty()!=true)
    {
        int f=0;
        for(int i=0;i<graph[s].size();i++)
        {
            j=graph[s].at(i);
            if(v[j]!=1)
            {
                f=1;
                cout<<j<<"\t";
                stk.push(j);
                v[j]=1;
                break;
            }
        }
        if(f==1)
        {
            s=j;
        }
        else
        {
            s=stk.top();
            stk.pop();
        }        
    }
}