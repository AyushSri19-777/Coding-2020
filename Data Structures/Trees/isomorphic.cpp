/*Write a function to detect if two trees are isomorphic. Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
For example, following two trees are isomorphic with following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8.
ISomorphicTrees

Input:
First line of input contains the number of test cases T. For each test case, there will be two lines of input , each of which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
Single line output, print "Yes" if trees are isomorphic else print "No".

Your Task:
You don't need to take input. Just complete the function isIsomorphic() that takes root nodes of both the tree as parameter and returns a boolean value.

Constraints:
1<=T<=30
1<=N<=105

Example:
Input:
2
1 2 3 4
1 3 2 4
1 2 3 4
1 3 2 N N N 4
Output:
No
Yes
Link to the problem : https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1

Code:
bool isIsomorphic(Node *root1,Node *root2)
{
  if(!root1&&!root2)
    return true;
  if(!root1||!root2)
    return false;
  if(root1->data!=root2->data) 
    return false;
  if(isIsomorphic(root1->left,root2->left)&&isIsomorphic(root1->right,root2->right)||isIsomorphic(root1->left,root2->right)&&isIsomorphic(root1->right,root2->left))
    return true;
}*/