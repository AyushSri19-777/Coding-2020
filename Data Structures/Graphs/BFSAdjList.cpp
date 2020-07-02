#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int main()
{
    int n,e;
    cout<<"Enter the number of vertices and edges\n";
    cin>>n>>e;
    vector <int> graph[n];
    cout<<"Enter the edges\n";
    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int s=0,v[n];
    queue <int> q;
    cout<<"The BFS is\n";
    memset(v,0,sizeof(v));
    if(v[s]==0)
    {
        v[s]=1;
        q.push(s);
    }    
    while(q.empty()!=true)
    {
        s=q.front();
        q.pop();
        cout<<s<<"\t";
        for(int i=0;i<graph[s].size();i++)
        {
            int j=graph[s].at(i);
            if(v[j]!=1)
            {            
            q.push(j);
            v[j]=1;
            }
        }
        
    }
}