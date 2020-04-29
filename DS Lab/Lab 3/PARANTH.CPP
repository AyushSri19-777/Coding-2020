#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#define max 30
class para
{
  int top;
  char s[max];
  public :
    void push(char);
    void pop();
    para()
    {
      top=-1;
    }
};
void para::push(char ele)
{
  if(top==max-1)
  cout<<"Overlow!";
  else
  s[++top]=ele;
}
void para::pop()
{
   if(top==-1)
   cout<<"Underflow";
   else
   cout<<s[top--];
}
int main()
{
   para ob;
   int f=1,i;
   char exp[max],k;
   cout<<"Enter the expression";
   gets(exp);
   for(i=0;exp[i]!='\0';i++)
   {
     char k=exp[i];
     if(k=='{'||k=='['||k=='(')
     ob.push(k);
     else if(k==')')
     {
	if(exp[ob.top]=='(')
	ob.pop();
	else
	{
	  f=0;
	  cout<<"Invalid Expression";
	}
     }
     else if(k=='}')
     {
	if(exp[ob.top]=='{')
	ob.pop();
	else
	{
	   f=0;
	   cout<<"Invalid expression";
	}
     }
     else if(k==']')
     {
       if(exp[ob.top]=='[')
       ob.pop();
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
   getch();
   return 0;
}