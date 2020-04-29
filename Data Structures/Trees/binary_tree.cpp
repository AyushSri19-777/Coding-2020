#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
class node
{
    char info;
    node *lcl,*rcl;
public:
    node *createbt(node *);
    void inorder_rec(node *);
    void preorder_rec(node *);
    void postorder_rec(node *);
    void display(node *,int);
    int cnleaf(node *,int);
    bool ancestors(node*,char);
    node *mirror(node *);
    node *parent(node *,char,node *);

};
node *node::createbt(node *root)
{
    node *temp,*prev,*cur;
    char d[10];
    int i,item;
    temp=new node;
    cout<<"\nElement\n";
    cin>>temp->info;
    temp->lcl=temp->rcl=NULL;
    if(root==NULL)
        return temp;
    cout<<"\nDirection";
    cin>>d;
    prev=NULL;
    cur=root;
    for(i=0;i<strlen(d);i++)
    {
        if(cur==NULL)
            break;
        prev=cur;
        if(d[i]=='L')
            cur=cur->lcl;
        else
            cur=cur->rcl;
    }
    if(cur!=NULL||i!=strlen(d))
    {
        cout<<"Impossible!";
        delete temp;
        return root;
    }
    if(d[i-1]=='L')
        prev->lcl=temp;
    else
        prev->rcl=temp;
    return root;
}
bool node::ancestors(node *root,char x)
{
    if(root==NULL)
        return false;
    if(root->info==x)
        return true;
    if(ancestors(root->lcl,x)||ancestors(root->rcl,x))
    {
        cout<<root->info<<" ";
        return true;
    }
    return false;
}
void node::display(node *root,int level)
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
/*int node::cnl(node *root)
{
    if((root==NULL)||(root->lcl==NULL&&root->rcl==NULL))
       return 0;
    return 1+cnl(root->lcl)+cnl(root->rcl);
}*/
void node ::inorder_rec(node *root)
{
    if(root==NULL)
        return;
    inorder_rec(root->lcl);
    cout<<root->info<<" ";
    inorder_rec(root->rcl);
}
void node ::preorder_rec(node *root)
{
    if(root==NULL)
        return;
    cout<<root->info<<" ";
    preorder_rec(root->lcl);
    preorder_rec(root->rcl);
}
void node ::postorder_rec(node *root)
{
    if(root==NULL)
        return;
    postorder_rec(root->lcl);
    postorder_rec(root->rcl);
    cout<<root->info<<" ";
}
node* node::parent(node *curr,char ele,node *prev)
{
    if(curr!=NULL)
	{
		parent(curr->lcl,ele, curr);
		if(ele==curr->info)
		{
			cout<<"\n Parent : "<<prev->info;
			return prev;
		}
		parent(curr->rcl, ele , curr);
	}

}
node *node::mirror(node *root)
{

  if (root==NULL)
    return root;
  else
  {
    node* temp;

    /* do the subtrees */
    mirror(root->lcl);
    mirror(root->rcl);
    /* swap the pointers in this node */
    temp        = root->lcl;
    root->lcl  = root->rcl;
    root->rcl = temp;
  }
  return root;
}
int node::cnleaf(node* root,int c)
{
    if(root==NULL)
        return c;
    cnleaf(root->lcl,c);
    if(root->lcl==NULL&&root->rcl==NULL)
    {
        c++;
       return c;
    }
    cnleaf(root->rcl,c);
}

int main()
{
    node n,*root=NULL;
    int ch;bool k;
    for(;;)
    {
        cout<<"Enter\n1.Insert\n2.Display\n3.Inorder recursive\n4.Preorder recursive\n5.Postorder recursive\n6.Parent\n7.Ancestors\n8.CNL\n9.Mirror";
        cin>>ch;
        switch(ch)
        {
            case 1:root=n.createbt(root);
                   break;
            case 2:n.display(root,0);
                   break;
            case 3:n.inorder_rec(root);
                   break;
            case 4:n.preorder_rec(root);
                   break;
            case 5:n.postorder_rec(root);
                   break;
            case 6:root=n.parent(root,'E',root);
                   break;
            case 7:k=n.ancestors(root,'E');
                   break;
            case 8:cout<<"Non Leaf nodes: "<<n.cnleaf(root,0);
                   break;
            case 9:root=n.mirror(root);
        }
    }
}
