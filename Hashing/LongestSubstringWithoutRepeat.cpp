int Solution::lengthOfLongestSubstring(string A) {
	int ans = 1;
	unordered_map<char, int> m1;
	if (A.size()==0)
	{
		return 1;
	}

	int start = 0;
	m1[A[start]]++;
	int end = 1;

	while(end<A.size()){
		m1[A[end]]++;
		if (m1[A[end]]>1)
		{
		  //  cout<<"start: "<<start<<" end "<<end<<endl;
			while(m1[A[end]]>1 && start!=end){
				m1[A[start]]--;
				start++;
			}
// 			cout<<m1[A[end]]<<endl;
			ans = max(end-start+1, ans);
			end++;
		}else{
			ans = max(end-start+1, ans);
			end++;
		}
	}
	
	return ans;
}
	