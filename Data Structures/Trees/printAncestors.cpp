/*Given a Binary Tree and a target key, your task is to complete the function printAncestors() that prints all the ancestors of the key in the given binary tree.

              1
            /   \
          2      3
        /  \
      4     5
     /
    7
Key: 7
Ancestor: 4 2 1
Input:

First line of input contains the number of test cases T. For each test case, there will be 2 lines of input. First line of each test case will be a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Second line of test case holds the data of key node.

Output:
For each test print all the ancestors of the target value in the order of their hierarchy.

Constraints:
1 <= T <= 1000
1 <= N <= 1000
1<= data of node <= 10000

Example:
Input:
2
1 2 3
2
1 2 3 4 5 6 8 7
7
Ouput:
1
4 2 1

 

 

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
Link- https://practice.geeksforgeeks.org/problems/ancestors-in-binary-tree/1/
*/
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