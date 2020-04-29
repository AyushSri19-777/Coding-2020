#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    char str[30],newstr[30][30];
    cout<<"Enter a sentence\n";
    gets(str);
    int i,j=0,k=0;
    for(i=0;i<=strlen(str);i++)
    {
        if(str[i]==' '&&str[i+1]!=' ')
        {
            newstr[k][j++]=str[i];
            if(str[i+1]==' ')
                k++;
        }
    }
    for(i=k;i>=0;i--)
        puts(newstr[i]);
        cout<<"\t";
    return 0;
}
