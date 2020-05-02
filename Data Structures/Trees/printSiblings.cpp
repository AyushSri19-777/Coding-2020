/*
Given a Binary Tree of size N, such that all nodes have distinct values, print all the nodes which don't have a sibling node in sorted order. If all nodes have a sibling node then print -1 .
Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:
  
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each test case , print all the nodes which don't have a sibling node in the sorted order. If all nodes have a sibling node then print -1.
Your Task:
You don't have to take input. Complete the function printSibling() that takes root node of the tree as parameter and prints all the space seperated sorted nodes which don't have a sibling node in the sorted order .
Constraints:
1 <=T<= 30
1 <=Number of nodes<= 104

Example:
Input
2
37 20 N 113 
1 2 3
Output 
20 113
-1
Explanation:
Testcase 1: In above example the root node is 37 which has left child 20 and right child nothing. The node 20 has a left child 113. So, the aswer is 2 that is node 20 and 113 don't have siblings.

Note: The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
Link-https://practice.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1
*/
#include <vector>
using namespace std;
vector <int> v;
void getSiblings(Node *node)
{
    if(node==NULL)
    return;
   if(node->right==NULL&&node->left!=NULL)
    v.push_back((node->left)->data);
   if(node->right!=NULL&&node->left==NULL)
    v.push_back((node->right)->data);
   getSiblings(node->left);
   getSiblings(node->right);
}
void printSibling(Node* node)
{
   getSiblings(node);
   if(v.size()==0)
    cout<<"-1";
   else
   {
       sort(v.begin(),v.end());
       for(int i=0;i<v.size();i++)
        cout<<v.at(i)<<" ";
   }
   v.clear();
}