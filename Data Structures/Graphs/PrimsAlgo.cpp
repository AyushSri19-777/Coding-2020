#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int minKey(int mstSet[],int key[],int n)
{
    int min=INT_MAX,idx=0;
    for(int i=0;i<n;i++)
    {
        if(mstSet[i]!=1&&key[i]<min)
        {
            min=key[i];
            idx=i;
        }
    }
    return idx;
}
bool allone(int mstSet[],int n)
{
    int f=0;
    for(int i=0;i<n;i++)
    {
        if(mstSet[i]==0)
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
    int mstSet[n];
    int parent[n];
    int key[n];
    for(int i=1;i<n;i++)
        key[i]=14000;
    key[0]=0;
    int count=0;
    parent[0]=-1;
    for(int count=0;count<n-1;count++)
    {
        int u=minKey(mstSet,key,n);
        cout<<key[u]<<"heloooo";
        mstSet[u]=1;
        for(int v=0;v<n;v++)
        {
            if(graph[u][v]>=0&&mstSet[v]!=1&&graph[u][v]<key[v])
            {
                key[v]=graph[u][v];
                parent[v]=u;
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cout<<key[i]<<"\t";
        sum+=key[i];
    }
    cout<<"The min cost is= "<<sum;
}