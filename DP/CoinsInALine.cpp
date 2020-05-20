
int dp[505][505];
int helper(vector<int> &A, int start, int end){
	if (start == end)
	{
		return A[start];
	}
	if (end == start+1)
	{
		return max(A[start], A[end]);
	}
	if (dp[start][end]!=-1)
	{
		return dp[start][end];
	}

	//Choose start
	int m1 = A[start]+min(helper(A, start+2, end), helper(A, start+1, end-1));
	//Choose end
	int m2 = A[end]+min(helper(A, start+1, end-1), helper(A, start, end-2));

	dp[start][end] = max(m1, m2);
	return max(m1, m2);
}

int Solution::maxcoin(vector<int> &A) {
	for (int i = 0; i < 505; ++i)
	{
		for (int j = 0; j < 505; ++j)
		{
			dp[i][j] = -1;
		}
	}
	int start = 0;
	int end = A.size()-1;
	return helper(A, start, end);
}
