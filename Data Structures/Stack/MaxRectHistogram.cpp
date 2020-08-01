#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no. of bars\n";
    cin>>n;
    int arr[n];
    stack<int>s;
    vector<int>right;
    vector<int>left;
    unordered_map<int,int>U;
    cout<<"Enter heights\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
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
    for(int i=0;i<right.size();i++)
        cout<<right[i]<<"\t";
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
    cout<<"\nLeft\n";
    for(int i=0;i<left.size();i++)
        cout<<left[i]<<"\t";
    int area[n];
    for(int i=0;i<n;i++)
    {
        area[i]=arr[i]*(right[i]-left[i]-1);
        maxi=max(area[i],maxi);
    }
    cout<<"Maximum area= "<<maxi;
}