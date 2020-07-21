#include<iostream>
using namespace std;
class Tree
{
    Tree *left,*right;
    int data;
    public:
    Tree *create();
    void inorder(Tree*);
    void preorder(Tree*);
    void postorder(Tree *);
    int countLeaves(Tree *);
    int height(Tree *);
    int parent(Tree *,Tree *,int);
    void printGivenLevel(Tree *,int);
    void levelOrder(Tree *);
};
Tree *Tree::create()
{
    cout<<"Enter data or -1 for  NULL\n";
    int x;
    cin>>x;
    if(x!=-1)
    {
        Tree *temp=new Tree;
        temp->data=x;
        cout<<"Enter the left child of"<<x<<"\n";
        temp->left=create();
        cout<<"Enter the right child of"<<x<<"\n";
        temp->right=create();
        return temp;        
    }
    else
    {
        return NULL;
    }
}
void Tree::inorder(Tree *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}
void Tree::preorder(Tree *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<"\t";
    preorder(root->left);
    preorder(root->right);    
}
void Tree::postorder(Tree *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"\t";
}
int Tree::countLeaves(Tree *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL&&root->right==NULL)
        return 1;
    else
        return countLeaves(root->left)+countLeaves(root->right);
}
int Tree::parent(Tree *root,Tree *prev,int x)
{
    if(root==NULL)
        return 0;
    if(root->data==x)
        return prev->data;
    else
    {
        return parent(root->left,root,x)+parent(root->right,root,x);
    }
    
}
int Tree::height(Tree *root)
{
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}
void Tree::printGivenLevel(Tree *root,int l)
{
    if(root==NULL)
        return;
    if(l==1)
        cout<<root->data<<"\t";
    else if(l>1)
    {
        printGivenLevel(root->left,l-1);
        printGivenLevel(root->right,l-1);
    }
}
void Tree::levelOrder(Tree *root)
{
    for(int i=1;i<=height(root);i++)
        printGivenLevel(root,i);
}
int main()
{
    Tree t;
    Tree *root=NULL;
    int x;
    root=t.create();
    cout<<"The inorder of tree\n";
    t.inorder(root);
    cout<<"\nThe preorder of tree\n";
    t.preorder(root);
    cout<<"\nThe postorder of tree\n";
    t.postorder(root);
    cout<<"\nThe number of leaf nodes= "<<t.countLeaves(root);
    cout<<"\nEnter the element whose parent you want";
    cin>>x;
    cout<<"The parent of "<<x<<" is "<<t.parent(root,NULL,x);
    cout<<"\nThe height of tree "<<t.height(root);
    cout<<"\nThe Level Order of tree\n";
    t.levelOrder(root);
}