/*Reverse a string using Stack 
An string of words is given, the task is to reverse the string using stack.

Input Format:
The first line of input will contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains a string s of words without spaces.

Output Format:
For each test case ,print the reverse of the string in new line. 

Your Task:
Since this is a function problem, you don't need to take any input. Just complete the provided function.

Constraints:
1 <= T <= 100
1 <= length of the string <= 100

Example:
Input:
2
GeeksQuiz
GeeksforGeeks
Output:
ziuQskeeG
skeeGrofskeeG
Link-https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1/?track=ppc-stack&batchId=221
*/
#include <bits/stdc++.h>
using namespace std;
int getHash(string s)
{
    int sum=0;
    unordered_map <char,int>U;
    for(int i=1;i<=26;i++)
    {
        U[char(i+96)]=i;
    }
    for(int i=0;i<s.length();i++)
    {
        sum+=U[s[i]]*pow(10,s.length()-i-1);
    }
    return sum;
}
int main() {
	int T;
	cin>>T;
	for(int h=0;h<T;h++)
	{
	    int count=0;
	    string s,w,p;
	    cin>>s;
	    p="gfg";
	    for(int i=0;i<s.length();i++)
	    {
	        w=s.substr(i,3);
	       if(getHash(w)==getHash(p))
	        count++;
	    }
	    if(count>0)
	        cout<<count<<"\n";
	   else
	    cout<<"-1\n";
	}
	return 0;
}