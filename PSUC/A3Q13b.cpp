#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int main()
{
    int c,b,i1=0,i2=0,i3=0,n;
    char str[30];
    cout<<"Input the string"<<endl;
    gets(str);
    n=strlen(str);
    for(int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            b=1;
            if(str[i]==str[j])
            {
                c=0;
                for(int k=i;k<=j;k++)
                {
                    if(str[k]!=str[j-c])
                    {
                        b=0;
                    }
                    c++;
                }
                if (b==1)
      {
                    if(i3<j-i)
                    {
                    i1=i;
                    i2=j;
                    i3=j-i;
                    }
                }
            }
        }
    }
    cout<<"Longest palindrome substring"<<endl;
    if (i3!=0)
    {
        for (int i=i1;i<=i2;i++)
        {
            cout<<str[i];
        }
        cout<<endl;
        cout<<"Length:"<<i3+1;
    }
    else
    {
        cout<<"No palindrome substring present";
    }
    return 0;   }
