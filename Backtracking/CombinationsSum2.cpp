

void helper(vector<vector<int>> &ans,vector<int> temp, vector<int> &A, int B, int sum, int start, map<vector<int>, int> &m1){
	if (sum==B)
	{
		if (!m1[temp])
		{
			m1[temp]++;
			ans.push_back(temp);
		}
		return;
	}

	if (sum>B || start == A.size())
	{
		return;
	}

	temp.push_back(A[start]);
	helper(ans, temp, A, B, sum+A[start], start+1,m1);

	temp.pop_back();
	helper(ans, temp, A, B, sum, start+1,m1);

	return;
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());

    vector<vector<int>> ans;
    vector<int> temp;
    map<vector<int>, int> m1;
    helper(ans,temp, A, B, 0, 0, m1);

    return ans;
}
