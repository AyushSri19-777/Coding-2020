#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int main()
{
    cout<<"Enter the no. of vertices and edges ";
    int n,e;
    cin>>n>>e;
    int arr[n][n],v[n];
    memset(arr,0,sizeof(arr));
    memset(v,0,sizeof(v));
    cout<<"Enter the edges";
    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        arr[v1][v2]=arr[v2][v1]=1;
    }
    int s=0;
    queue <int> q;
    if(v[s]==0)  
    {  
        q.push(s);
        v[s]=1;
    }
    while(q.empty()!=true)
    {
        for(int i=0;i<n;i++)
        {
            if(arr[s][i]==1&& v[i]!=1)
            {
                q.push(i);
                v[i]=1;
            }
        }
        s=q.front();
        cout<<s<<"\t";
        q.pop();
    }
}