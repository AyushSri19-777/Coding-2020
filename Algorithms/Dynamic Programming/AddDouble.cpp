/*
You are given a number N. You have to find the number of operations required to reach N from 0. You have 2 operations available:

Double the number
Add one to the number
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N.

Output:
For each test case, in a new line, print the minimum number of operations required to reach N from 0.

Constraints:
1<=T<=100
1<=N<=104

Example:
Input:
2
8
7
Input:
4
5

Explanation:
Testcase1:
Input  : N = 8
Output : 4
0 + 1 = 1, 1 + 1 = 2, 2 * 2 = 4, 4 * 2 = 8
Testcase2:
Input  : N = 7
Output : 5
0 + 1 = 1, 1 + 1 = 2, 1 + 2 = 3, 3 * 2 = 6, 6 + 1 = 7
Link- https://practice.geeksforgeeks.org/problems/find-optimum-operation/0/
*/
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int t[10001];
int minSteps(int n,int h)
{
    if(h>n)
        return t[h]=INT_MAX;
    if(h==n)
        return t[h]=0;
    if(t[h]!=-1)
        return t[h];
    return t[h]=1+min(minSteps(n,h+1),minSteps(n,h*2));
}
int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int n;
        cin>>n;
        memset(t,-1,sizeof(t));
        cout<<"Min steps= "<<2+minSteps(n,2);
    }
}