#include <iostream>
using namespace std;
class Tree
{
    int data;
    Tree *left;
    Tree *right;
    public:
        Tree *create(Tree*,int);
        void display(Tree *,int);
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
}