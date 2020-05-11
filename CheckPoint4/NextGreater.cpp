vector<int> Solution::nextGreater(vector<int> &A) {
    stack<int> s1;
    vector<int> ans(A.size());
    for (int i = A.size()-1; i >= 0; --i)
    {
        while(!s1.empty() && s1.top()<=A[i]){
            s1.pop();    
        }

        if (s1.empty())
        {
            ans[i] = -1;
            s1.push(A[i]);
        }else{
            ans[i] = s1.top();
            s1.push(A[i]);
        }

    }

    return ans;
}