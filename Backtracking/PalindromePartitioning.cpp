bool IsPalindrome(string &s){
    int n = s.length();
    for(int i = 0; i <= n/2; i++){
        if(s[i] != s[n-1-i]) return false;
    }
    
    return true;
}

void helper(vector<string> A, int start, vector<string> temp, vector<vector<string>> ans){
	
}

vector<vector<string> > Solution::partition(string A) {
	// string temp;
	vector<string> temp;
	vector<vector<int>> ans;

	helper(A, -1, temp, ans);

	return ans;

}
