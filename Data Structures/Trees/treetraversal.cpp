/*
Given Preorder, Inorder and Postorder traversals of some tree. The task is to check if they are all of the same tree or not.

Input:
First line of input contains number of testcases T. For each testcase, there will be four lines, first contains the number of nodes in the tree. This is followed by preorder, inorder, postorder traversal respectively.  

Output:
Print Yes if all the traversals are for the same tree otherwise print No. 

Your Task:
Complete the function checktree() which takes the preorder, inorder, postorder traversal along with the number of nodes in the tree as input and returns a boolean value. 

Constraints:

Examples:

Sample Input:
2
5
1 2 4 5 3
4 2 5 1 3
4 5 2 3 1
5
1 5 4 2 3
4 2 5 1 3
4 1 2 3 5

Sample Output:
Yes
No

Explanation:
Testcase 1:
Preorder -> 1 2 4 5 3
Inorder -> 4 2 5 1 3
Postorder -> 4 5 2 3 1
All of the above three traversals are of the same tree.
                           1
                         /   \
                        2     3
                      /   \
                     4     5
                     */
bool checktree(int preorder[], int inorder[], int postorder[], int len) 
{ 
	// if the array lengths are 0 then all of them are obviously equal 
	if (len == 0) 
		return 1; 

	// if array lengths are 1, then check if all of them are equal 
	if (len == 1) 
		return (preorder[0] == inorder[0]) && (inorder[0] == postorder[0]); 

	// search for first element of preorder in inorder array 
	int idx = -1; 
	for (int i = 0; i < len; ++i) 
		if (inorder[i] == preorder[0]) { 
			idx = i; 
			break; 
		} 

	if (idx == -1) 
		return 0;
	
	// matching element in postorder array
	if( preorder[0] != postorder[len-1] ) return false;

	// check for the left subtree 
	int ret1 = checktree(preorder + 1, inorder, postorder, idx); 

	// check for the right subtree 
	int ret2 = checktree(preorder + idx + 1, inorder + idx + 1, postorder + idx, len - idx - 1); 

	// return 1 only if both of them are correct else 0 
	return (ret1 && ret2); 
} 