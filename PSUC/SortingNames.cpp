#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
    char str[30][30],temp[30];
    int n,i,j;
    cout<<"Enter the number of names\n";
    cin>>n;
    cout<<"Enter the names\n";
    for(i=0;i<=n;i++)
        gets(str[i]);
    for(i=0;i<=n-1;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(strcmp(str[i],str[j])>0)
            {
                strcpy(temp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],temp);
            }

        }
    }
    cout<<"Sorted Names:\n";
    for(i=0;i<=n;i++)
        puts(str[i]);
        return 0;
}
