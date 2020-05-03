/*Given a BST and some keys, you need to insert the keys in the given BST. Duplicates are not inserted (If a test case contains duplicate keys, you need to consider the first occurrence and ignore duplicates).

Input:
The first line of input contains the number of test cases T. For each test case, there will two lines. The first line of input is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:
 
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Second-line is an integer represents the key value which needs to be inserted

Output:
For each test case, in a new line, the inorder of the BST gets printed.

Your Task:
Since this is a function problem, you don't have to read anything. You have to complete the function insert that takes a node and key as a parameter.

Constraints:
1 <= T <= 10
1 <= N <= 100000
1 <= K <= 1000000

Example:
Input:
2
2 1 3 
4
2 1 3 N N N 6 4
1
Output:
1 2 3 4
1 2 3 4 6

Explanation:
Testcase 1: After inserting the node 4 the tree will be
                                          2
                                      /        \
                                    1          3
                                                   \
                                                    4
Inorder traversal will be 1 2 3 4.
Testcase 2: After inserting the node 1 the tree will be 
                                         2
                                    /           \
                                  1            3
                                /     \       /     \
                              N     N     N     6
                                                   /
                                                 4
Inorder traversal of the above tree will be 1 2 3 4 6.
Link-https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1
*/
Node* insert(Node* node, int data)
{
    if(node==NULL)
    {
        Node *temp=newNode(data);
        return temp;
    }
    if(data<node->data)
    {
        node->left=insert(node->left,data);
    }
    if(data>node->data)
    {
        node->right=insert(node->right,data);
    }
    return node;
}
