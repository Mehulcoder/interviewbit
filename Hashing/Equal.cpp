vector<int> Solution::equal(vector<int> &A) {
	map<int, vector<int>> m1;
	vector<vector<int>> ans2;
	vector<int> ans;

	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = i+1; j < A.size(); ++j)
		{
			int sum = A[i]+A[j];
			if (m1.find(sum)!=m1.end())
			{
				vector<int> temp = m1[sum];
				
				int a = temp[0];
				int b = temp[1];

				if ((a!=j && a!=i) && (b!=j && b!=i))
				{
					ans.push_back(a);
					ans.push_back(b);
					
					ans.push_back(i);
					ans.push_back(j);
					ans2.push_back(ans);
					ans.clear();
				}
			}else{
				vector<int> v1;
				v1.push_back(i);
				v1.push_back(j);

				m1[sum] = v1;
			}
		}
	}
	

	if (!ans2.size())
	{
		return ans;
	}
	sort(ans2.begin(), ans2.end());
    
	return ans2[0];

}
