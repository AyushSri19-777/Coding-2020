#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class node
{
    int r,c,v;
    node *next;
public:
    void input();
    node *attach(node *,int,int,int);
    node *delpart(node*,int,int,int);
    void display(node *);
};

node *node::attach(node *start,int rw,int cl,int val)
{
    node *temp=new node;
    node *cur=start;
    temp->r=rw;
    temp->c=cl;
    temp->v=val;
    if(start==NULL)
    {
        start=temp;
        return start;
    }
    while(cur->next!=NULL)
        cur=cur->next;
    cur->next=temp;
    temp->next=NULL;
    return start;
}
void node::input()
{
    int rw,cl,i,j,val,k=0;
    node *start=NULL;
    cout<<"Enter the row and column of a matrix: ";
    cin>>rw>>cl;
    cout<<"\nEnter the matrix elements: ";
    for(i=0;i<rw;i++)
    {
        for(j=0;j<cl;j++)
        {
            cin>>val;
            if(val!=0)
            {
                start=attach(start,i,j,val);
                k++;
            }
        }
    }
    cout<<"Row\tColumn\tValue\n";
    cout<<rw<<"\t"<<cl<<"\t"<<k<<"\n";
    display(start);
    node *cur=start;
    while(cur->next!=NULL&&cur->r!=cur->c)
    {
       cur=cur->next;
    }
    start=delpart(start,cur->r,cur->c,cur->v);
    cout<<"Row\tColumn\tValue\n";
    cout<<rw<<"\t"<<cl<<"\t"<<k<<"\n";
    display(start);
}
void node::display(node *start)
{
    node *cur=start;
    while(cur!=NULL)
    {
        cout<<cur->r<<"\t"<<cur->c<<"\t"<<cur->v<<"\n";
        cur=cur->next;
    }
}
node *node::delpart(node *start,int rw,int cl,int vl)
{
    int data;
    node *cur,*prev,*temp;
    if(start==NULL)
        cout<<"Nothing to delete..";
    else
    {
        data=vl;
        cur=start;
        while((cur!=NULL)&&(cur->v!=data))
        {
            prev=cur;
            cur=cur->next;
        }
        if(cur==start)
        {
            start=start->next;
            cout<<"Deleted element: "<<data<<"\n";
        }
        else if(cur==NULL)
        {
            cout<<"Nothing to delete..";
            return start;
        }
        else
        {
            prev->next=cur->next;
            cout<<"Deleted element: "<<data;
            return start;
        }
        delete cur;
    }
}
int main()
{
    node n;
    n.input();
    return 0;
}
