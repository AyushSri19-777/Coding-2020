/*
Given a Binary Search Tree (BST) and a range, print all the numbers in the BST that lie in the given range l-h(inclusive) in non-decreasing order. If no such element exists, an empty line will be printed.
Note: Element greater than or equal to root go to the right side.

Input:
First line of input contains the number of test cases T. For each test case, there will be two lines of input First line contains a string representing the tree as described below and second line contains two space seperated integers l and h denoting given range.

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each testcase, in a new line, print print all the numbers in the BST that lie in the given range in non-decreasing order.

Your Task:
This is a function problem. You don't have to take any input. Complete the function printNearNodes() that takes root, l, h as parameters and prints numbers in the BST that lie in the given range in non-decreasing order.

Constraints:
1 <= T <= 100
1 <= N <= 104
1 <= l < h < 105

Example:
Input:
2
17 4 18 2 9 
4 24
16 7 20 1 10 
13 23
Output:
4 9 17 18 
16 20 

Explanation:
Testcase 1: For the given input , elements which lies in the range of 4 and 24(inclusive) are 4 9 17 18.
Testcase 2: For the given input , elements which lies in the range of 13 and 23 inclusive of both are 16 and 20.
Link- https://practice.geeksforgeeks.org/problems/print-bst-elements-in-given-range/1/
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
void printNearNodes(Node *root, int l, int h)
{
    v.clear();
    inorder(root);
  for(int i=0;i<v.size();i++)
  {
      if(v.at(i)>=l&&v.at(i)<=h)
        cout<<v.at(i)<<" ";
  }
}