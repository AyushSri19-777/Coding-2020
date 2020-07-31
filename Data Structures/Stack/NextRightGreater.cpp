#include<iostream>
#include <stack>
#include<vector>
#include <algorithm>
using namespace std;
int main()
{
    cout<<"Enter the number of elements\n";
    int n;
    cin>>n;
    stack<int>s;
    vector<int>ans;
    int arr[n];
    cout<<"Enter array elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty()==true)
            ans.push_back(-1);
        else
        {
            while(arr[i]>=s.top())
            {
                s.pop();
            }
            ans.push_back(s.top());
        }
        s.push(arr[i]);        
    }
    cout<<"Solution array\n";
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<ans.at(i)<<"\t";
}