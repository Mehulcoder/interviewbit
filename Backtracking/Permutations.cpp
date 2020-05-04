void helper(vector<int> A, int start, vector<vector<int>> &ans){
	if (start == A.size())
	{
		return;
	}

	vector<vector<int>> ans2;
	helper(A, start+1, ans);
	for (int i = 0; i < ans.size(); ++i)
	{
		
		for (int j = 0; j < ans[i].size(); ++j)
		{
		    vector<int> temp2 = ans[i];
			int val = A[start];
			temp2.insert(temp2.begin()+j, val);
			ans2.push_back(temp2);
		}
		vector<int> temp2 = ans[i]; 
		temp2.push_back(A[start]);
		ans2.push_back(temp2);
	}

	ans = ans2;
	return;
}

vector<vector<int> > Solution::permute(vector<int> &A) {
	vector<vector<int>> ans;
	vector<int> s1;
	ans.push_back(vector<int>(0));
	helper(A, 0, ans);
	return ans;
}
