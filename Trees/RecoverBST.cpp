/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* A, vector<int> &ans, int &prev, int &first, int &possibleSecond, int &vectorFilled){
	if (A==NULL || vectorFilled)
	{
		return;
	}

	helper(A->left, ans, prev, first, possibleSecond, vectorFilled);
	if (prev>A->val && first)
	{
		ans.push_back(prev);
		first = 0;
		possibleSecond = A->val;
	}else if (prev>A->val && !first)
	{
		ans.push_back(A->val);
		vectorFilled = 1;
		return;
	}
	prev = A->val;
	helper(A->right, ans, prev, first, possibleSecond, vectorFilled);
}

vector<int> Solution::recoverTree(TreeNode* A) {
	vector<int> ans;
	int vectorFilled = 0;
	int possibleSecond = -1;
	int first = 1;
	int prev = INT_MIN;
	helper(A, ans, prev, first, possibleSecond, vectorFilled);
	if (!vectorFilled)
	{
		ans.push_back(possibleSecond);
	}

	sort(ans.begin(), ans.end());
	return ans;
}
