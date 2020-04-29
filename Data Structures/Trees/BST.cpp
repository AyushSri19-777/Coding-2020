#include <iostream>
#include <stdio.h>
using namespace std;
class bst
{
    int info;
    bst *lcl,*rcl;
public:
    bst *insert(bst *);
    bst *del(bst *);
    void display(bst *,int);
    void max_min(bst *);
    void search(bst*);
};
void bst::max_min(bst *root)
{
    bst *lcur=root,*rcur=root;
    int ld=0,rd=0;
    while(lcur->lcl!=NULL)
    {
        lcur=lcur->lcl;
        ld++;
    }
    while(rcur->rcl!=NULL)
    {
        rcur=rcur->rcl;
        rd++;
    }
    cout<<"MAXIMUM : "<<rcur->info<<" MINIMUM : "<<lcur->info;
    cout<<"DEPTH : "<<((ld>rd)?ld:rd);
}
void bst::search(bst *root)
{
    int ele;
    cout<<"Enter the element to be searched";
    cin>>ele;
    if(root==NULL)
	{
		cout<<"tree is empty";
		return;
	}
	bst *cur=root;
	while(cur!=NULL)
	{
		if(cur->info==ele)
		{
			cout<<"Element found";
			return;
		}
		else if(cur->info>ele)
            cur=cur->lcl;
		else
			cur=cur->rcl;
	}
	cout<<"Element not found";


}
bst *bst::insert(bst *root)
{
    bst *temp=new bst;
    temp->lcl=temp->rcl=NULL;
    bst *c=root,*p=NULL;
    cout<<"\nEnter the element: ";
    cin>>temp->info;
    if(root==NULL)
        return temp;
    while(c!=NULL)
    {
        if(c->info>temp->info)
        {
            p=c;
            c=c->lcl;
        }
        else if(c->info<temp->info)
        {
            p=c;
            c=c->rcl;
        }
        else
        {
            cout<<"Duplicate elements not allowed!!";
            break;
        }

    }
    if(temp->info<p->info)
        p->lcl=temp;
    else
        p->rcl=temp;
    return root;
}
bst *bst::del(bst *root)
{
    int ele;
    cout<<"Enter the element to be deleted";
    cin>>ele;
    if(root==NULL)
     return root;
    bst *par=NULL;
    bst *cur=NULL;
    bst *q=root,*succ=NULL;
    while(q!=NULL)
    {
        if(q->info==ele)
        {
            cur=q;
            break;
        }
        par=q;
        if(q->info>ele)
            q=q->lcl;
        else
            q=q->rcl;
    }
    if(cur->lcl!=NULL&&cur->rcl!=NULL)
    {
        par=cur;
        succ=cur->rcl;
        while(succ->lcl!=NULL)
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
        return root;
    }
    if(cur->lcl==NULL&&cur->rcl!=NULL)
    {
        if(par->lcl==cur)
            par->lcl=cur->rcl;
        else
            par->rcl=cur->rcl;
        delete cur;
        return root;
    }
    if(cur->lcl!=NULL&&cur->rcl==NULL)
    {
        if(par->lcl==cur)
            par->lcl=cur->lcl;
        else
            par->rcl=cur->lcl;
        delete cur;
        return root;
    }
}
void bst::display(bst *root,int level)
{
     int i;
    if(root==NULL)
        return;
    display(root->rcl,level+1);
    for(i=0;i<level;i++)
        cout<<"\t\t";
    cout<<root->info<<"\n";
    display(root->lcl,level+1);
}
int main()
{
    bst b,*root=NULL;
    int ch;
    for(;;)
    {
        cout<<"Enter\n1.Insert\n2.Display\n3.Maximum&Minimum\n4.Search\n5.Delete";
        cin>>ch;
        switch(ch)
        {
            case 1:root=b.insert(root);
                   break;
            case 2:b.display(root,0);
                   break;
            case 3:b.max_min(root);
                   break;
            case 4:b.search(root);
                   break;
            case 5:root=b.del(root);
                   break;
        }
    }
    return 0;
}
