#include <iostream>
#include <stdio.h>
#include <string.h>
#define maxe 30
using namespace std;
class evalu
{
    int top,s[maxe];
    char pfix[maxe];
public:
    void read();
    int operate(int,int,char);
    void res();
    void display();
    void push(int);
    int pop();
    int isEmpty();
};
void evalu::read()
{
    cout<<"Enter the prefix expression :";
    gets(pfix);
    //puts(pfix);
   // strrev(pfix);
}
int evalu::isEmpty()
{
    if(top==-1)
        return 1;
    return 0;
}
void evalu::push(int x)
{
    if(top==maxe-1)
        cout<<"Underflow!";
    else
        s[++top]=x;
}
int evalu::pop()
{
    if(top==-1)
      return -999;
    else
        return s[top--];
}
int evalu::operate(int a,int b,char c)
{
    switch(c)
    {
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
}
/*void eval::res()
{
    int i,op1,op2,res;char j;
    for(i=0;pfix[i]!='\0';i++)
    {
        j=pfix[i];
        cout<<j<<"  hoho ";
        if(j>=48&&j<=57)
        {
           push((int)(j-48));

        }
        else
            continue;
    }
    //for(j=0;j<=top;j++)
       // cout<<s[j]<<"he ";
    for(i=0;pfix[i]!='\0';i++)
    {
        switch(pfix[i])
        {
            case '+':
            case '-':
            case '*':
            case '/':op2=pop();
                     op1=pop();
                     res=operate(op1,op2,pfix[i]);
                     push(res);
                     break;
        }

    }

    res=pop();
        if(!isEmpty())
            cout<<"Invalid expression";
        else
            cout<<"The result is : "<<res;
}*/
void evalu::display()
{
    for(int i=0;i<=top;i++)
        cout<<s[i]<<" ";
}
void evalu::res()
{
    int i,op1,op2,res;
    for(i=0;pfix[i]!='\0';i++)
    {
        if(pfix[i]>=48&&pfix[i]<=57)
            push(pfix[i]-'0');
    }
    display();
}
int main()
{
    evalu obj;
    obj.read();
    obj.res();
    return 0;
}
