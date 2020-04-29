#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    char str[100];
    cout<<"Enter a string\n";
    gets(str);
    int i,j=0,c=0,k;
    char a,b;
    str[strlen(str)]=' ';
    str[strlen(str)+1]='\0';
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]==' '&&str[i+1]!=' ')
        {
            if((i-j)==4)
            {
                c++;
                a=str[j];
                str[j]=str[i-1];
                str[i-1]=a;
                b=str[j+1];
                str[j+1]=str[i-2];
                str[i-2]=b;
            }

                j=i+1;
        }

    }

    cout<<"No. of words 4 lettered = "<<c;
    cout<<"\nNew string = ";
    for(j=0;j<i;j++)
        cout<<str[j];
}
