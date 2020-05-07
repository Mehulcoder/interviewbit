vector<int> convert(vector<string> a){
	vector<int> ans;
	for (int i = 0; i < a.size(); ++i)
	{
		string temp = a[i];
		int number = stoi(temp, 0, 2);
		ans.push_back(number);
	}

	return ans;
}

vector<string> helper(int a){

	if (a==1)
	{
		vector<string> ans;
		ans.push_back("0");
		ans.push_back("1");
		return ans;
	}

	vector<string> l1 = helper(a-1);
	vector<string> l2;
	for(int i = 0; i<l1.size();i++){
	    l2.push_back(l1[i]);
	}
	reverse(l2.begin(), l2.end());

	for (int i = 0; i < l1.size(); ++i)
	{
		l1[i] = "0"+l1[i];
		l2[i] = "1"+l2[i];
	}
    
    // cout<< l1.size()<<endl;
    // return l1;
	l1.insert(l1.end(), l2.begin(), l2.end());

	return l1;
}

vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	vector<string> binary = helper(A);

	vector<int> ans = convert(binary);

	return ans;

}
