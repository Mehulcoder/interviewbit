
int helper(vector<vector<int>> &A, int** dp, int r, int c){

	int n = A.size();
	int m = A[0].size();

	if (dp[r][c]!=-1)
	{
		return dp[r][c];
	}

	int down = A[r][c] + helper(A, dp, r+1, c);
	int right = A[r][c] + helper(A, dp, r, c+1);
    
	dp[r][c] = min(down, right);

	return dp[r][c];
}

int Solution::minPathSum(vector<vector<int> > &A) {
	int** dp = new int*[A.size()];
	for (int i = 0; i < A.size(); ++i)
	{
		dp[i] = new int[A[0].size()];
		for (int j = 0; j < A[0].size(); ++j)
		{
			dp[i][j] = -1;
		}
	}

	int n = A.size();
	int m = A[0].size();
	int sum = 0;
	for (int i = n-1; i >= 0; --i)
	{

		dp[i][m-1] = A[i][m-1];
		if (i+1<n)
		{
			dp[i][m-1]+=dp[i+1][m-1];
		}
		sum+=dp[i][m-1];
	}

	sum = 0;
	for (int i = m-1; i >= 0; --i)
	{
		dp[n-1][i] = A[n-1][i];
		if (i+1<m)
		{
			dp[n-1][i]+=dp[n-1][i+1];
		}
		sum+=dp[n-1][i];
	}

	return helper(A, dp, 0, 0);
}
