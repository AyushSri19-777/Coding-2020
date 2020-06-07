/*
Given weights and values related to n items and the maximum capacity allowed for these items. What is the maximum value we can achieve if we can pick any weights any number of times for a total allowed weight of W?

Input:
The first line of input contains an integer denoting the number of test cases. Then T test cases follow . Each test case contains two integers N and W denoting the number of items and the total allowed weight. In the next two lines are space separated values of the array denoting values of the items (val[]) and their weights (wt[]) respectively.

Output:
For each test case, in a new line, print the  maximum value which we can achieve if we can pick any weights any number of times for a bag of size W.

Constraints:
1 <= T <= 100
1 <= N, W <= 103
1 <= wt[], val[] <= 100

Example:
Input:
2
2 3
1 1
2 1 
4 8
1 4 5 7
1 3 4 5
Output:
3
11
Link- https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0
*/
#include <iostream>
using namespace std;

int knapsack(int wt[],int val[],int n,int W)
{
    int t[n+1][W+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0||j==0)
                t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            if(wt[i-1]<=j)
                t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
            else
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][W];
}
int main() {
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int n,W;
        cin>>n>>W;
        int wt[n],val[n];
        for(int i=0;i<n;i++)
            cin>>val[i];
        for(int i=0;i<n;i++)
            cin>>wt[i];
        cout<<knapsack(wt,val,n,W)<<"\n";
            
    }	
	return 0;
}