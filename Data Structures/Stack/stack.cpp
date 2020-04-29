#include <bits/stdc++.h>
using namespace std;
class stacky
{
    int s[20];
    int top;
public :
    void push();
    void pop();
    void display();
    stacky()
    {
        top=-1;
    }
};
void stacky::push()
{
    int ele;
    cout<<"Enter an element ";
    cin>>ele;
    if(top==19)
        cout<<"Overflow";
    else
        s[++top]=ele;
}
void stacky::pop()
{
    if(top==-1)
        cout<<"Underflow: ";
    else
        cout<<s[top--]<<"\n";
}
void stacky::display()
{
    for(int i=0;i<=top;i++)
        cout<<s[i]<<" ";
}
int main()
{
    stacky s;
    int ch;
    for(;;)
    {
    cout<<"\nEnter 1.Push 2.Pop 3.Display 4.Exit";
    cin>>ch;


    switch(ch)
    {
        case 1: s.push();
                break;
        case 2: s.pop();
                break;
        case 3: s.display();
                break;
        case 4: exit(0);
                break;
    }
    }
}
