#include <bits/stdc++.h>
#define maxe 20
using namespace std;
class mstack
{
    int ms[maxe];
    int t[maxe/2],b[maxe/2];
public :
    void createStack(int);
    void push(int);
    void pop(int);
    void display(int);
};
void mstack:: createStack(int n)
{
    int i;
        for(i=0;i<n;i++)
            t[i]=b[i]=(maxe/n)*i-1;
        b[i]=maxe-1;
}
void mstack::push(int n)
{
    int ele,i;
    for(i=1;i<=n;i++)
            cout<<i<<" ";
    cout<<"Enter the stack where you want to insert element";
    cin>>i;
    cout<<"Enter the element: ";
    cin>>ele;
    if(t[i-1]==b[i])
        cout<<"Overflow";
    else
       ms[++t[i-1]]=ele;
}
void mstack::pop(int n)
{
    int i;
    for(i=1;i<=n;i++)
            cout<<i<<" ";
    cout<<"Enter the stack whose element you want to delete";
    cin>>i;
    if(t[i-1]==b[i-1])
        cout<<"Underflow";
    else
        cout<<ms[t[i-1]--];
}
void mstack::display(int n)
{
    int i;
    for(i=1;i<=n;i++)
            cout<<i<<" ";
    cout<<"Enter the stack whose elements you want to display";
    cin>>i;
    if(t[i-1]==b[i-1])
    {
        cout<<"Underflow";
        return;
     }
    for(int k=b[i-1]+1;k<=t[i-1];k++)
        cout<<ms[k]<<" ";
    cout<<"\n";
}
int main()
{
    mstack ms;
      int ch,x;
    cout<<"Enter the number of stacks ";
        cin>>x;
          ms.createStack(x);
    while(1)
    {
        cout<<"\nEnter 1.Push 2.Pop 3.Display 4.Exit::";
        cin>>ch;
        switch(ch)
        {
        case 1: ms.push(x);
                break;
        case 2: ms.pop(x);
                break;
        case 3: ms.display(x);
                break;
        case 4: exit(0);
                break;
      }
   }
}
