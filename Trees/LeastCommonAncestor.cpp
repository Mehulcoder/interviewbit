/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void pathFinder(TreeNode* A, int B, vector<int> out, vector<int> &ans, int &found){
	if (found || !A)
	{
		return;
	}

	if (A->val == B)
	{
		found = 1;
		out.push_back(B);
		ans = out;
		return;
	}

	out.push_back(A->val);
	pathFinder(A->left, B, out, ans, found);
	pathFinder(A->right, B, out, ans, found);

	return;

}

int Solution::lca(TreeNode* A, int B, int C) {
	vector<int> pathC;
	vector<int> pathB;
	vector<int> helper;
	int foundB = 0;
	int foundC = 0;

	pathFinder(A, B, helper, pathB, foundB);
	pathFinder(A, C, helper, pathC, foundC);
	if (!foundB || !foundC)
	{
		return -1;
	}

	int ans = -1;
	for (int i = 0; i < min(pathC.size(), pathB.size()); ++i)
	{
		if (pathB[i]==pathC[i])
		{
			ans = pathB[i];
		}
	}

	return ans;

}
