#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements\n";
    cin>>n;
    int arr[n];
    vector<int>ans;
    stack<int>s;
    cout<<"Enter th array elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        if(s.empty()==true)
            ans.push_back(-1);
        else
        {
            while(arr[i]>s.top())
                s.pop();
            if(s.empty()==true)
                 ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        s.push(arr[i]);
    }
    cout<<"Solution array\n";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<"\t";
}