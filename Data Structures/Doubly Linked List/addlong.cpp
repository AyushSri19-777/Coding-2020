#include <iostream>
using namespace std;
class dnode
{
    int info;
    dnode *next;
    dnode *prev;
public:
    dnode *insend(dnode *,int);
    dnode *insbeg(dnode *,int);
    void add(int,int);
    void display(dnode*);
};
void dnode::display(dnode *start)
{
    dnode *cur=start;
    while(cur!=NULL)
    {
        cout<<cur->info<<" ";
        cur=cur->next;
    }
}
dnode *dnode::insend(dnode *start,int data)
{
    dnode *temp=new dnode;
    temp->prev=temp->next=NULL;
    temp->info=data;
    dnode *cur=start;
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
dnode *dnode::insbeg(dnode *start,int data)
{
    dnode *temp=new dnode;
    temp->prev=temp->next=NULL;
    temp->info=data;
    dnode *cur=start;
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
void dnode::add(int n1,int n2)
{
    dnode *num1=NULL,*num2=NULL,*num3=NULL;
    while(n1!=0)
    {
        num1=insend(num1,n1%10);
        n1/=10;
    }
    while(n2!=0)
    {
        num2=insend(num2,n2%10);
        n2/=10;
    }
    cout<<"First Number  ";
    display(num1);
    cout<<"Second Number  ";
    display(num2);
    dnode *c1=num1,*c2=num2;
    while(c1!=NULL&&c2!=NULL)
    {
        int sum=c1->info+c2->info;
        if(sum>9)
        {
            if(c1->next!=NULL)
            {
            (c1->next)->info+=1;
            sum-=10;
            }
        }
        if(c1->next!=NULL)
          num3=insbeg(num3,sum);
        else if(c1->next==NULL&&sum>9)
        {
          num3=insbeg(num3,sum-10);
          num3=insbeg(num3,1);
        }
        c1=c1->next;
        c2=c2->next;
    }
    while(c1!=NULL)
        num3=insbeg(num3,c1->info);
    while(c2!=NULL)
        num3=insbeg(num3,c2->info);
    cout<<"Sum: ";
    display(num3);
}
int main()
{
    dnode d;
    d.add(1709,1709);
}
