#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c;
    cout<<"Enter the number of days\n";
    cin>>n;
    int arr[n];
    vector<int>v;
    stack<int>s;
    unordered_map<int,int>U;
    cout<<"Enter stock prizes\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        U[arr[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        if(s.empty()==true)
            v.push_back(1);
        else
        {
            while(s.top()<arr[i])
            {
                s.pop();
            }
            if(s.empty()==true)
            {
                v.push_back(U[arr[i]]+1);
            }
            else
            {
                v.push_back(i-U[s.top()]);
            }            
        }
        s.push(arr[i]);
    }
    
    cout<<"Solution array\n";
    for(int i=0;i<v.size();i++)
        cout<<v.at(i)<<"\t";

}