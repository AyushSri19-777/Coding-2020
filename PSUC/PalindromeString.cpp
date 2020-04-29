#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
    char str[30];
    int f=0;
    cout<<"Enter a sentence\n";
    gets(str);
    int n=strlen(str);
    for(int i=0;i<=n/2;i++)
    {
        if(str[i]!=str[n-i-1])
            f=1;
    }
    if(f==1)
    {
        puts(str);
        cout<<"Is not palindrome";
    }
    else
        {
        puts(str);
        cout<<"Is palindrome";
    }
    return 0;
}
