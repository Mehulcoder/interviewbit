int Solution::jump(vector<int> &A) {
	int n = A.size();
	if (n==0 || n==1)
	{
		return 0;
	}
	int startIndex = 0;
	int lastFromStart = A[0];
	int jumps = 1;
	while(lastFromStart<A.size()-1){
		jumps++;
		int maxReachable = 0;
		for (int i = startIndex; i <= lastFromStart; ++i)
		{
			maxReachable = max(maxReachable, A[i]+i);
		}

		if (maxReachable == startIndex)
		{
			return -1;
		}
		startIndex = lastFromStart;
		lastFromStart = maxReachable;
		
	}

	return jumps;
}
