/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isLeaf(TreeNode* A){
	return (!A->left && !A->right);
}

void helper(TreeNode* A, int sum, vector<vector<int>> &ans, vector<int> container){

	if (isLeaf(A))
	{
	    
		if (A->val == sum)
		{
			container.push_back(A->val);
			ans.push_back(container);
		}
		return;	
	}

	container.push_back(A->val);
	if (A->left)
	{
		helper(A->left, sum-A->val, ans, container);		
	}
	if (A->right)
	{
		helper(A->right, sum-A->val, ans, container);			
	}

	return;
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
	vector<vector<int>> ans;
	vector<int> temp;
	helper(A, B, ans, temp);

	return ans;
}
