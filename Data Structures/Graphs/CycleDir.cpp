#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
bool allvisited(vector <int> p,int v[])
{
    int f=0;
    for(int i=0;i<p.size();i++)
    {
        int j=p.at(i);
        if(v[j]==0)
        {
            f=1;
            break;
        }
    }
    if(f==1)
        return false;
    return true;
}
int main()
{
    int n,e;
    cout<<"Enter the number of vertices and edges\n";
    cin>>n>>e;
    bool f=false;
    vector <int> graph[n];
    int v[n];
    memset(v,-1,sizeof(v));
    cout<<"Enter the edges\n";
    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
    }
    stack <int> stk;
    int s=0;
    stk.push(s);
    v[s]=0;
    cout<<s<<"\t";
    while(stk.empty()!=true)
    {
        int k=0,j;
        for(int i=0;i<graph[s].size();i++)
        {
            j=graph[s].at(i);
            if(v[j]==0)
            {
                f=true;
                break;
            }
            else if(v[j]==-1)
            {
                k=1;
                stk.push(j);
                cout<<j<<"\t";
                v[j]=0;
                break;             
            }
        }
        if(f==true)
            break; 
        if(k==1)
        {
            s=j;
        }
        else
        {
            s=stk.top();
            if(allvisited(graph[s],v))
            {
                stk.pop();
                v[s]=1;
            }
        }      
    }
    if(f==false)
    {
        cout<<"No cycle";
    }
    else
    {
        cout<<"Cycle is present";
    }
    
}