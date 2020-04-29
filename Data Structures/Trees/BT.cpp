#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
class node
{
    char info;
    node *lcl;
    node *rcl;
public:
    node *create(node *);
    void display(node *,int);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    void parent(node *,char);
   // void level_order(node *);
    int areMirror(node *,node *);
};
class queue
{
    public:
    int f,r;
    node *q[10];
public:
    void addq(node *);
    node *delq();
    queue()
    {
        f=r=-1;
    }
};
void queue::addq(node *x)
{
    q[++r]=x;
}
node *queue::delq()
{
    return q[++f];
}
class stack
{
public:
    int top;
    node *stk[10];
public:
    void push(node *);
    node *pop();
    stack()
    {
        top=-1;
    }
};
void stack::push(node *x)
{
    stk[++top]=x;
}
node *stack::pop()
{
    return stk[top--];
}
void node::inorder(node *root)
{
    stack s1;
    node *r=root;
    for(;;)
    {
        for(;r!=NULL;r=r->lcl)
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
    node *r=root;
    stack s1;
    for(;;)
    {
        for(;r!=NULL;r=r->lcl)
        {
            cout<<r->info<<" ";
            s1.push(r);
        }
        r=s1.pop();
        if(r==NULL)
            break;
        r=r->rcl;
    }
}
void node::parent(node *root,char data)
{
    stack s1;int f=1;
    node *r=root,*pr;
    for(;;)
    {
        pr=r;
        for(;r;r->lcl)
        {
           s1.push(r);
           pr=r;
        }
        r=s1.pop();
        if(!r)
        {
            f=0;
            break;
        }
        if(r->info==data)
        {
            cout<<"Parent: "<<pr->info;
            break;
        }
        pr=r;
        r=r->rcl;
    }
    if(f==0)
    cout<<"Parent not found";
}
/*void node::level_order(node *root)
{
    queue q1;
    node *r=root;
    if(!r)
      return;
    q1.addq(r);
    do{
        r=q1.delq();
        if(!r)
        {
            cout<<r->info;
            if(r->lcl)
                q1.addq(r->lcl);
            if(r->rcl)
                q1.addq(r->lcl);
        }
    }while(q1.f!=q1.r);
}
*/
void node::postorder(node *root)
{
    stack s1;
    node *r=root,*k;
    if(root==NULL)
      return;
    do{
        while(r!=NULL)
        {
            if(r->rcl!=NULL)
                s1.push(r->rcl);
            s1.push(r);
            r=r->lcl;
        }
        r=s1.pop();
        if(r->rcl!=NULL&&s1.stk[s1.top]==r->rcl)
        {
            k=s1.pop();
            s1.push(r);
            r=r->rcl;
        }
        else
        {
            cout<<r->info<<" ";
            r=NULL;
        }
    }while(s1.top!=-1);
}
int node::areMirror(node* a, node* b)
{
    /* Base case : Both empty */
    if (a==NULL && b==NULL)
        return true;

    // If only one is empty
    if (a==NULL || b == NULL)
        return false;

    /* Both non-empty, compare them recursively
     Note that in recursive calls, we pass left
     of one tree and right of other tree */
    return  a->info == b->info &&areMirror(a->lcl, b->rcl)&&areMirror(a->rcl, b->lcl);
}
node *node::create(node *root)
{
    char d[10];
    int i;
    node *cur=root,*par=NULL;
    node *temp=new node;
    temp->lcl=temp->rcl=NULL;
    cout<<"Enter the info";
    cin>>temp->info;
    if(root==NULL)
        return temp;
    cout<<"Direction";
    cin>>d;
    for(i=0;i<strlen(d);i++)
    {
        if(cur==NULL)
            break;
        par=cur;
        if(d[i]=='L')
            cur=cur->lcl;
        else if(d[i]=='R')
            cur=cur->rcl;
    }
    if(d[i-1]=='L')
        par->lcl=temp;
    else
        par->rcl=temp;
     return root;
}
void node::display(node *root,int level)
{
    if(root==NULL)
        return;
    display(root->rcl,level+1);
    for(int i=0;i<level;i++)
        cout<<"\t\t";
    cout<<root->info<<"\n";
    display(root->lcl,level+1);
}
int main()
{
    node n,*root=NULL,*r1=NULL,*r2=NULL;
    int ch;
    char k='Y';
    cout<<"First tree:";
    while(k!='N')
    {
        r1=n.create(r1);
        cin>>k;
    }
    k='Y';
    while(k!='N')
    {
         r2=n.create(r2);
         cin>>k;
    }
    for(;;)
    {
        cout<<"\nEnter \n1.Create \n2.Display \n3.Inorder \n4.Preorder \n5.Parent\n6.Postorder\n7.Level Order";
        cin>>ch;
        switch(ch)
        {
            case 1:root=n.create(root);
                   break;
            case 2:n.display(root,0);
                   break;
            case 3:n.inorder(root);
                   break;
            case 4:n.preorder(root);
                   break;
            case 5:n.parent(root,'B');
                   break;
            case 6:n.postorder(root);
                   break;
           // case 7:n.level_order(root);
                  // break;
            case 8:cout<<n.areMirror(r1,r2);
                   break;
        }
    }
    return 0;
}
