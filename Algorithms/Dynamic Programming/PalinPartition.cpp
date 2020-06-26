#include <iostream>
#include <climits>
using namespace std;
bool isPalin(string s,int i,int j)
{
    int f=0;
    for(int h=i;h<=j/2;h++)
    {
        if(s[h]!=s[j-h])
        {
            f=1;
            break;
        }
    }
    if(f==1)
        return false;
    return true;
}
int solve(string s,int i,int j)
{
    if(i>=j)
        return 0;
    if(isPalin(s,i,j)==true)
        return 0;
    int min=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=solve(s,i,k)+solve(s,k+1,j)+1;
        if(temp<min)
            min=temp;
    }
    return min;
}
int main()
{
    string s;
    cout<<"Enter a string to check palindrome partitions ";
    cin>>s;
    cout<<isPalin(s,0,s.length()-1);
    cout<<"The no. of palindrome partitions= "<<solve(s,0,s.length()-1);
}