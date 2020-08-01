#include<bits/stdc++.h>
using namespace std;
int MAH(int arr[],int n)
{  
    stack<int>s;
    vector<int>right;
    vector<int>left;
    unordered_map<int,int>U;

    for(int i=0;i<n;i++)
    {
       // cin>>arr[i];
        U[arr[i]]=i;
    }
    //for NGR
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty()==true)
            right.push_back(n);
        else
        {
            while(s.top()>arr[i]&&s.empty()==false)
            {
                //cout<<arr[i]<<"ki"<<s.top()<<"uda\n";
                  s.pop();
            }
              
            if(s.empty()==true)
            {
                right.push_back(n);
            }
            else
            {
                //cout<<"hjhkn"<<arr[i]<<"nkn\n";
                right.push_back(U[s.top()]);
            }            
        }
        s.push(arr[i]);        
    }
    reverse(right.begin(),right.end());
    // for(int i=0;i<right.size();i++)
    //     cout<<right[i]<<"\t";
    //creating NGL
    while(s.empty()!=true)
        s.pop();
    for(int i=0;i<n;i++)
    {
        if(s.empty()==true)
            left.push_back(-1);
        else
        {
            while(s.top()>arr[i]&&s.empty()==false)
            {
                //cout<<arr[i]<<"ki"<<s.top()<<"uda\n";
                  s.pop();
            }
              
            if(s.empty()==true)
            {
                left.push_back(-1);
            }
            else
            {
                //cout<<"hjhkn"<<arr[i]<<"nkn\n";
                left.push_back(U[s.top()]);
            }            
        }
        s.push(arr[i]);        
    }
    int maxi=0;
    // cout<<"\nLeft\n";
    // for(int i=0;i<left.size();i++)
    //     cout<<left[i]<<"\t";
    int area[n];
    for(int i=0;i<n;i++)
    {
        area[i]=arr[i]*(right[i]-left[i]-1);
        maxi=max(area[i],maxi);
    }
    return maxi;
}
int main()
{
    int n,m,maxi=0,ans,k=0;
    cout<<"Enter the size of matrix\n";
    cin>>m>>n;
    int arr[m][n];
    cout<<"Enter matrix\n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int b[n];
    memset(b,0,sizeof(b));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0)
                b[k++]=0;
            else
                b[k++]+=arr[i][j];
        }
        k=0;
        ans=MAH(b,n);
        cout<<i<<" max area="<<ans<<"\n";
        for(int t=0;t<n;t++)
            cout<<b[t]<<"\t";
        maxi=max(maxi,ans);
    }
    cout<<"Maximum area= "<<maxi;
}
