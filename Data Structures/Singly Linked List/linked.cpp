#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class node
{
    public:
    int info;
    node *next;
};
class imple
{
    public:
    node *insend(node *);
    node *insbeg(node *);
    node *insbefele(node *);
    node *insafele(node *);
    node *delend(node *);
    node *delbeg(node *);
    node *delelem(node *);
    node *rev(node *);
    node *sorty(node *);
    node *insertsorted(node *);
    node *delAlt(node *);
    void display(node *);
    void mergesort(node *);
    void middle(node *);

};
node *imple::insend(node *start)
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
void imple::display(node *start)
{
    node *cur=start;
    while(cur!=NULL)
    {
        cout<<cur->info<<"\t";
        cur=cur->next;
    }
}
node *imple::rev(node *start)
{
    node *cur=start;
    node *nextnode;
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
node *imple::sorty(node *start)
{
    node *p,*q;
    int data;
    q=start;
    while(q!=NULL)
    {
        p=q->next;
        while(p!=NULL)
        {
            if(q->info>p->info)
            {
                data=q->info;
            q->info=p->info;
            p->info=data;
            }
            p=p->next;
        }
        q=q->next;
    }
    return start;
}
node *imple::insbeg(node *start)
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
    temp->next=start;
    start=temp;
    return start;
}
node *imple::insbefele(node *start)
{
    int data;
    node *cur=start;
    node *temp=new node;
    cout<<"Enter the element before you want to insert: ";
    cin>>data;
    cout<<"Enter the element to be inserted: ";
    cin>>temp->info;
    temp->next=NULL;
    if(start==NULL)
        return start;
    if(cur->info==data)
    {
        temp->next=cur;
        start=temp;
        return start;
    }
    while(cur->next!=NULL&&(cur->next)->info!=data)
        cur=cur->next;
    if((cur->next)!=NULL)
    {
        temp->next=cur->next;
        cur->next=temp;
        return start;
    }
    else
    {
        cout<<"Data not present";
        return start;
    }
}
node*imple::delend(node *start)
{
    node *cur=start;
    if(start==NULL)
        return start;
    else if(cur->next==NULL)
    {
        delete cur;
        start=NULL;
        return start;
    }
    while((cur->next)->next!=NULL)
        cur=cur->next;
    delete cur->next;
    cur->next=NULL;
    return start;

}
node*imple::delbeg(node *start)
{
    node *cur=start;
    if(start==NULL)
        return start;
    else
    {
        start=start->next;
        delete cur;
        return start;
    }
}
node *imple::insafele(node *start)
{
    int data;
    node *cur=start;
    node *temp=new node;
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
        return start;
    }
    while(cur->next!=NULL&&cur->info!=data)
        cur=cur->next;
    if(cur->next!=NULL)
    {
        temp->next=cur->next;
        cur->next=temp;
        return start;
    }
    else if(cur->next==NULL&&cur->info==data)
    {
        cur->next=temp;
        temp->next=NULL;
        return start;
    }
    else
    {
        cout<<"Data not present";
        return start;
    }
}
node *imple::delelem(node *start)
{
    int data;
    node *cur,*prev,*temp;
    if(start==NULL)
        cout<<"Nothing to delete..";
    else
    {
        cout<<"Enter the element to be deleted: ";
        cin>>data;
        cur=start;
        while((cur!=NULL)&&(cur->info!=data))
        {
            prev=cur;
            cur=cur->next;
        }
        if(cur==start)
        {
            start=start->next;
            cout<<"Deleted element: "<<data;
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
node *imple::insertsorted(node *start)
{
    node *cur=start;
    node *temp=new node;
    temp->next=NULL;
    cout<<"Enter the element to be inserted: ";
    cin>>temp->info;
    if(start==NULL)
        return start;
    if(temp->info<start->info)
    {
        temp->next=start;
        start=temp;
        return start;
    }
    while(cur->next!=NULL||(cur->next)->info<temp->info)
        cur=cur->next;
    if(cur->next!=NULL)
    {
        temp->next=cur->next;
        cur->next=temp;
        return start;
    }
    cur->next=temp;
    temp->next=NULL;
    return start;
}
node *imple::delAlt(node *start)
{
    node *t1,*t2;
    t1 = start->next;
    t2 = t1->next;
    start->next = t1->next;
    while(t1 != NULL && t2 != NULL)
    {
        delete t1;
        t1 = t2->next;
        t2->next = t1->next;
        t2 = t1->next;
    }
    return start;
}
void imple::mergesort(node *start)
{
    int n1,n2,i;
    node *s1=NULL,*s2=NULL,*c1,*c2,*s3=NULL;
    node *f3=new node;
    cout<<"Enter number of elements in list A";
    cin>>n1;
    cout<<"\nEnter the elements of list A";
    for(i=0;i<n1;i++)
        s1=insend(s1);
    cout<<"\nEnter number of elements in list B";
    cin>>n2;
    cout<<"\nEnter the elements of list B";
    for(i=0;i<n2;i++)
        s2=insend(s2);
    c1=s1;
    c2=s2;
    s3=(s1->info<s2->info)?s1:s2;
    while(c1!=NULL&&c2!=NULL)
    {
        if(c1->info<c2->info)
        {
           f3->next=c1;
           c1=c1->next;
           f3=f3->next;

        }
        else if(c1->info>c2->info)
        {
           f3->next=c2;
           c2=c2->next;
           f3=f3->next;
        }
        else
        {
           f3->next=c2;
           c2=c2->next;
           f3=f3->next;
        }
    }
    while(c1!=NULL)
    {
        f3->next=c1;
        c1=c1->next;
        f3=f3->next;
    }
    while(c2!=NULL)
    {
        f3->next=c2;
        c2=c2->next;
        f3=f3->next;
    }
    node *cur=s3;
    while(cur!=NULL)
    {
        cout<<cur->info<<"\t";
        cur=cur->next;
    }

}
void imple::middle(node *start)
{
    node *fp=start,*sp=start;
    while(fp->next!=NULL&&(fp->next)->next!=NULL)
    {
        fp=(fp->next)->next;
        sp=sp->next;
    }
    cout<<"Middle element: "<<sp->info;
}
int main()
{
    imple p;node *start;
    start=NULL;
    int ch;
    for(;;)
    {
        cout<<"\nEnter\n1.Insert at end\n2.Insert at beginning\n3.Display\n4.Stop\n5.Insert before a given element\n6.Delete from end";
        cout<<"\n7.Delete from beginning\n8.Insert after a given element\n9.Delete particular element\n10.Reverse\n11.Sort\n12.InsSort";
        cout<<"\n13.DeleteAlternate\n14.Mergesort\n15.Middle element :";
        cin>>ch;
        switch(ch)
        {
            case 1:start=p.insend(start);
                    break;
            case 2:start=p.insbeg(start);
                    break;
            case 3:p.display(start);
                    break;
             case 4:exit(0);
             case 5:start=p.insbefele(start);
                    break;
             case 6:start=p.delend(start);
                    break;
             case 7:start=p.delbeg(start);
                    break;
             case 8:start=p.insafele(start);
                    break;
            case 9: start=p.delelem(start);
                    break;
            case 10:start=p.rev(start);
                     break;
            case 11:start=p.sorty(start);
                    break;
            case 12:start=p.insertsorted(start);
                    break;
            case 13:start=p.delAlt(start);
                    break;
            case 14:p.mergesort(NULL);
                    break;
            case 15:p.middle(start);
                    break;
        }
    }
   return 0;
}
