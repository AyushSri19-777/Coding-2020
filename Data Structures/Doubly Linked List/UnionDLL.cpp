#include <iostream>
#include <stdio.h>
using namespace std;
class dnode
{
    int info;
    dnode *next;
    dnode *prev;
public:
    void ins_end(dnode *);
    void unions();
    void display(dnode*);
    dnode* rev(dnode*);
    void shift(dnode *);
    void sort(dnode *);
};
dnode *dnode ::rev(dnode* start)
{
    dnode *a=NULL,*b=start,*c=start->next;
    while(c!=NULL)
    {
        b->next=a;
        b->prev=c;
        a=b;
        b=c;
        c=c->next;
    }
    b->next=a;
    b->prev=c;
    return b;
    //display(header);
}
void dnode::sort(dnode *start)
{
    start=start->next;
    int temp;
    dnode *p=start,*q=start;
    while(p!=NULL)
    {
        q=p->next;
        while(q!=NULL)
        {
            if(p->info<q->info)
            {
                temp=p->info;
                p->info=q->info;
                q->info=temp;
            }
            q=q->next;
        }
        p=p->next;
    }
    cout<<"\n";
    display(start);
}
void dnode::ins_end(dnode *header)
{
    dnode *temp=new dnode;
    dnode *cur=header->next;
    cout<<"Enter the element";
    cin>>temp->info;
    temp->next=temp->prev=NULL;
    if(header->next==NULL)
    {
        header->next=temp;
        temp->prev=header;
        return;
    }
    while(cur->next!=NULL)
        cur=cur->next;
    cur->next=temp;
    temp->prev=cur;
}
void dnode::unions()
{
    dnode *h1=new dnode;
    dnode *h2=new dnode;
    dnode *h3=new dnode;
    h1->next=h1->prev=NULL;
    h2->next=h2->prev=NULL;
    h3->next=h3->prev=NULL;
    int n1,i,n2;
    cout<<"Enter the no. of elements of first list\n";
    cin>>n1;
    cout<<"Enter the 1st list elements\n";
    for(i=1;i<=n1;i++)
        ins_end(h1);
    cout<<"Enter the no. of elements of second list\n";
    cin>>n2;
    cout<<"Enter the 2nd list elements\n";
    for(i=1;i<=n2;i++)
        ins_end(h2);
    display(h1);
    cout<<"\n";
    display(h2);
    dnode *c1=h1->next;
    dnode *c3=h3;
    dnode *c2;
   while(c1!=NULL)
   {
       int f=0;
       c2=h2->next;
       while(c2!=NULL)
       {
           if(c1->info==c2->info)
           {
               f=1;
           }
          c2=c2->next;
       }
       if(f==0)
       {
               dnode *t1=new dnode;
               t1->info=c1->info;
               t1->next=NULL;
               c3->next=t1;
               t1->prev=c3;
               c3=c3->next;
       }
       c1=c1->next;
   }
    c3->next=h2->next;
    cout<<"\n";
    display(h3);
    rev(h1);
    //cout<<"\n";
   // display(h1);
    //cout<<"\n";
   // shift(h1);
    //display(h1);
    sort(h1);
}
void dnode::shift(dnode *header)
{
    int k,n=1;
    cout<<"Enter k value";
    cin>>k;
    dnode *cur=header->next;
    dnode *h1=new dnode;
    dnode *c1=h1->next;
    while(cur!=NULL)
    {
        dnode *t1=new dnode;
        t1->info=c1->info;
        t1->next=NULL;
        c1->next=t1;
        t1->prev=c1;
        if(n%k==0)
        {
            c1=rev(c1);
        }
        c1=c1->next;
        n++;
    }
    header->next=c1;
}
void dnode::display(dnode *header)
{
    dnode *cur=header->next;
    while(cur!=NULL)
    {
        cout<<cur->info<<"-->";
        cur=cur->next;
    }
}
int main()
{
    dnode d;
    d.unions();

}

