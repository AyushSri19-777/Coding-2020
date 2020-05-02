#include<iostream>
using namespace std;
class Tree
{
    int data;
    Tree *left;
    Tree *right;
    public:
        Tree *create();
        void display(Tree *);
        int countLeaf(Tree *);
        int parent(int,Tree *,Tree *);
        void printSibling(Tree *);
};
void Tree::printSibling(Tree* node)
{
   if(node==NULL)
    return;
   if(node->right==NULL&&node->left!=NULL)
    cout<<(node->left)->data<<" ";
   if(node->right!=NULL&&node->left==NULL)
    cout<<(node->right)->data<<" ";
   printSibling(node->left);
   printSibling(node->right);
}
Tree *Tree::create()
{
    int x;
    Tree *temp=new Tree;
    cout<<"Enter the data or -1 to stop\n";
    cin>>x;
    if(x==-1)
        return NULL;
    else
    {
        temp->data=x;
        cout<<"Enter the left child of "<<x<<"\n";
        temp->left=create();
        cout<<"Enter the right child of "<<x<<"\n";
        temp->right=create();
        return temp;
    }
}
int Tree::parent(int x,Tree *prev,Tree *root)
{
    if(root==NULL)
        return 0;
    if(root->data==x)
    {
        return prev->data;
    }
    return parent(x,root,root->left)+parent(x,root,root->right);
}
void Tree::display(Tree *root)
{
    if(root==NULL)
        return;
    display(root->left);
    cout<<root->data<<"yo";
    display(root->right);
}
int Tree::countLeaf(Tree *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL&&root->right==NULL)
    {
        return 1;
    }
    else
        return countLeaf(root->left)+countLeaf(root->right);
}
int main()
{
    Tree t;
    Tree *root=NULL;
    root=t.create();
    t.display(root);
    cout<<t.countLeaf(root);
    int x,y;
    cout<<"\nEnter element jiska parent chahiye ";
    cin>>x;
    if(t.parent(x,NULL,root)==0)
        cout<<"\nNo parent found";
    else
    {
        cout<<"\nThe parent is "<<t.parent(x,NULL,root);
    }    
    cout<<"\nSibling ho jae ";
    t.printSibling(root);
}
