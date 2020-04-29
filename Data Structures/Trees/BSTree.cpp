#include <iostream>
using namespace std;
class node
{
    int info;
    node *lcl;
    node *rcl;
public:
    node *create(node *);
    void display(node *,int);
    void search(node *);
    void del_bst(node *);

};
void node::display(node *root,int level)
{
    if(root==NULL)
        return;
    display(root->rcl,level+1);
    for(int i=0;i<level;i++)
        cout<<"\t\t";
    cout<<root->info<<"\n";
    display(root->lcl,level+1);
}
node *node::create(node *root)
{
    cout<<"Enter the info";
    node *temp=new node;
    temp->lcl=temp->rcl=NULL;
    cin>>temp->info;
    if(root==NULL)
        return temp;
    node *c=root,*p=NULL;
    while(c!=NULL)
    {
        if(temp->info<c->info)
        {
            p=c;
            c=c->lcl;
        }
        else if(temp->info>c->info)
        {
            p=c;
            c=c->rcl;
        }
        else
            cout<<"Duplicates not allowed";
    }
    if(temp->info<p->info)
        p->lcl=temp;
    else
        p->rcl=temp;
    return root;
}
void node::del_bst(node *root)
{
     int ele;
    cout<<"Enter the element to be deleted";
    cin>>ele;
    node *q=root,*cur=NULL,*succ=NULL,*par=NULL;
    while(q!=NULL)
    {
        if(q->info==ele)
        {
            cur=q;
            break;
        }
        par=q;
        if(ele<q->info)
            q=q->lcl;
        else
            q=q->rcl;
    }
    if(cur->lcl!=NULL&&cur->rcl!=NULL)
    {
        par=cur;
        succ=cur->rcl;
        while(succ->lcl)
        {
            par=succ;
            succ=succ->lcl;
        }
        cur->info=succ->info;
        cur=succ;
    }
   if(cur->lcl==NULL&&cur->rcl==NULL)
   {
       if(par->rcl==cur)
        par->rcl=NULL;
       else
        par->lcl=NULL;
       delete cur;
       return ;
   }
    if(cur->lcl!=NULL&&cur->rcl==NULL)
   {
       if(par->rcl==cur)
        par->rcl=cur->lcl;
       else
        par->lcl=cur->lcl;
       delete cur;
       return;
   }
    if(cur->lcl==NULL&&cur->rcl!=NULL)
   {
       if(par->rcl==cur)
        par->rcl=cur->rcl;
       else
        par->lcl=cur->rcl;
       delete cur;
       return ;
   }
}
void node::search(node *root)
{
    int ele;
    cout<<"Enter the element to be searched";
    cin>>ele;
    node *c=root;
    int f=0;
    while(c!=NULL)
    {
        if(ele<c->info)
            c=c->lcl;
        else if(ele>c->info)
            c=c->rcl;
        else
        {
            f=1;
            break;
        }
    }
    if(f==1)
        cout<<"Found";
    else
        cout<<"Not found";
}
int main()
{
    node n,*root=NULL;
    int ch;
    for(;;)
    {
        cout<<"1.Create\n2.Display\n3.Search\n4.Delete";
        cin>>ch;
        switch(ch)
        {
            case 1:root=n.create(root);
                   break;
            case 2:n.display(root,0);
                   break;
            case 3:n.search(root);
                   break;
            case 4:n.del_bst(root);
                   break;
        }
    }
    return 0;
}
