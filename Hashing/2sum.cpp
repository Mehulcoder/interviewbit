vector<int> Solution::twoSum(const vector<int> &A, int B) {
	unordered_map<int, int> m1;
	unordered_map<int, int> index_map;

	for (int i = 0; i < A.size(); ++i)
	{
		int temp = B-A[i];
		if (m1[temp]>0)
		{
			vector<int> ans;
			ans.push_back(index_map[temp]);
			ans.push_back(i);
			return ans;
			// return index_map[temp];
		}else{
			m1[A[i]]++;
			index_map[temp] = i
		}
	}
}

/*


*/