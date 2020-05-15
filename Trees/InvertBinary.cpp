/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
	if (!A)
	{
		return NULL;
	}

	if (!A->left && !A->right)
	{
		return A;
	}

	TreeNode* newLeft = invertTree(A->right);
	TreeNode* newRight = invertTree(A->left);

	A->left = newLeft;
	A->right = newRight;

	return A;
}
