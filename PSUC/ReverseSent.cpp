#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
    char sent[30],newstr[30][30];
    int i,j=0,n,k=0;
    cout<<"Enter a sentenc\n";
    gets(sent);
    n=strlen(sent);
    sent[n+1]=' ';
    n++;
    for(i=0;i<=n;i++)
    {
        if(sent[i]!=' ')
            newstr[k][j++]=sent[i];
        else
        {
            k++;
            j=0;
        }
    }
    for(i=k;i>=0;i--)
        puts(newstr[i]);
    return 0;
}
