 
typedef long long ll;
#define MOD 1000000007
/*
[1 0 0 0]
[0		]
[0		]
[0		]

*/
int Solution::solve(int A, int B) {
   	
   	vector<vector<ll> > dp;
	dp.resize(A+1);
	for(int i = 0; i < A+1; i++) {
	    dp[i].resize(B+1);
	    for(int j = 0; j < B+1; j++)
	          dp[i][j] = 0;
	}
	dp[0][0] = 1;

	for (ll i = 1; i < A+1; ++i)
	{
		for (ll j = 1; j < B+1; ++j)
		{
			for (ll p = 0; p <= 9 && j-p>=0; ++p)
			{
				dp[i][j]+=dp[i-1][j-p]%MOD;
			}
			dp[i][j] = dp[i][j]%MOD;
		}
	}
	

	return (int)dp[A][B]%MOD;
}
