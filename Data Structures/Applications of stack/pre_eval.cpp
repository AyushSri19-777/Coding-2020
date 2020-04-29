#include <iostream>
#include <stdio.h>
#include <string.h>
#define maxe 100
using namespace std;
class eval
{
    int top,s[maxe];
    char pfix[maxe];
public:
    void read();
    int operate(int,int,char);
    void reso();
    void push(int);
    int pop();
    int isEmpty();
    eval()
    {
        top=-1;
    }
};
void eval::read()
{
    cout<<"Enter the prefix expression :";
    gets(pfix);
    puts(pfix);
}
int eval::isEmpty()
{
    if(top==-1)
        return 1;
    return 0;
}
void eval::push(int x)
{
    if(top==maxe-1)
        cout<<"Underflow!";
    else
        s[++top]=x;
}
int eval::pop()
{
    if(top==-1)
      return -999;
    else
        return s[top--];
}
int eval::operate(int a,int b,char c)
{
    switch(c)
    {
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
}
void eval::reso()
{
    int i,op1,op2,len,res=0,j;
    len=strlen(pfix);
    for(i=len-1;i>=0;i--)
    {
        if(pfix[i]>48&&pfix[i]<=57)
        {
           push(pfix[i]-'0');
        }
        else
        {
            op1=pop();
            op2=pop();
            res=operate(op1,op2,pfix[i]);
            push(res);
        }
    }
    res=pop();
        if(!isEmpty())
            cout<<"Invalid expression";
        else
            cout<<"The result is : "<<res;
}
int main()
{
    eval e;
    e.read();
    e.reso();
    return 0;
}
