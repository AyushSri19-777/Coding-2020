#include<bits/stdc++.h>
#define C 5
using namespace std;
class rot
{
    public:
    int time,x,y;
};
int main()
{
    cout<<"Enter the matrix dimentions";
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    cout<<"Enter matrix\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    queue<rot>Q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==2)
            {
                rot temp;
                temp.time=0;
                temp.x=i;
                temp.y=j;
                Q.push(temp);
            }
        }
    }
    rot temp;
    while(Q.empty()!=true)
    {
        temp=Q.front();
        rot temp2;
        cout<<temp.time<<"\t"<<temp.x<<"\t"<<temp.y<<"\n";
        if(temp.x<n&&arr[temp.x+1][temp.y]==1)
        {
            arr[temp.x+1][temp.y]=2;
            temp2.x=temp.x+1;
            temp2.y=temp.y;
            temp2.time=temp.time+1;
            Q.push(temp2);
        }
        if(temp.x-1>=0&&arr[temp.x-1][temp.y]==1)
        {
            arr[temp.x-1][temp.y]=2;
            temp2.x=temp.x-1;
            temp2.y=temp.y;
            temp2.time=temp.time+1;
            Q.push(temp2);
        }
        if(temp.y+1<m&&arr[temp.x][temp.y+1]==1)
        {
            arr[temp.x][temp.y+1]=2;
            temp2.x=temp.x;
            temp2.y=temp.y+1;
            temp2.time=temp.time+1;
            Q.push(temp2);
        }
        if(temp.y-1>=0&&arr[temp.x][temp.y-1]==1)
        {
            arr[temp.x][temp.y-1]=2;
            temp2.x=temp.x;
            temp2.y=temp.y-1;
            temp2.time=temp.time+1;
            Q.push(temp2);
        }
        Q.pop();
    }
    int f=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==1)
            {
                f=1;
                break;
            }
        }
    }
    if(f==1)
        cout<<-1;
    else
    {
        cout<<temp.time;
    }
    
}