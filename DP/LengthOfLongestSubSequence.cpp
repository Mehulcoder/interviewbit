int helper(const vector<int> &A, int start, int &startSequence, int &isOnlyIncreasing, int &isOnlyDecreasing){
	if (start == A.size()-1)
	{
		startSequence = start;
		return 1;
	}

	int temp = helper(A, start+1, startSequence, isOnlyIncreasing, isOnlyDecreasing);
	if (A[start] == A[startSequence])
	{
		return temp;
	}
	if (isOnlyDecreasing && isOnlyIncreasing)
	{
		if (A[start]<A[startSequence])
		{
			startSequence = start;
			isOnlyDecreasing = 0;
			isOnlyIncreasing = 1;
		}else{
			startSequence = start;
			isOnlyDecreasing = 1;
			isOnlyIncreasing = 0;
		}

		return temp+1;
	}else if (isOnlyDecreasing)
	{
		if (A[start]<A[startSequence])
		{
			isOnlyDecreasing = 0;
		}
		startSequence = start;
		return temp+1;	
	}else{
		if (A[start]<A[startSequence])
		{
			start = startSequence;
			return temp+1;
		}
		return temp;
	}


}

int Solution::longestSubsequenceLength(const vector<int> &A) {
	int start = -1;
	int isOnlyDecreasing = 1;
	int isOnlyIncreasing = 1;
	return helper(A, 0, startSequence, isOnlyIncreasing, isOnlyDecreasing);
}
