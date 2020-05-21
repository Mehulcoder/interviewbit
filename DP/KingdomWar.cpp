int Solution::solve(vector<vector<int> > &A) {
	int n = A.size();
	int m = A[0].size();
	int ans = INT_MIN;
	int** dp = new int*[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i] = new int[m+1];
		for (int j = 0; j < m+1; ++j)
		{
			dp[i][j] = 0;
		}
	}

	for (int i = n-1; i >=0; --i)
	{
		for (int j = m-1; j >= 0; --j)
		{
			dp[i][j] = dp[i+1][j]+dp[i][j+1]-dp[i+1][j+1]+A[i][j];
			ans = max(ans, dp[i][j]);
		}
	}

	return ans;
}


/*
Algorithm behind the question

*/