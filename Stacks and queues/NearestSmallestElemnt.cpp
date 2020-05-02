vector<int> Solution::prevSmaller(vector<int> &A) {
	stack<int> s1;
	vector<int> ans(A.size(),-1);
	s1.push(A[0]);
	
	if(A.size()==1){
	    return ans;
	}

	for (int i = 1; i < A.size(); ++i)
	{
		if (s1.empty())
		{
		  //  cout<<"here"<<endl;
			s1.push(A[i]);
			continue;
		}
		if (s1.top()<A[i])
		{
			ans[i] = s1.top();
			s1.push(A[i]);
// 			cout<<s1.top()<<endl;
			continue;
		}

		if (s1.top()>=A[i])
		{
			while(!s1.empty() && s1.top()>=A[i]){
				s1.pop();
			}
			if (!s1.empty() && s1.top()<A[i])
			{
				ans[i] = s1.top();
			}
			s1.push(A[i]);
		}
		
// 		return ans;
	}

	return ans;

}
