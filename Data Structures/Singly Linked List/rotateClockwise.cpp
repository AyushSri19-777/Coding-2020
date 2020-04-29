#include <iostream>
using namespace std;

class Node
{
    public:
    Node *next;
    int data;
    Node *insend(Node *);
    Node *rotate(Node *,int,int);
};
Node *Node::insend(Node *start)
{
   Node *cur=start;
    Node *temp=new Node;
    cout<<"Enter the element: ";
    cin>>temp->data;
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
Node *Node::rotate(Node *head,int k,int n)
{
    Node *cur=head;
    //int n=0
    int c,h=0;
    while(cur->next!=NULL)
    {       
        cur=cur->next;
    }
    c=n-k%n;
    Node *cur1=head;
    while(cur1->next!=NULL)
    {
        h++;
        if(h==c)
            break;
        cur1=cur1->next;
    }
    Node *store=cur1->next;
    cur1->next=NULL;
    cur->next=head;
    head=store;
    return head;
}
int main()
{
    Node *head=NULL,*cur;
    Node j;
    int n,k;
    cout<<"Enter number of list elements";
    cin>>n;
    cout<<"Enter the numbers:";
    for(int i=0;i<n;i++)
    {
        head=j.insend(head);
    }
    cout<<"Enter position";
    cin>>k;
    head=j.rotate(head,k,n);
    cur=head;
    cout<<"The rotated list: ";
    while(cur!=NULL)
    {
        cout<<cur->data<<"\t";
        cur=cur->next;
    }
}


