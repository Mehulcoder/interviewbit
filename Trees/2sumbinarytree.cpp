/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/



/*
				PROBLEM STATEMENT
Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes

Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.
Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40

Return: 0
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
// int Solution::t2Sum(TreeNode* A, int B) {
// 	TreeNode* temp1 = A;
// 	TreeNode* temp2 = A;

// 	//making stacks
// 	stack<TreeNode*> s1;
// 	stack<TreeNode*> s2;

// 	//making temp1 as left

// 	while(temp1!=NULL){
// 		s1.push(temp1);
// 		temp1 = temp1->left;
// 	}
// 	temp1 = s1.top();
// 	while(temp2!=NULL){
// 		s1.push(temp2);
// 		temp2 = temp2->right;
// 	}
// 	temp2= s2.top();


// }

bool findpair(TreeNode* root, int sum, unordered_set<int> &set){
	if (root == NULL) 
        return false; 
  
    if (findpairUtil(root->left, sum, set)) 
        return true; 
  
    if (set.find(sum - root->data) != set.end()) { 
        cout << "Pair is found ("
             << sum - root->data << ", "
             << root->data << ")" << endl; 
        return true; 
    } 
    else
        set.insert(root->data); 
  
    return findpairUtil(root->right, sum, set);

}

int Solution::t2Sum(TreeNode* A, int B) {
	unordered_set<int> set;
	return(findpair(A, B, set));
    
}


