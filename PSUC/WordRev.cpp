#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char *rev(char a[],int n)
{
    char temp,*ptr;int i;

    for(i=0;i<n/2;i++)
    {
        temp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;
    }
    ptr=a;
    return ptr;
}
int main()
{
    char str[30];
    cout<<"\nEnter a string\n";
    gets(str);
    cout<<"B4 change= ";
    puts(str);
    cout<<"After change= ";
    char *pt=rev(str,strlen(str));
    puts(pt);
    return 0;
}
