#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int t[501][501];
bool isPalin(string s,int i,int j)
{
    if(i>=j)
        return true;
    while(i<j)
    {
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int solve(string s,int i,int j)
{
    if(i>=j)
        return 0;
    if(isPalin(s,i,j)==true)
        return 0;
    if(t[i][j]!=-1)
        return t[i][j];
    int min=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=solve(s,i,k)+solve(s,k+1,j)+1;
        if(temp<min)
            min=temp;
    }
    return t[i][j]=min;
}
int main()
{
    string s;
    cout<<"Enter a string to check palindrome partitions ";
    cin>>s;
    memset(t,-1,sizeof(t));
    cout<<isPalin(s,0,0);
    cout<<"The no. of palindrome partitions= "<<solve(s,0,s.length()-1);
}