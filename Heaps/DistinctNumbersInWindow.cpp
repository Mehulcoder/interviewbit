vector<int> Solution::dNums(vector<int> &A, int B) {
	vector<int>ans;
	set<int> s1;
	unordered_map<int, int> m1;
	if (A.size()<=B)
	{
		for (int i = 0; i < A.size(); ++i)
		{
			s1.insert(A[i]);
		}
		ans.push_back(s1.size());
		return ans;
	}

	for (int j = 0; j < B; ++j)
	{
		s1.insert(A[j]);
		m1[A[j]]++;
	}
	ans.push_back(s1.size());

	int pop = 0;
	int push = B;
	while(push<A.size()){
		m1[A[push]]++;
		s1.insert(A[push]);
		m1[A[pop]]--;
		if (m1[A[pop]] == 0)
		{
			s1.erase(A[pop]);
		}

		ans.push_back(s1.size());
		pop++;
		push++;
	}

	return ans;
	
}
