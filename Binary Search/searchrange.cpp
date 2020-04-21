vector<int> Solution::searchRange(const vector<int> &A, int B) {
	vetor<int> ans(2,-1);
	int start = lower_bound(A.begin(), A.end(), B)-A.begin();
	if (A[start]!=B)
	{
		return ans;
	}

	int end = upper_bound(A.begin(), a.end(), B)-A.begin();
	if (A[end]>B)
	{
		end--;
	}

	ans[0] = start;
	ans[1] = end;
	return ans;
}
	