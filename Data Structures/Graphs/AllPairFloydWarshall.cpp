#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cout<<"Enter the number of vertices and edges\n";
    cin>>n>>e;
    int d[n][n],graph[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                d[i][j]=0;
            else
            {
                d[i][j]=1400000;
            }            
        }
    }
    cout<<"Enter the edges and weights\n ";
    for(int i=0;i<e;i++)
    {
        int v1,v2,w;
        cin>>v1>>v2>>w;
        d[v1][v2]=w;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(d[i][k]+d[k][j]<d[i][j])
                    d[i][j]=d[i][k]+d[k][j];
            }
        }
    }
    cout<<"The all pair shortest path\n";
    for(int i=0;i<n;i++)
        cout<<"\t"<<i;
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<i<<"\t";
        for(int j=0;j<n;j++)
        {
            if(d[i][j]==1400000)
                cout<<"INF\t";
            else
            {
                cout<<d[i][j]<<"\t";
            }
            
        }
        cout<<"\n";
    }

}
