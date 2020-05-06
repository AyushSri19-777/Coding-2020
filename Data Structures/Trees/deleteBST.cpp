/*Given a Binary Search Tree (BST) and a node with value 'x', your task is to delete the node 'x' from the BST.
If no node with value x exists then, do not make any changes

Input:
The first line of input contains the number of test cases T. For each test case, there will two lines. First line of input is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:
 
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Second-line is an integer represents K

Output:
For each test case, driver code will return the inorder traversal of the modified root.

Your Task:
You are required to complete the function deleteNode() which takes two arguments. The first being the root of the tree, and an integer 'x' denoting the node to be deleted from the BST. The function returns a pointer to the root of the modified BST.

Constraints:
1 <= T <= 10
1 <= N <= 100000

Example:
Input:
2
2 1 3 N N N N
12
1 N 2 N 8 5 11 4 7 9 12
9
Output:
1 2 3
1 2 4 5 7 8 11 12

Explanation:
Testcase 1: In the given input there is no node with value 12 , so the tree will remain same.
Testcase 2: In the given input tree after deleting 9 will be
                        1
                  /               \
                N                2
                              /           \
                            N            8
                                     /            \
                                   5              11
                              /          \              \
                            4           7             12
Link- https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1/
*/
Node *minVal(Node *cur)
{
    while(cur->left!=NULL)
        cur=cur->left;
    return cur;
}
Node *deleteNode(Node *root,  int x)
{
    if(root==NULL)
        return root;
    else if(x<root->data)
        root->left=deleteNode(root->left,x);
    else if(x>root->data)
        root->right=deleteNode(root->right,x);
    else
    {
        if(root->left==NULL)
        {
            Node *temp=root->right;
            delete(root->right);
            return temp;
        }
        else if(root->right==NULL)
        {
            Node *temp=root->left;
            delete(root->left);
            return temp;
        }
        Node *temp=minVal(root->right);//to gt minimum element from right subtree
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}