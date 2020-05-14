/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int isEqual(TreeNode* A, TreeNode* B){
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

	if (A->val != B->val)
	{
		return 0;
	}

	return (isEqual(A->left, B->right)&&isEqual(A->right,B->left));
}

int Solution::isSymmetric(TreeNode* A) {
	if (A==NULL)
	{
		return 1;
	}
	if (A->left==NULL && A->right ==NULL)
	{
		return 1;
	}
	if (A->left!=NULL && A->right==NULL)
	{
		return 0;
	}
	if (A->left==NULL && A->right!=NULL)
	{
		return 0;
	}
	if (A->left->val != A->right->val)
	{
		return 0;
	}

	return isEqual(A->left,A->right);

}
