#include <iostream>
using namespace std;
void operate(long a,long b)
{
    long ar[100],br[100],cr[100],dr[100],er[100],fr[100],i=0,j=0,c1=0,c2=0,l=0;
    while(a!=0)
    {
        ar[i]=a%10;
        er[i]=a%10;
        a/=10;
        c1++;
        i++;
    }
    while(b!=0)
    {

        br[j]=b%10;
        fr[j]=b%10;
        b/=10;
        c2++;
        j++;
    }

       l=(c1>c2)?c1:c2;
    if(c1>c2)
    {
        for(i=c2;i!=c1;i++)
        {
            br[i]=0;
            fr[i]=0;
        }
    }
    else
    {
        for(i=c1;i!=c2;i++)
        {
            ar[i]=0;
            er[i]=0;
        }
    }

            for(i=(l);i<(l+1);i++)
            {
                ar[i]=0;
                br[i]=0;
                er[i]=0;
                fr[i]=0;
            }

                for(i=0;i<(l+1);i++)
    {
        if(ar[i]==0&&br[i]==0)
            cr[i]=0;
        else if((ar[i]==0&&br[i]==1)||(ar[i]==1&&br[i]==0))
            cr[i]=1;
        else if((ar[i]+br[i])>=2&&(ar[i]+br[i])==2)
        {
            cr[i]=0;
            ar[i+1]=ar[i+1]+1;
        }
        else if((ar[i]+br[i])>=2&&(ar[i]+br[i])==3)
        {
            cr[i]=1;
            ar[i+1]=ar[i+1]+1;
        }
    }
    cout<<"\nThe sum= ";
    for(i=l;i>=0;i--)
        cout<<cr[i];
        for(i=0;i<(l+1);i++)
        {
            if(er[i]==1&&fr[i]==1)
                dr[i]=0;
            else if(er[i]==0&&fr[i]==0)
                dr[i]=0;
            else if(er[i]==1&&fr[i]==0)
                dr[i]=1;
            else if(er[i]==0&&fr[i]==1)
            {
                dr[i]=1;
                er[i+1]=0;
            }
        }
         cout<<"\nThe difference= ";
    for(i=l;i>=0;i--)
        cout<<dr[i];
}
long binary(int n)
{
    if(n==0)
        return 0;
    else
        return binary(n/2)*10+n%2;

}

int main()
{
    int a,b;
    cout<<"Enter two decimal nos.\n";
    cin>>a>>b;
    long a1=binary(a);
    long b1=binary(b);
    cout<<"Binary equivalent of "<<a<<" = "<<a1;
    cout<<"\nBinary equivalent of "<<b<<" = "<<b1;
    operate(a1,b1);
    cout<<"\nSum= "<<(a+b);
    cout<<"\nDifference= "<<(a-b);
}

