#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,i,j,W;
    cin>>N>>i>>j>>W;
    int A[N][N];
    for(int a=0;a<N;a++)
        for(int b=0;b<N;b++)
           cin>>A[a][b];
for(int a=0;a<N;a++)
    {
        for(int b=0;b<N;b++)
        {
            if((abs(a-i)==1&&A[a][b]==0)||(abs(b-i)==1&&A[a][b]==0)||(abs(b-j)==1&&A[a][b]==0))
                A[a][b]=W;
        }
    }
    A[i][j]=W;
    cout<<"Changed\n";
    for(int a=0;a<N;a++)
    {
        for(int b=0;b<N;b++)
           cout<<A[a][b];
           cout<<"\n";
    }

           return 0;
}
