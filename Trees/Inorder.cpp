

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
	vector<int> ans;
	if (A==NULL)
	{
		return ans;
	}
	stack<TreeNode*> heads;
	unordered_map<TreeNode*, int> m1;
	
	heads.push(A);
	while(!heads.empty()){
		while(heads.top()->left && m1[heads.top()->left]==0){
            m1[heads.top()->left]++;
			heads.push(heads.top()->left);
			
		}
		TreeNode* curr = heads.top();
		ans.push_back(curr->val);
		heads.pop();
		if (curr->right)
		{
			heads.push(curr->right);
		}
	}

	return ans;
}
