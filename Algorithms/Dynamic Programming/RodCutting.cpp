/*Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Input:
First line consists of T test cases. First line of every test case consists of n, denoting the size of array. Second line of every test case consists of price of ith length piece.

Output:
For each testcase, in a new line, print a single line output consists of maximum price obtained.

Constraints:
1 <= T <= 100
1 <= n <= 100
1 <= Ai <= 100

Example:
Input:
1
8
1 5 8 9 10 17 17 20
Output:
22
Link-https://practice.geeksforgeeks.org/problems/rod-cutting/0
*/
#include <iostream>
#include <climits>
#include <math.h>
using namespace std;
int unbound(int wt[],int val[],int n)
{
    int t[n+1][n+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0||j==0)
                t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(wt[i-1]<=j)
                t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
            else
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][n];
}
int main() {
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    int n;
	    cin>>n;
	    int length[n],price[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>price[i];
	        length[i]=i+1;
	    }
	    cout<<unbound(length,price,n)<<"\n";
	}
	return 0;
}