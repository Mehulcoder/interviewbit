/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


/*
				PROBLEM STATEMENT

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* helper(const vector<int> &A, int left, int right){
	if (left>right)
	{
		return NULL;
	}
	if (left==right)
	{
		return new TreeNode(A[left]);
	}
	int mid = left+(right-left)/2;
	TreeNode* head = new TreeNode(A[mid]);
	head->left = helper(A, left, mid-1);
	head->right = helper(A, mid+1, right);
	
	return head;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
	return helper(A, 0, A.size()-1);
}
