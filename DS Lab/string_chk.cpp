#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    char s1[30],s2[30],s3[30],s4[30];
    int i,j,k,h=0,f=0,pos,l,t,c;
    cout<<"Enter 1st string ";
    gets(s1);
    cout<<"Enter 2nd string ";
    gets(s2);
    for(i=0;s1[i]!='\0';i++);
    cout<<"\nThe length is 1st string= "<<i<<" characters";
    for(j=0;s2[j]!='\0';j++);
    cout<<"\nThe length is 2nd string= "<<j<<" characters";
    for(k=i;k<=i+j;k++)
        s1[k]=s2[h++];
    cout<<"\nThe concatenated string= "<<s1;
    cout<<"\nThe strings after being compared= ";
    for(i=0;i<=k;i++)
    {
        if(s1[i]!=s2[i])
        {
            f=1;
            break;
        }
    }
    if(f==1)
    {
        h=((s1[i]-s2[i])>0)?1:-1;
        cout<<h;
    }
    else
        cout<<"0";
    cout<<"\nEnter the position -->";
    cin>>pos;
    pos--;
    cout<<"Enter the substring you want to insert in string 2 ";
    cin>>s3;
    for(k=0;s3[k]!='\0';k++);
    for(i=j+k-1;i>=pos+k+1;i--)
    {
        s2[i]=s2[i-k];
    }
    s2[j+k]='\0';
    h=0;
    f=0;
    for(j=pos+1;j<=i;j++)
    {
        s2[j]=s3[h++];
    }

    cout<<"\nThe modified string: \n";
    puts(s2);
    cout<<"Enter the substring you want to delete from string 2 ";
    cin>>s4;
    for(t=0;s4[t]!='\0';t++);
    for(i=0;s2[i]!='\0';i++)
    {
        if(s4[0]==s2[i])
        {
            l=i;
            c=0;
            k=0;h=l+t;
            while(l!=h)
            {
                if(s2[l++]==s4[k++])
                   c++;

            }
            if(c==t)
            {
                f=1;
                break;
            }

        }
    }
    if(f==1)
    {
        for(j=i;s2[j]!='\0';j++)
          s2[j]=s2[j+t];

    }
    s2[j]='\0';
    cout<<"The modified string :";
    puts(s2);
    return 0;

}
