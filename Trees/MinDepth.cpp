/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
	if (!A)
	{
		return 0;
	}

	if (!A->left && !A->right)
	{
		return 1;
	}

	int v1 = INT_MAX;
	int v2 = INT_MAX;
	if (!A->left)
	{
		return minDepth(A->right)+1;
	}else if (!A->right)
	{
		return minDepth(A->left)+1;
	}
	
	return min(minDepth(A->left), minDepth(A->right))+1;
}
