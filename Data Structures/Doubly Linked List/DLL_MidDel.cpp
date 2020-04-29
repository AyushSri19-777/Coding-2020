#include <iostream>
#include <stdio.h>
using namespace std;
class dnode
{
    int info;
    dnode *prev,*next;
public:
    int retmid(dnode *);
    dnode *insbeg(dnode *);
    dnode *del(dnode *,int);
    void TravDis(dnode *);
};
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
dnode *dnode::insbeg(dnode *start)
{
    dnode *temp=new dnode;
    temp->prev=temp->next=NULL;
    cout<<"Enter the element: ";
    cin>>temp->info;
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
dnode *dnode::del(dnode *start,int data)
{
    dnode *cur=start;
    if(start->info==data)
    {
        start=start->next;
        start->prev=NULL;
        delete cur;
        return start;
    }
    while(cur->info!=data&&cur->next!=NULL)
      cur=cur->next;
    if(cur->info==data)
    {
        (cur->next)->prev=cur->prev;
        (cur->prev)->next=cur->next;
        delete cur;
    }
    return start;
}
int dnode::retmid(dnode *start)
{
    dnode *sp=start,*fp=start;
    while(fp->next!=NULL&&(fp->next)->next!=NULL)
    {
        sp=sp->next;
        fp=(fp->next)->next;
    }
    return sp->info;
}
int main()
{
    dnode d,*start=NULL;
    int ch,mid;
    for(;;)
    {
        cout<<"\nEnter\n1.Insert \n2.Delete mid an element\n3.Traverse/Display: ";
        cin>>ch;
        switch(ch)
        {
            case 1:start=d.insbeg(start);
                   break;
            case 2:mid=d.retmid(start);
                   cout<<"Middle element: "<<mid;
                   start=d.del(start,mid);
                   break;
            case 3:d.TravDis(start);
                   break;
        }
    }

    d.TravDis(start);
    return 0;
}
