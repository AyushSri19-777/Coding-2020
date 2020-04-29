#include <iostream>
#include <stdio.h>
#include <conio.h>
#define maxe 30
using namespace std;
class para
{
  int top;
  char s[maxe];
  public :
    void push(char);
    void pop();
    void check(char *);
    para()
    {
      top=-1;
    }
};
void para::push(char ele)
{
  if(top==maxe-1)
  cout<<"Overlow!";
  else
  s[++top]=ele;
}
void para::pop()
{
   if(top==-1)
   cout<<"Underflow";
   else
   top--;
}

void para::check(char exp[])
{
   int i,f=1;
   for(i=0;exp[i]!='\0';i++)
   {
     char k=exp[i];
     if(k=='{'||k=='['||k=='(')
      push(k);
     else if(k==')')
     {
	   if(s[top]=='(')
	   pop();
	   else
       {
	     f=0;
	     cout<<"Invalid Expression";
	     break;
	   }
     }
     else if(k=='}')
     {
	   if(s[top]=='{')
	   pop();
	   else
	   {
	     f=0;
	     cout<<"Invalid expression";
	     break;
	   }
     }
     else if(k==']')
     {
       if(s[top]=='[')
       pop();
       else
       {
	     f=0;
	     cout<<"Invalid expression";
       }
     }
     else
     continue;
  }
   if(f==1)
   cout<<"Valid Expression";
}
int main()
{
   para ob;
   char exp[maxe],k;
   cout<<"Enter the expression  ";
   gets(exp);
   ob.check(exp);
   return 0;
}
