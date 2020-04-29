#include <iostream>
#define max 30
using namespace std;
class fastack
{
    int s[max],top;
public:
    int isEmpty();
    void push(int);
    int pop();
    int fact(int);
    int comb(int,int);
    int perm(int, int);
    fastack()
    {
        top=-1;
    }
};
void fastack::push(int x)
{
    if(top==max-1)
        cout<<"Overflow!";
    else
        s[++top]=x;
}
int fastack::pop()
{
    if(top==-1)
        return -999;
    else
        return s[top--];
}
int fastack::isEmpty()
{
    if(top==-1)
        return 1;
    return 0;
}
int fastack::fact(int n)
{
    int f=1,a=0;
    while(n>0)
    {
        push(n);
        n--;
    }
    while(!isEmpty())
    {
        a=pop();
        if(a!=-999)
        f=f*a;
    }
    return f;
}
int fastack::comb(int n,int r)
{
    return (fact(n)/(fact(n-r)*fact(r)));
}
int fastack::perm(int n,int r)
{
    return (fact(n)/fact(n-r));
}
int main()
{
    fastack ob;
    cout<<"Enter n and r ";
    int n,r;
    cin>>n>>r;
    cout<<"\nn= "<<n;
    cout<<"\nr= "<<r;
    cout<<"\nnCr= "<<ob.comb(n,r);
    cout<<"\nnPr= "<<ob.perm(n,r);
    return 0;
}
