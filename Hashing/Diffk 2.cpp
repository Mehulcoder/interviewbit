int Solution::diffPossible(const vector<int> &A, int B) {
	unordered_map<int, int> m1;

	for (int i = 0; i < A.size(); ++i)
	{

		if (m1[B+A[i]]>0 || m1[A[i]-B]>0)
		{
			return 1;
		}
		m1[A[i]]++;
	}
	
	return 0;
}
