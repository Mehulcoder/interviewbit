

void helper(vector<vector<int>> &ans,vector<int> temp, vector<int> &A, int start, map<vector<int>, int> &m1){

	if (start == A.size())
	{
		if (!m1[temp])
		{
			m1[temp]++;
			ans.push_back(temp);
		}
		return;
	}

	temp.push_back(A[start]);
	helper(ans, temp, A,start+1,m1);

	temp.pop_back();
	helper(ans, temp, A, start+1,m1);

	return;
}


vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
	sort(A.begin(), A.end());
    vector<vector<int>> ans;
    vector<int> temp;
    map<vector<int>, int> m1;

    helper(ans,temp, A, 0, m1);

    return ans;

}
