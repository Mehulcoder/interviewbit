int Solution::numDecodings(string A) {
    int n = A.size();
    if (n==1)
    {
        return (A[0]!='0');
    }
    int* dp = new int[n+1];
    dp[n] = 1;
    dp[n-1] = (A[n-1]!='0');
    
    for (int i = n-2; i >= 0; --i)
    {
        if (A[i]=='0')
        {
            dp[i] = 0;
            continue;
        }else{
            dp[i] = dp[i+1];
        }
        string temp2 = A.substr(i,2);
        int val = stoi(temp2);
        if (val>=1 && val<=26)
        {
            dp[i]+=dp[i+2];
        }
    }

    return dp[0];
}
