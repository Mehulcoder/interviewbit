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


*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bits/stdc++.h>

using namespace std;

TreeNode* helper(const vector<int> &A, int i, int j){
	if(i==j){
		return new TreeNode(A.at(i));
	}

	int mid = i+(j-i)/2;

	TreeNode* root =new TreeNode(A.at(mid));
	root->left  = helper(A, i, mid-1);
	root->right = helper(A, mid+1, j);

	return root;

}


TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
	return helper(A, 0, A.size()-1);  

}
