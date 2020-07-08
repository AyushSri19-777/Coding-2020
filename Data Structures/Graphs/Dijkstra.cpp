#include <bits/stdc++.h>
using namespace std;
int minKey(int v[],int key[],int n)
{
    int min=INT_MAX,idx;
    for(int i=0;i<n;i++)
    {
        if(v[i]!=1&&key[i]<min)
        {
            min=key[i];
            idx=i;
        }
    }
    return idx;
}
int main()
{
    int n,e;
    cout<<"Enter number of vertices and edges\n";
    cin>>n>>e;
    int graph[n][n];
    cout<<"Enter all edges and weight\n";
    for(int i=0;i<e;i++)
    {
        int v1,v2,w;
        cin>>v1>>v2>>w;
        graph[v1][v2]=w;
        graph[v2][v1]=w;
    } 
    int visited[n],key[n];
    for(int i=1;i<n;i++)
        key[i]=INT_MAX;
    key[0]=0;
    for(int count=0;count<n;count++)
    {
        int u=minKey(visited,key,n);
        cout<<"min is"<<u<<"\n";
        visited[u]=1;
        for(int v=0;v<n;v++)
        {
            if(graph[u][v]>0&&visited[v]!=1&&(key[u]+graph[u][v]<key[v]))
            {
                key[v]=key[u]+graph[u][v];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<"\t"<<key[i]<<"\n";
    }
    return 0;
}