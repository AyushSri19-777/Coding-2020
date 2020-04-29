#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
    char str[30],word[30];
    int i,j,f=0,k=0,temp;
    cout<<"Enter a string\n";
    gets(str);
    cout<<"\nEnter the word you want to delete\n";
    gets(word);
    for(i=0;i<strlen(str);i++)
    {
        if(word[0]==str[i])
        {
            for(j=i;j<=strlen(word);j++)
            {
                if(word[k++]==str[j])
                    f=1;
            }
            if(f==1)
                break;
        }
    }
    int w=strlen(word);
    for(k=i;k<=strlen(str);k++)
    {
        temp=str[k];
        str[k]=str[k+w];
        str[k+w]=temp;
    }
    str[k]='\0';
    cout<<"The changed string: ";
    for(i=0;i<strlen(str);i++)
        if(str[i]!=0)
        cout<<str[i];
}
