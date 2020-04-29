#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class dnode
{
    int info;
    dnode *next,*prev;
public:
    dnode *insend(dnode *);
    dnode *insbeg(dnode *);
    dnode *insAfter(dnode *);
    void display(dnode *);
    void concat();
    //dnode *revk(dnode *,int);
};
dnode *dnode::insend(dnode *start)
{
    dnode *temp=new dnode;
    dnode *cur=start;
    cout<<"Enter the element";
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
    temp->prev=cur;
    return start;
}
dnode *dnode::insbeg(dnode *start)
{
    dnode *temp=new dnode;
    cout<<"Enter the element";
    cin>>temp->info;
    temp->next=temp->prev=NULL;
    if(start==NULL)
    {
        start=temp;
        return start;
    }
    temp->next=start;
    start->prev=temp;
    start=temp;
    return start;
}
/*dnode *dnode::revk(dnode *start,int k)
{
    int c=1;
    dnode *cur=start,*p=NULL,*next=NULL;
     while(cur->next!=NULL)
     {

     }
}*/

dnode *dnode::insAfter(dnode *start)
{
    int data;
    dnode *cur=start;
    dnode *temp=new dnode;
    cout<<"Enter the element after which you want to insert: ";
    cin>>data;
    cout<<"Enter the element to be inserted: ";
    cin>>temp->info;
    temp->next=NULL;
    if(start==NULL)
        return start;
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
    {
        cout<<"Data not present";
        return start;
    }

}
void dnode::display(dnode *start)
{
    dnode *cur=start;
    cout<<"\nSexy display\n";
    cur->prev=NULL;
    while(cur!=NULL)
    {
        cout<<cur->info<<"\t";
        cur=cur->next;
    }
    //cout<<cur->info;
    cout<<"\nUlta pulta display\n";
    while(cur->prev!=NULL)
    {
        cout<<cur->info<<"\t";
        cur=cur->prev;
    }
    cout<<cur->info;
}
void dnode::concat()
{
    dnode *X1=NULL,*X2=NULL;
    int n1,n2,i;
    cout<<"Enter the number of elements in the first list";
    cin>>n1;
    cout<<"Enter the elements of first list";
    for(i=1;i<=n1;i++)
    {
         X1=insend(X1);
    }
    dnode *cur=X1;
    while(cur->next!=NULL)
        cur=cur->next;
    cout<<"Enter the number of elements in the second list";
    cin>>n2;
    cout<<"Enter the elements of second list";
    for(i=1;i<=n2;i++)
        X2=insend(X2);
    cur->next=X2;
    X2->prev=cur;
    display(X1);
}
int main()
{
    dnode d,*start=NULL;
    int ch;
    for(;;)
    {
        cout<<"\nEnter\n1.Insert at end\n2.Display\n3.Insert after\n4.Exit\n5.Concat\n6.Reverse k\n7.Insbeg: ";
        cin>>ch;
        switch(ch)
        {
            case 1:start=d.insend(start);
                   break;
            case 2:d.display(start);
                   break;
            case 3:start=d.insAfter(start);
                   break;
            case 4:exit(0);
                   break;
            case 5:d.concat();
                   break;
            /*case 6:start=d.revk(start,2);
                   break;*/
            case 7:start=d.insbeg(start);
                   break;
        }
    }
    return 0;
}

