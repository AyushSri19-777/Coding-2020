#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#define max 10
class stack
{

  int top,s[max];
  public:
    void push();
    void pop();
    void display();
    stack()
    {
     top=-1;
    }
 };
 void stack::push()
 {
    int ele;
    cout<<"Enter an element ";
    cin>>ele;
    if(top==max-1)
      cout<<"Overflow! ";
    else
      s[++top]=ele;
 }
 void stack::pop()
 {
    if(top==-1)
    cout<<"Underflow! ";
    else
    cout<<"The removed element "<<s[top--];
 }
 void stack:: display()
 {
    cout<<"The stack: ";
    for(int i=0;i<=top;i++)
    cout<<s[i]<<" ";
 }
 int main()
 {
    clrscr();
    stack s;
    int ch;
    for(;;)
    {
      cout<<"Press 1.Push  2.Pop  3.Display  4.Stop ";
      cin>>ch;
      switch(ch)
      {
	 case 1:s.push();
		break;
	 case 2:s.pop();
		break;
	 case 3:s.display();
		break;
	 case 4:exit(0);
		break;
      }
    }
      return 0;
 }