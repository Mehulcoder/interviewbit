/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    if (!A)
    {
    	return NULL;
    }
    if (!A->left && !A->right)
    {
    	return A;
    }

    TreeNode* leftFlat = flatten(A->left);
    TreeNode* flatRight = flatten(A->right);
    A->left = NULL;
    A->right = NULL;
    A->right = leftFlat;

    TreeNode* mover = A;
    while(mover->right){
    	mover = mover->right;
    }
	mover->right = flatRight;
	return A;
}
