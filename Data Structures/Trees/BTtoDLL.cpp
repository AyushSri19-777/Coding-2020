/*
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the DLL.

TreeToList

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each test case, in a new line, print front to end and back to end traversals of DLL.

Your Task:
You don't have to take input. Complete the function bToDLL() that takes node and head as parameter. The driver code prints the DLL both ways.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 1000
1 <= Data of a node <= 1000

Example:
Input:
2
1 3 2
10 20 30 40 60
Output:
3 1 2
2 1 3
40 20 60 10 30
30 10 60 20 40

Explanation:
Testcase1: The tree is
        1
     /      \
   3       2
So, DLL would be 3<=>1<=>2
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
So, DLL would be 40<=>20<=>60<=>10<=>30.
Link- https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
*/
void BinaryTree2DoubleLinkedList(node *root, node **head) 
{ 
    // Base case 
    if (root == NULL) return; 
  
    // Initialize previously visited node as NULL. This is 
    // static so that the same value is accessible in all recursive 
    // calls 
    static node* prev = NULL; 
  
    // Recursively convert left subtree 
    BinaryTree2DoubleLinkedList(root->left, head); 
  
    // Now convert this node 
    if (prev == NULL) 
        *head = root; 
    else
    { 
        root->left = prev; 
        prev->right = root; 
    } 
    prev = root; 
  
    // Finally convert right subtree 
    BinaryTree2DoubleLinkedList(root->right, head); 
}