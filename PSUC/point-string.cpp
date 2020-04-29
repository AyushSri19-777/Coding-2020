#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    char str[30];
    int n,charac=0,wrd=0,sent=0,i;
    cout<<"Enter a text where each sentence is to be terminated by . ? or ! ";
    gets(str); char *cptr=str;
    n=strlen(str);
    str[n]=' ';
    str[n+1]='\0';
    for(i=0;i<strlen(str);i++)
    {
        if(*(cptr+i)!=' '&&*(cptr+i+1)==' ')
            wrd++;
        if(*(cptr+i)=='.'||*(cptr)=='!'||*(cptr+i)=='?')
            sent++;
        if(*(cptr+i)!=' '||*(cptr+i)!='.'||*(cptr+i)!='!'||*(cptr+i)!='?')
        charac++;
    }
    cout<<"Word :"<<++wrd;
    cout<<"\nSentences :"<<++sent;
    cout<<"\nCharacters :"<<charac;
}
