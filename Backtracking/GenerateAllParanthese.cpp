void helper(vector<string> &ans, string s1, int a ){
	if (a==0)
	{
		return;
	}

	helper(ans, s1, a-1);
	set<string> ans2;	
	for (int i = 0; i < ans.size(); ++i)
	{
		string temp = "()";
		for (int j = 0; j < ans[i].size(); ++j)
		{
			string temp2 = ans[i].substr(0,j)+temp+ans[i].substr(j);
			ans2.insert(temp2);
		}
		ans2.insert(ans[i]+temp);
	}

	ans.clear();
	for(auto val: ans2){
		ans.push_back(val);
	}

	return;

}

vector<string> Solution::generateParenthesis(int A) {
	vector<string> ans;
	string s1 = "()";
	ans.push_back("");

	helper(ans, s1, A);
	return ans;
}
