/*
Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.
 

Input:
First line of input contains the number of test cases T. For each test case, there will be only two line of input, first line contains a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Second line of each test case will contain the integer value k.

Output:
The kth largest element for given input tree.

Your task:
Your task is to complete the function kthLargest(). This function takes the tree and the value k as argument and prints the kth largest element in a new line.

Constraints:
1 <= T <= 1000
1 <= N <= 1000
1 <= K <= N

Example(To be used only for expected output):
Input:
2
4 2 9 1 3 N 10
3
9 N 10
1
Output:
4
10

 Link- https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
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
void kthLargest(Node *root, int k)
{
    v.clear();
    inorder(root);
    cout<<v.at(v.size()-k);
    cout<<"\n";
}