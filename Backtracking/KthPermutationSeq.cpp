string helper(set<int> &s1, int k, string &out){
	



}

string Solution::getPermutation(int A, int B) {
	if (B>12)
	{
		return to_string(INT_MAX);
	}

	set<int> s1;
	
	for (int i = 0; i < A; ++i)
    {
	    s1.insert(i+1);
    }

    string ans;

    helper(s1, B,ans);
    return ans;
}
