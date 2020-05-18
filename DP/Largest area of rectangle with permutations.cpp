#define pb push_back
#define all(x) x.begin(), x.end()


int Solution::solve(vector<vector<int> > &A) {
    //Transform matrix
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < A[i].size(); ++j)
        {
            if (i && A[i][j])
            {
                A[i][j]+=A[i-1][j];
            }
        }
    }

    //Sort by max value of each column row by row
    int ans = INT_MIN;
    for (int i = 0; i < A.size(); ++i)
    {
        sort(all(A[i]));
        for (int j = 0; j < A[i].size(); ++j)
        {
            int temp = A[i][j]*(A[i].size()-j);
            ans = max(ans, temp);
        }
    }

    return ans;
}