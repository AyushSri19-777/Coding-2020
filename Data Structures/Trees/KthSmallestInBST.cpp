/*Given the root of the binary search tree and K as input, find K-th smallest element in BST. Your task is to return the K-th smallest element in BST from the function KthSmallestElement().

Input:
The first line of input contains the number of test cases T. For each test case, there will two lines. The first line of input is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:
 
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Second-line is an integer represents K

Output:
For each test case, the output will be the kth smallest element of BST. If no such element exists then print -1.

Constraints:
1<=T<=10
1<=N<=100000


Example(To be used only for expected output):
Input:
2
2 1 3
2
2 1 3
5
Output:
2
-1
Link- https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
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
int KthSmallestElement(Node *root, int k)
{
    v.clear();
    inorder(root);
    if(k<=v.size())
        return v.at(k-1);
    return -1;
}