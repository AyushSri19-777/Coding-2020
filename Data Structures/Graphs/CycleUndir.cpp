#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
bool allvisit(int v[],int n)
{
    bool f=true;
    for(int i=0;i<n;i++)
    {
        if(v[i]==-1)
        {
            f=false;
            break;
        }
    }
    return f;
}
int getUnvisited(int v[],int n)
{
    int idx;
    for(int i=0;i<n;i++)
    {
        if(v[i]==-1)
        {
            idx=i;
            break;
        }
    }
    return idx;
}
int main()
{
    cout<<"Enter the no. of vertices and edges ";
    int n,e,f=0;
    cin>>n>>e;
    int arr[n][n],v[n];
    memset(arr,0,sizeof(arr));
    memset(v,-1,sizeof(v));
    cout<<"Enter the edges";
    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        arr[v1][v2]=arr[v2][v1]=1;
    }
    queue <int> q;
    int s=0;
    q.push(s);
    v[s]=0;
    while (q.empty()!=true||allvisit(v,n)==false)
    {
        if(allvisit(v,n)==false&&q.empty()==true)
        {
            s=getUnvisited(v,n);
            q.push(s);
        }
        else{
        s=q.front();
        q.pop();
        }
        cout<<s<<"\t";        
        v[s]=1;
        for(int i=0;i<n;i++)
        {
            if(arr[s][i]==1&&v[i]!=1)
            {
                if(v[i]==0)
                {
                    f=1;
                    break;
                }
                else
                {
                    q.push(i);
                    v[i]=0;
                }
            }
        }

    }
    if(f==1)
        cout<<"There is a cycle";
    else
    {
        cout<<"No cycle";
    }
    
    

}
