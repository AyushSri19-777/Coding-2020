#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int src,des,wt;
};
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
    Edge E[e];
    cout<<"Enter all edges and weight\n";
    for(int i=0;i<e;i++)
    {
        int v1,v2,w;
        cin>>v1>>v2>>w;
        graph[v1][v2]=w;
        E[i].src=v1;
        E[i].des=v2;
        E[i].wt=w;
        //graph[v2][v1]=w;
    } 
    int visited[n],key[n];
    memset(visited,0,sizeof(visited));
    for(int i=1;i<n;i++)
        key[i]=INT_MAX;
    key[0]=0;
    for(int b=0;b<n-1;b++)
    {
        for(int j=0;j<e;j++)
        {
            int u=E[j].src;
            int v=E[j].des;
            if(key[u]+E[j].wt<key[v])
            {
                key[v]=key[u]+E[j].wt;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<"\t"<<key[i]<<"\n";
    }
    return 0;
}