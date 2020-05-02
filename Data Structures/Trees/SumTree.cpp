/*Write a function that returns true if the given Binary Tree of size N is SumTree else return false. A SumTree is a Binary Tree in which value of each node x is equal to sum of nodes present in its left subtree and right subtree . An empty tree is SumTree and sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

Following is an example of SumTree.

          26
        /    \
      10      3
    /   \   /   \ 
   4     6  1    2
 

Input:
The first line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
Print "1" if the given tree is SumTree else print "0".

Your Task:
You don't need to take input. Just complete the function isSumTree() that takes root node as parameter and returns true, if the tree is SumTree else returns false.
Constraints:
1 <=T<=100
1 <= N <= 104
Example:
Input:
2
3 1 2
10 20 30 10 10

Output:
1
0
Link- https://practice.geeksforgeeks.org/problems/sum-tree/1
*/
vector <int> v;
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