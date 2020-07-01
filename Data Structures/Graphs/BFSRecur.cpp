#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
void BFS(int **arr,int s,int v[],int n)
{
    if(v[s]==0){
    cout<<s<<"\t";
    v[s]=1;}
    for(int i=0;i<n;i++)
    {
        if(arr[s][i]==1&&v[i]!=1)
        {
            cout<<i<<"\t";
            v[i]=1;
         }
    }
    for(int i=0;i<n;i++)
        if(v[i]==1&&i!=s)
            BFS(arr,i,v,n);       
}
int main()
{
    cout<<"Enter the no. of vertices and edges\n ";
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
    cout<<"Enter the edges\n";
    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        arr[v1][v2]=arr[v2][v1]=1;
    }
    BFS(arr,0,v,n);
}