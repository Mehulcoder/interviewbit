int Solution::climbStairs(int A) {
	int n = A;
	int* dp = new int[n+1];
	if (A==1 || A==2)
	{
		return A;
	}
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= A; ++i)
	{
		dp[i] = dp[i-1]+dp[i-2];
	}

	return dp[n];
}
