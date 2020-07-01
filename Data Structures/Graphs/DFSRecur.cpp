#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
void DFS(int **arr,int s,int v[],int n)
{
    cout<<s<<"\t";
    v[s]=1;
    for(int i=0;i<n;i++)
    {
        if(arr[s][i]==1&&v[i]!=1)
            DFS(arr,i,v,n);
    }
}
int main()
{
    cout<<"Enter the no. of vertices and edges ";
    int n,e;
    cin>>n>>e;
    int **arr= new int*[n];int v[n];
   for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            arr[i][j]=0;
        }
    }
    memset(v,0,sizeof(v));
    cout<<"Enter the edges";
    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        arr[v1][v2]=arr[v2][v1]=1;
    }
    DFS(arr,0,v,n);
}