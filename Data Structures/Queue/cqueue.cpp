#include <bits/stdc++.h>
#define maxe 5
using namespace std;
class cqueue
{
    int cq[maxe],f,r,c;
public:
    void addq();
    void delq();
    void display();
    cqueue()
    {
        f=r=-1;
        c=0;
    }
};
void cqueue::addq()
{
    int ele;
    cout<<"Enter the element";
    cin>>ele;
    if(r==maxe-1&&c==maxe)
        cout<<"Overflow!\n";
    else if(r<maxe-1)
    {
        cq[++r]=ele;
        c++;
        cout<<"Rear="<<r;
    }
    else if(c<maxe&&r==maxe-1)
    {
       // cout<<"Front ="<<f;
        r=0;
        cq[r++]=ele;
        c++;
    }

}
void cqueue::delq()
{
    if(f==r)
        cout<<"Underflow\n";
    else
    {
        cout<<cq[++f];
        c--;
    }

    cout<<"\n";
}
void cqueue::display()
{
    if(f<=r)
    {
       for(int i=f+1;i<=r;i++)
        cout<<cq[i]<<" ";
    }
    else{
       for(int i=r;i<=f;i++)
        cout<<cq[i]<<" "; }

    cout<<"\n";
}
int main()
{
    cqueue c;
    int ch;
    for(;;)
    {
    cout<<"\nEnter 1.Push 2.Pop 3.Display 4.Exit";
    cin>>ch;

    switch(ch)
    {
        case 1: c.addq();
                break;
        case 2: c.delq();
                break;
        case 3: c.display();
                break;
        case 4: exit(0);
                break;
    }
}
}

