#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class cdnode
{
    int info;
    cdnode *next,*prev;
public:
    cdnode *insAfter(cdnode *);
    cdnode *delpos(cdnode *);
    void display(cdnode *);
};
cdnode *cdnode::insAfter(cdnode *start)
{
    cdnode *temp=new cdnode;
    cdnode *cur=start;
    int data;
    cout<<"Enter the element after which you want to insert: ";
    cin>>data;
    cout<<"Enter the element ";
    cin>>temp->info;
    if(start==NULL)
    {
        start=temp;
        temp->next=start;
        temp->prev=start;
        return start;
    }
    if((start->next==start)&&(start->prev=start))
    {
        start->next=temp;
        temp->prev=start;
        temp->next=start;
        start->prev=temp;
        return start;
    }
    while(cur->info!=data&&cur->next!=start)
        cur=cur->next;
    if(cur->next!=start)
    {
    temp->next=(cur->next);
    (cur->next)->prev=temp;
    cur->next=temp;
    temp->prev=cur;
    }
    else if (cur->next==start)
    {
        cur->next=temp;
        temp->prev=cur;
        start->prev=temp;
        temp->next=start;
        return start;
    }
    else
    {
        cout<<"Element not found!";
        return start;
    }
}
void cdnode::display(cdnode *start)
{
    cdnode *cur=start;
    cur->prev=NULL;
    while(cur->next!=start)
    {
        cout<<cur->info<<"\t";
        cur=cur->next;
    }
    cout<<cur->info;
    cout<<"\nReversed List: ";
    while(cur->prev!=NULL)
    {
        cout<<cur->info<<"\t";
        cur=cur->prev;
    }
    cout<<cur->info;
}
cdnode *cdnode::delpos(cdnode *start)
{
    int data;
    cdnode *cur=start,*p=start->next;
    cout<<"Enter the the element to be deleted";
    cin>>data;
    if(start==NULL){
        cout<<"Nothing to delete";
        return start;}
    if(start->info==data)
    {

        while(p->next!=start)
            p=p->next;
        p->next=start->next;
        start=start->next;
        start->prev=p;
        delete cur;
        return start;
    }
    while(cur->info!=data&&cur->next!=NULL)
       cur=cur->next;
    (cur->next)->prev=cur->prev;
    (cur->prev)->next=cur->next;
    delete cur;
    return start;
}
int main()
{
    cdnode cd;
    cdnode *start=NULL;
    int ch;
    for(;;)
    {
        cout<<"\nEnter\n1.Insert\n2.Display\n3.Delete: ";
        cin>>ch;
        switch(ch)
        {
            case 1:start=cd.insAfter(start);
                   break;
            case 2:cd.display(start);
                   break;
            case 3:start=cd.delpos(start);
                   break;
        }
    }
    return 0;
}
