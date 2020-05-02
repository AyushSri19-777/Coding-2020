/*Given a Binary Tree, print Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Input :
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output :
For each test case, in a new line, print the right view of the binary tree.

Your Task:
This is a function problem. You don't have to take input. Just complete the function rightView() that takes node as parameter and prints the right view. The newline is automatically appended by the driver code.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 105
1 <= Data of a node <= 105

Example:
Input:
2
1 3 2
10 20 30 40 60
Output:
1 2
10 30 60

Explanation:
Test case 1: Below is the given tree

           1
         /     \
      3        2
For the above test case the right view is: 1 2
Test case 2: Below is the given tree

            10
         /        \
     20          30
   /      \      
40      60

Right View is: 10 30 60.
Link- https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
*/
vector <int> v;
int height(Node *root)
{
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}
void printGivenLevel(Node *root,int l)
{
    if(root==NULL)
        return;
    if(l==1)
        v.push_back(root->data);
    else if(l>1)
    {
        printGivenLevel(root->left,l-1);
        printGivenLevel(root->right,l-1);
    }
}
void rightView(Node *root)
{
   for(int i=1;i<=height(root);i++)
   {
       printGivenLevel(root,i);
       cout<<v.at(v.size()-1)<<" ";
       v.clear();
   }
}