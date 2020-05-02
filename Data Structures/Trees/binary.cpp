#include<iostream>
#include<stdio.h>
#include<vector>
#include<bits/stdc++.h>
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
        void preorder(Tree *);
        void inorder(Tree *);
        void postorder(Tree *);
        void leftView(Tree *);
        void getL(Tree *);
        void getR(Tree *);
        void topView(Tree *);
        void getSum(Tree *);
        bool isSumTree(Tree *);
        void ancestors(Tree *,int);
};
vector <int> v,p;
void Tree::getSum(Tree *root)
{
    if(root==NULL)
        return;
    v.push_back(root->data);
    getSum(root->left);
    getSum(root->right);
}
bool Tree::isSumTree(Tree* root)
{
    int sum=0;
    getSum(root);
    for(int i=0;i<v.size();i++)
        sum=sum+v.at(i);
    if((sum-(root->data))==(root->data))
    {
         v.clear();
        return true;
    }
    else {
         v.clear();
        return false;
    }
   
}
void Tree::preorder(Tree *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void Tree::inorder(Tree *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void Tree::postorder(Tree *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void Tree::ancestors(Tree *root,int j)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data==j)
    {
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
    }
    else
    {
        v.push_back(root->data);
        ancestors(root->left,j);
        ancestors(root->right,j);
        v.pop_back();
    }    
}
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
void Tree:: leftView(Tree *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    if(root->left==NULL&&root->right!=NULL)
        leftView(root->right);
    leftView(root->left);
}
void Tree::getL(Tree *root)
{
    if(root==NULL)
        return;
    topView(root->left);
    v.push_back(root->data);
}
void Tree::getR(Tree *root)
{
    if(root==NULL)
        return;
    topView(root->right);
    v.push_back(root->data);
}
void Tree::topView(Tree *root)
{
    getL(root);
    getR(root);
    for(int i=0;i<v.size();i++)
        cout<<v.at(i)<<" ";
    reverse(p.begin(),p.end());
    for(int i=1;i<p.size();i++)
        cout<<p.at(i)<<" ";
    v.clear();
    p.clear();
    
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
    cout<<"\nPreorder ";
    t.preorder(root);
    cout<<"\nInorder ";
    t.inorder(root);
    cout<<"\nPostorder ";
    t.postorder(root);
    cout<<"\nLeft View of Binary Tree ";
    t.leftView(root);
    if(t.isSumTree(root)==0)
        cout<<"\nThe tree is not sum tree";
    else
    {
        cout<<"\nThe tree is sum tree";
    }
    cout<<"\nPrinting ancestor ";
    t.ancestors(root,1);    
    cout<<"Top view is: ";
    t.topView(root);
}
