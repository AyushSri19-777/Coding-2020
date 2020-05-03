/*
Given a binary tree, return true if it is BST, else false. For example, the following tree is not BST, because 11 is in the left subtree of 10. The task is to complete the function isBST() which takes one argument, root of Binary Tree.

        10
     /     \
   7       39
     \
      11

The first line of input contains the number of test cases T. Each test case contains a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:
 
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
The function should return 1 if BST else returns 0.

Your Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function isBST() which takes the root of the tree as a parameter.

Constraints:
1 <= T <= 10
0 <= Number of edges <= 100000

Example:
Input:
2
2 1 3
2 N 7 N 6 N 5 N 9 N 2 N 6
Output:
1
0

Explanation:
Testcase 1: The given binary tree is a BST, hence the answer is 1.
Link- https://practice.geeksforgeeks.org/problems/check-for-bst/1

*/
vector <int> v;
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    v.push_back(root->data);
    inorder(root->right);
    
}
bool isBST(Node* root) {
    v.clear();
    inorder(root);
    int f=0;
    for(int i=0;i<v.size()-1;i++)
    {
        if(v.at(i+1)<=v.at(i)){
            f=1;
            break;
        }
    }
    if(f==1)
        return false;
    return true;
}