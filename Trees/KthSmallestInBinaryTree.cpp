/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* A, int &count, int B, bool &gotAnswer, int ans){
	if (!A || gotAnswer)
		return;

	helper(A->left, count, B, gotAnswer, ans);
	helper(A->right,  count, B, gotAnswer, ans);
	count++;
	if (count == B)
	{
		gotAnswer = 1;
		ans = A->val;
	}

	return;
}

int Solution::kthsmallest(TreeNode* A, int B) {
	int ans;
	helper(A, 0, B, 0, ans);
	
	return ans;
}
