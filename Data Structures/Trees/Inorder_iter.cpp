#include <iostream>
#include <string.h>
#define max 30
using namespace std;

class node
{
    char info;
    node *lcl,*rcl;
public:
    void inorder(node *);
    void preorder(node *);
    void display(node *,int);
    void leaf(node *);
    node *createbt(node *);
};
class stk
{
    public:
    int top;
    node *st[max];
public:
    void push(node *x);
    node* pop();
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
node *stk::pop()
{
    if(top==-1)
        return NULL;
    else
        return st[top--];
}
void node::inorder(node *root)
{
    stk s1;
    node *r=root;
    for(;;)
    {
        for(;r;r=r->lcl)
            s1.push(r);
        r=s1.pop();
        if(!r)
            break;
        cout<<r->info<<" ";
        r=r->rcl;
    }
}
void node::preorder(node *root)
{
    stk s1;
    node *r=root;
    for(;;)
    {

        for(;r;r=r->lcl)
        {
            cout<<r->info;
            s1.push(r);
        }
        r=s1.pop();
        if(!r)
            break;
        //cout<<r->info<<" ";
        r=r->rcl;
    }
}
node *node::createbt(node *root)
{
    node *temp,*prev,*cur;
    char d[10];
    int i,item;
    temp=new node;
    cout<<"\nElement\n";
    cin>>temp->info;
    temp->lcl=temp->rcl=NULL;
    if(root==NULL)
        return temp;
    cout<<"\nDirection";
    cin>>d;
    prev=NULL;
    cur=root;
    for(i=0;i<strlen(d);i++)
    {
        if(cur==NULL)
            break;
        prev=cur;
        if(d[i]=='L')
            cur=cur->lcl;
        else
            cur=cur->rcl;
    }
    if(cur!=NULL||i!=strlen(d))
    {
        cout<<"Impossible!";
        delete temp;
        return root;
    }
    if(d[i-1]=='L')
        prev->lcl=temp;
    else
        prev->rcl=temp;
    return root;
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
void node::leaf(node *root)
{
    stk s1;
    node *r=root;
    int c=0;
    for(;;)
    {
        for(;r;r->lcl)
            s1.push(r);
        r=s1.pop();
        if(!(r->rcl)&&!(r->lcl))
            c++;
        if(!(r->rcl)&&s1.top==-1)
        break;
        r=r->rcl;
    }
    cout<<"Leaf nodes= "<<c;
}
int main()
{
    node p,*root=NULL;
    int ch;
    for(;;)
    {
        cout<<"Enter\n1.Insert\n2.Display\n3.Inorder";
        cin>>ch;
        switch(ch)
        {
             case 1:root=p.createbt(root);
                    break;
             case 2:p.display(root,0);
                     break;
             case 3:p.inorder(root);
                    break;
             case 4:p.preorder(root);
                    break;
            case 5:p.leaf(root);
        }
    }

}
