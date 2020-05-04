#include <iostream>
using namespace std;
class Tree
{
    public:
    int data;
    Tree *left;
    Tree *right;
    public:
        Tree *create(Tree*,int);
        void display(Tree *,int);
        Tree *search(Tree*,int);
};
Tree *Tree::create(Tree *root,int x)
{    
    if(root==NULL)
    {
        Tree *temp=new Tree;
        temp->data=x;
        temp->left=temp->right=NULL;
        return temp;
    }
    if(x<root->data)
    {
        root->left=create(root->left,x);
    }
    if(x>root->data)
    {
        root->right=create(root->right,x);
    }
    return root;
}
Tree *Tree::search(Tree *root,int x)
{
    if(root->data==x)
        return root;
    if(x<root->data)
        return search(root->left,x);
    if(x>root->data)
        return search(root->right,x);
}
void Tree::display(Tree *root,int level)
{
    if(root==NULL)
        return;
    display(root->right,level+1);
    for(int i=0;i<level;i++)
        cout<<"\t";
    cout<<root->data<<endl;
    display(root->left,level+1);
}
int main()
{
    Tree t,*root=NULL;int x=0;
    while(1)
    {
        cout<<"Enter the value or -1 to stop";
        cin>>x;    
        if(x==-1)
            break;
        root=t.create(root,x);
    }
    t.display(root,1);    
    Tree *cur=t.search(root,18);
    cout<<(cur)->data<<"aajfbsja";
}