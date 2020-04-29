#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class dnode
{
    int info;
    dnode *next,*prev;
public:
    dnode *insBef(dnode *);
    dnode *insAfter(dnode *);
    dnode *Delem(dnode *);
    void TravDis(dnode *);
    dnode *rev(dnode *);
};
dnode *dnode::insBef(dnode *start)
{
    dnode *temp=new dnode;
    dnode *cur=start;
    temp->next=temp->prev=NULL;
    int data;
    cout<<"Enter the element before which you want to insert the element";
    cin>>data;
    cout<<"Enter the element to be inserted";
    cin>>temp->info;
    if(start==NULL)
    {
        start=temp;
        return start;
    }
    if(cur->info==data)
    {
        temp->next=start;
        start->prev=temp;
        start=start->prev;
        return start;
    }
    while(cur->info!=data)
      cur=cur->next;
    (cur->prev)->next=temp;
    temp->prev=cur->prev;
    (cur->next)->prev=temp;
    temp->next=cur->next;
    return start;
}
dnode *dnode::insAfter(dnode *start)
{
    dnode *temp=new dnode;
    dnode *cur=start;
    temp->next=temp->prev=NULL;
    int data;
    cout<<"Enter the element after which you want to insert the element";
    cin>>data;
    cout<<"Enter the element to be inserted";
    cin>>temp->info;
    if(start==NULL)
    {
        start=temp;
        return start;
    }
    if(cur->info==data)
    {
        cur->next=temp;
        temp->prev=cur;
        return start;
    }
    while(cur->next!=NULL&&cur->info!=data)
      cur=cur->next;
    if(cur->next!=NULL)
    {
        temp->next=cur->next;
        (cur->next)->prev=temp;
        cur->next=temp;
        temp->prev=cur;
        return start;
    }
    else if(cur->next==NULL&&cur->info==data)
    {
        cur->next=temp;
        temp->prev=cur;
        temp->next=NULL;
        return start;
    }
    else
        cout<<"Data not present!";
    return start;
}
dnode *dnode::Delem(dnode *start)
{
    int data;
    dnode *cur=start;
    cout<<"Enter the element to be deleted";
    cin>>data;
    if(start==NULL)
    {
        cout<<"Cannot delete,list is empty!";
        return NULL;
    }
    if(cur->info==data)
    {
       delete cur;
       start=NULL;
       return NULL;
    }
    while(cur->next!=NULL&&cur->info!=data)
        cur=cur->next;
    cout<<"The info: "<<cur->info;
    (cur->next)->prev=cur->prev;
    (cur->prev)->next=cur->next;
    delete cur;
    return start;
}
void dnode::TravDis(dnode *start)
{
    dnode *cur=start;
    cur->prev=NULL;
    while(cur->next!=NULL)
    {
        cout<<cur->info<<"\t";
        cur=cur->next;
    }
    cout<<cur->info;
}
dnode *dnode::rev(dnode *start)
{
    dnode *a,*b,*c;
    a=NULL;
    b=start;
    c=start->next;
    //start->p
    while(c!=NULL)
    {
        b->next=a;
        b->prev=c;
        a=b;
        b=c;
        c=c->next;
    }
    b->prev=c;
    b->next=a;
    return b;
}
int main()
{
    dnode d,*start=NULL;
    int ch;
    for(;;)
    {
        cout<<"\nEnter\n1.Insert Before\n2.Insert After\n3.Delete an element\n4.Traverse/Display\n5.Reverse the list";
        cin>>ch;
        switch(ch)
        {
            case 1:start=d.insBef(start);
                   break;
            case 2:start=d.insAfter(start);
                   break;
            case 3:start=d.Delem(start);
                   break;
            case 4:d.TravDis(start);
                   break;
            case 5:start=d.rev(start);
                   break;
        }
    }
    return 0;
}

