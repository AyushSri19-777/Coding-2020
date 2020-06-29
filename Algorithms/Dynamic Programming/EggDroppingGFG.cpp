/*Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page

Input:
The first line of input is  T denoting the number of testcases.Then each of the T lines contains two positive integer N and K where 'N' is the number of eggs and 'K' is number of floor in building.

Output:
For each test case, print a single line containing one integer the minimum number of attempt you need in order find the critical floor.

Constraints:
1<=T<=30
1<=N<=10
1<=K<=50

Example:
Input:
2
2 10
3 5

Output:
4
3
Link- https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
*/
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int t[11][51];
int solve(int e,int f)
{
    if(e==1||f==0||f==1)
        return t[e][f]=f;
    if(t[e][f]!=-1)
        return t[e][f];
    int mn=INT_MAX;
    for(int k=1;k<=f;k++)
    {
        int temp=1+max(solve(e-1,k-1),solve(e,f-k));
        mn=min(temp,mn);
    }
    return t[e][f]=mn;
}
int main() {
	int T;
	cin>>T;
	for(int h=0;h<T;h++)
	{
	    int e,f;
	    cin>>e>>f;
	    memset(t,-1,sizeof(t));
	    cout<<solve(e,f)<<"\n";
	}
	return 0;
}