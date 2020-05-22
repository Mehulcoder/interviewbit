int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int n = A.size();
	// int m = A[0].size();
	int ans = INT_MAX;
	int** dp = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		dp[i] = new int[A[i].size()];
		for (int j = 0; j < A[i].size(); ++j)
		{
			if (i==n-1)
			{
				dp[i][j] = A[i][j];
			}
		}
	}

	for (int i = n-2; i >= 0; --i)
	{
		for (int j = 0; j < A[i].size(); ++j)
		{
			dp[i][j] = min(dp[i+1][j], dp[i+1][j+1])+A[i][j];
		}
	}

	return dp[0][0];
}
