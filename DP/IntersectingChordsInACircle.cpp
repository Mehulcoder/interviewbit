#define M 1000000007
int Solution::chordCnt(int A) {
    int N = A;
    long long int dp[N+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i] += (dp[j-1]*dp[i-j])%M;
            dp[i]=dp[i]%M;
        }
    }
    return dp[A];
}
