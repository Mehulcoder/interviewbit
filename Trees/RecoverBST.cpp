/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* findPred(TreeNode* A){
	if (A->left==NULL)
	{
		return NULL;
	}

	TreeNode* temp = A->left;
	while(temp->right && temp->right!=A){
		temp = temp->right;
	}

	return temp;
}

void helper(TreeNode* A, vector<int> &ans, int &prev, int &first, int &possibleSecond, int &vectorFilled){

	TreeNode* current = A;
	while(current!=NULL){
		if (vectorFilled)
		{
			return;
		}
		if (!current->left)
		{
			if (prev>current->val && first)
			{
				ans.push_back(prev);
				first = 0;
				possibleSecond = current->val;
			}else if (prev>current->val && !first)
			{
				ans.push_back(current->val);
				vectorFilled = 1;
				return;
			}
			prev = current->val;
			current = current->right;
		}else{
			TreeNode* predecessor = findPred(current);
			if (!(predecessor->right))
			{
				predecessor->right = current;
				current = current->left;
			}else{
				//Already visited
				predecessor->right = NULL;
				if (prev>current->val && first)
				{
					ans.push_back(prev);
					first = 0;
					possibleSecond = current->val;
				}else if (prev>current->val && !first)
				{
					ans.push_back(current->val);
					vectorFilled = 1;
					return;
				}
				prev = current->val;
				current = current->right;
			}
		}
	}


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


// 15 10 7 13 6 8 12 15 -1 5 -1 -1 -1 -1 -1 -1