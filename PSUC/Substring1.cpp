#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
    char str[30],word[30];
    int i,j,f=0,k=0;
    cout<<"Enter a string\n";
    gets(str);
    cout<<"\nEnter the substring you want to find\n";
    gets(word);
    cout<<"\n"<<strlen(word);
    for(i=0;i<strlen(str);i++)
    {
        if(word[0]==str[i])
        {
            for(j=i;j<=strlen(word);j++)
            {
                if(word[k++]==str[j])
                    f=1;
            }
        }
    }
    if(f==1)
        cout<<"\nThe given substring is there in string\n";
    else
        cout<<"\nThe given substring is not there in string\n";
}
