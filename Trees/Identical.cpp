/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
	if (A==NULL && B==NULL)
	{
		return 1;
	}
	if (A==NULL && B!=NULL)
	{
		return 0;
	}
	if (A!=NULL && B==NULL)
	{
		return 0;
	}
	if (A->val!=B->val)
	{
		return 0;
	}

	int isLeft = isSameTree(A->left, B->left);
	int isRight = isSameTree(A->right, B->right);

	return (isRight && isLeft);
}
