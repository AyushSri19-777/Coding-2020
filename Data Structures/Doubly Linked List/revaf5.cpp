#include <iostream>
#include <stdio.h>
using namespace std;
class node
{
    public:
    int info;
    node *next;
public:
    node *insend(node *);
    node *rev(node *);
    void display(node *);

};
node *node::insend(node *start)
{
    node *cur=start;
    node *temp=new node;
    cout<<"Enter an element: ";
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
    return start;
}
node *node::rev(node *start)
{
    node *cur=start,*nextnode;
    start=NULL;
    while(cur!=NULL)
    {
        nextnode=cur->next;
        cur->next=start;
        start=cur;
        cur=nextnode;
    }
    return start;
}
void node::display(node *start)
{
    node *cur=start;
    while(cur!=NULL)
    {
        cout<<cur->info<<" ";
        cur=cur->next;
    }
}
int main()
{
    node n,*start=NULL,*p=NULL;
    node *cur;
    int ch,c=1;
    for(;;)
    {
        cout<<"\nEnter\n1.Insert\n2.Rev5: ";
        cin>>ch;
        switch(ch)
        {
            case 1:start=n.insend(start);
                   cur=start;
                   break;
            case 2:while(c!=5)
                  {
                      c++;
                      cur=cur->next;
                   }
                   cout<<"cur->info: "<<cur->info;
                   p=cur->next;
                   cur->next=NULL;
                   p=n.rev(p);
                   cur->next=p;
                   break;
            case 3:n.display(start);
                   break;
        }
    }
}
