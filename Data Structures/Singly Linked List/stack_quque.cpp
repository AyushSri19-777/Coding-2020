#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class node
{
    int info;
    node *next;
public:
    node *push(node *start);
    node *pop(node *start);
    node *delq(node *start);
    void display(node *start);
};
node *node::push(node *start)
{
    node *cur=start;
    node *temp=new node;
    cout<<"Enter the element: ";
    cin>>temp->info;
    temp->next=NULL;
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
node *node::pop(node *start)
{
    if(start==NULL)
    {
        cout<<"Stack Underflow!";
        return NULL;
    }
    if(start->next==NULL)
    {
        delete start;
        return NULL;
    }
    node *cur=start;
    while((cur->next)->next!=NULL)
      cur=cur->next;
    delete cur->next;
    cur->next=NULL;
    return start;
}
node *node::delq(node *start)
{
    node *cur=start;
    if(start==NULL)
    {
        cout<<"Queue is empty!";
        return start;
    }

    else
    {
        start=start->next;
        delete cur;
        return start;
    }
}
void node::display(node *start)
{
    node *cur=start;
    while(cur!=NULL)
    {
        cout<<cur->info<<"\t";
        cur=cur->next;
    }
}
int main()
{
    node n,*start;
    int ch,ch1;
    cout<<"Enter \n1.Stack\n2.Queue";
    cin>>ch;
    switch(ch)
    {
        case 1:start=NULL;
               for(;;)
                {
               cout<<"\nEnter\n1.Push\n2.Pop\n3.Display\n4.Exit";
               cin>>ch1;
               switch(ch1)
               {
                   case 1:start=n.push(start);
                          break;
                   case 2:start=n.pop(start);
                          break;
                   case 3:n.display(start);
                          break;
                   case 4:exit(0);
                          break;
                 }
               }
               break;
        case 2:start=NULL;
               for(;;)
               {
                   cout<<"\nEnter\n1.Add element\n2.Delete Element\n3.Display\n4.Exit";
                    cin>>ch1;

               switch(ch1)
               {
                   case 1:start=n.push(start);
                          break;
                   case 2:start=n.delq(start);
                          break;
                   case 3:n.display(start);
                          break;
                   case 4:exit(0);
               }
               }
               break;
        default:cout<<"Wrong choice!";

    }
    return 0;
}
