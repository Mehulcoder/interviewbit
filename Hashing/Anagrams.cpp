vector<vector<int> > Solution::anagrams(const vector<string> &A) {
	map<multiset<char>, int> count;
	map<multiset<char>, int> index;
	vector<vector<int>> ans;
	int start = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		multiset<char> s1;
		for (int j = 0; j < A[i].size(); ++j)
		{
			s1.insert(A[i][j]);
		}
		if (count[s1]>0)
		{
			ans[index[s1]].push_back(i+1);
			count[s1]++;
		}else{
			vector<int> temp;
			temp.push_back(i+1);
			ans.push_back(temp);
			index[s1] = start;
			start++;
			count[s1]++;
		}
	}

	sort(ans.begin(), ans.end());
	return ans;



}
