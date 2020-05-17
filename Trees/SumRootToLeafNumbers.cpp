/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 const int MOD = 1003;
 
void helper(TreeNode* A, vector<string> &v1, string s1){
	if (!A->left && !A->right)
	{
		s1+=to_string(A->val);
		v1.push_back(s1);
		return;
	}

	s1+=to_string(A->val);
	s1 = to_string(stoll(s1, nullptr, 10)%1003);
	if (A->left)
	{
		helper(A->left, v1, s1);
	}
	if (A->right)
	{
		helper(A->right, v1, s1);
	}

	return;


}

int Solution::sumNumbers(TreeNode* A) {
	if (!A)
	{
		return 0;
	}
	string s1 = "";
	vector<string> v1;
	helper(A, v1, s1);

	long long sum = 0;
	for (int i = 0; i < v1.size(); ++i)
	{
		sum=(sum + stoll(v1[i], nullptr, 10)%MOD)%MOD;
	}

	sum = sum%MOD;
	return (int)sum;
}
