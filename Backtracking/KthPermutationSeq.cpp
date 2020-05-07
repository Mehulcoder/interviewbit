int fact(int n)
{
    if(n>12)
        return INT_MAX;
    if(n==0)
        return 1;
    return n*fact(n-1);
}

void helper(vector<int> &s1, int &k, string &out){
	if (k==1)
	{
    	for (int i = 0; i < s1.size(); ++i)
    	{
    	    out+=to_string(s1[i]);
    	}
    	
    	return;
	}

	int index = (k-1)/fact(s1.size()-1);
	auto it = s1.begin();
	int val = *(it+index);

	k-=index*(fact(s1.size()-1));

	out += to_string(val);
	s1.erase(it+index);
	helper(s1, k, out);
	return;
}

string Solution::getPermutation(int A, int B) {

	vector<int> s1;
	
	for (int i = 0; i < A; ++i)
    {
	    s1.push_back(i+1);
    }

    string ans;

    helper(s1, B,ans);
    
    return ans;
}
