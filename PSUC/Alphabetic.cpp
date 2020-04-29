#include <bits/stdc++.h>
using namespace std;
int main()
{
    char string[30][30],temp[30];
    int no,i,j;
    cout<<"Enter the number of strings\n";
    cin>>no;
    for(i=0;i<=no;i++)
        gets(string[i]);
    for(i=0;i<=no-1;i++)
    {
        for(j=i+1;j<=no;j++)
        {
            if(strcmp(string[i],string[j])>0)
            {
                strcpy(temp,string[i]);
                strcpy(string[i],string[j]);
                strcpy(string[j],temp);
            }
        }
    }
    cout<<"The sorted array is :\n";
    for(i=0;i<=no;i++)
        puts(string[i]);
    return 0;
}
