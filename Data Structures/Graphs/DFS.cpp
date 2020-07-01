#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main()
{
    cout<<"Enter the no. of vertices and edges\n";
    int n,e;
    cin>>n>>e;
    int arr[n][n],v[n];
    memset(arr,0,sizeof(arr));
    memset(v,0,sizeof(v));
    cout<<"Enter the edges\n";
    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        arr[v1][v2]=arr[v2][v1]=1;
    }
    int s=0;
    stack <int> stk;
    if(v[s]==0)
    {
        cout<<s<<"\t";
        stk.push(s);
        v[s]=1;
    }
    while(stk.empty()!=true)
    {
        int i,f=0;
        for(i=0;i<n;i++)
        {
            if(arr[s][i]==1&&v[i]!=1)
            {
                f=1;
                cout<<i<<"\t";
                stk.push(i);
                v[i]=1;
                break;
            }          
        }
        if(f==0){
            s=stk.top();
            stk.pop();  
        }
        else
        {
            s=i;
        }
    }

}