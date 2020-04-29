#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
    char str[30];
    cout<<"Enter a sentence\n";
    gets(str);
    for(int i=0;i<=strlen(str);i++)
    {
        if(str[i]>=65&&str[i]<=90)
            str[i]+=32;
        else if(str[i]>=97&&str[i]<=122)
            str[i]-=32;
    }
    cout<<"String after toggle case :\n";
    puts(str);
    return 0;
}
