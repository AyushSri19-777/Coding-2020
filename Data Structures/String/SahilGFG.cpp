/*Sahil is done with his internship and now it's time to attend Geeks Classes to enhance knowledge of Data Structures. However, to join this class, he has been given a task to complete. The task is to count the occurrences of "gfg" in the given string, and if he completes this task, he qualifies for Geeks Classes. But, Sahil is facing some problem in solving this task, so help him.

Input :
First line of input contains "T" testcases. Next "T" lines contains Strings with lowercase characters.

Output :
For each testcase, output the count the ccurrences of "gfg"(continuous) present in string.

Constraints :
1 <= T <= 10
1<= length_of_string <= 100

Example :
Input :
2
geefgfgksforgfgeeks
dsajslsdlsfgf
Output :
2
-1
Link-https://practice.geeksforgeeks.org/contest-problem/sahil-loves-gfg/0/
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