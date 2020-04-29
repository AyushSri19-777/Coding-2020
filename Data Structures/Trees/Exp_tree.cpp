#include <iostream>
#include <string.h>
#include <stdio.h>
#define max 30
using namespace std;

class node
{
public:
    char info;
    node *lcl,*rcl;
public:
    void display(node *,int);
    node *createbtin(node *,char *);
    int eval(node *);
};
class stk
{
    public:
    int top;
    node *st[max];
public:
    void push(node *x);
    node* pop();
    int toInt(char);
    stk()
    {
        top=-1;
    }
};
void stk::push(node *x)
{
    if(top==max-1)
        cout<<"Overflow!";
    else
        st[++top]=x;
}
int stk::toInt(char x)
{
    return x-'0';
}
node *stk::pop()
{
    if(top==-1)
        return NULL;
    else
        return st[top--];
}
node *node::createbtin(node *root,char pfix[])
{
    stk s1;
   // node *op1;
    for(int i=0;i<strlen(pfix);i++)
    {
        char ch=pfix[i];
        node* temp=new node;
        temp->lcl=temp->rcl=NULL;
        temp->info=ch;
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        {
            temp->rcl=s1.pop();
            temp->lcl=s1.pop();
            s1.push(temp);
        }
        else
        {
            s1.push(temp);
           // cout<<s1.st[s1.top]->info<<"hi:";
        }

    }
    root=s1.pop();
    return root;
}
int node::eval(node *root)
{
    stk s1;
    if(root->lcl&&root->rcl)
    {
        int l=s1.toInt(eval(root->lcl));
        int r=s1.toInt(eval(root->rcl));
        switch(root->info)
        {
            case '+':return l+r;
            case '-':return l-r;
            case '*':return l*r;
            case '/':return l/r;
        }
    }
    else
        return root->info;
}
void node::display(node *root,int level)
{
    int i;
    if(root==NULL)
        return;
    display(root->rcl,level+1);
    for(i=0;i<level;i++)
        cout<<"\t\t";
    cout<<root->info<<"\n";
    display(root->lcl,level+1);
}
int main()
{
    char str[30];
    cout<<"Enter the postfix expression";
    gets(str);
    node p,*root=NULL;
    root=p.createbtin(root,str);
    p.display(root,0);
    cout<<p.eval(root)-'0';
}
