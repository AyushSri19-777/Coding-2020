#include <iostream>
#include <stdio.h>
#include <conio.h>
#define max 30
using namespace std;
class palin_s
{
   char st[max];
   int top;
   public:
     void push(char[]);
     char pop();
    palin_s()
     { top=-1;}

};
void palin_s::push(char pst[])
{
      if(pst[top]=='\0')
       cout<<"Overflow! ";
      else
      {
       ++top;
      st[top]=pst[top];
      }
}
char palin_s::pop()
{
    if(top==-1)
     return 0;
    else
     return st[top--];
}
int main()
{
    char nm[max],c;
   int f=0,i;
   palin_s s;
   cout<<"Enter the string ";
   gets(nm);
   for(i=0;nm[i]!='\0';i++)
      s.push(nm);
   for(i=0;nm[i]!='\0';i++)
   {
      c=s.pop();
      if(c==nm[i])
      f=1;
      else
      f=0;
   }
   if(f==1)
   cout<<"The string is palindrome ";
   else
   cout<<"The string is not palindrome";
   getch();
   return 0;
}





