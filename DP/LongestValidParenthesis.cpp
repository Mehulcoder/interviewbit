//Basically you need to check for the i-1 && check that if (i-len(i-1)-1) == '(' ---> ans = (len(i-1)+2+len(i-2-len(i-1))

int Solution::longestValidParentheses(string A) {
	int n = A.size();
	if (n<=1)
	{
		return 0;
	}
	vector<int> dp(n, 0);
	int ans = 0;
	for (int i = 1; i < n; ++i)
	{
		if (A[i]=='(')
		{
			dp[i] = 0;
		}else{
			if (A[i-1] == '(')
			{
				dp[i]+=2;
				if (i-2>=0)
				{
					dp[i]+=dp[i-2];
				}
			}else{
				if (i-dp[i-1]-1>=0 && A[i-dp[i-1]-1]=='(')
				{
					dp[i]+=dp[i-1]+2;
					if (i-2-dp[i-1]>=0)
					{
						dp[i]+=dp[i-2-dp[i-1]];
					}
				}
			}
		}
// 		cout<<"i: "<<i<<" "<<dp[i]<<endl;
		ans = max(ans, dp[i]);
	}

	return ans;
}
