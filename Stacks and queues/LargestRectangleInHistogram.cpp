#define pb push_back

int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size();
    vector<int> left(n, 0);
    vector<int> right(n,0);
    vector<int> out(n,0);
    stack<int> sl;
    stack<int> sr;

    for (int i = 0; i < n; ++i)
    {
        if (sl.empty())
        {
            sl.push(i);
            left[i] = i;
        }else if (A[sl.top()]>=A[i]){
            // cout<<"here: "<<i<<endl;
            while(!sl.empty() && A[sl.top()]>=A[i]){
                sl.pop();
            }
            if (!sl.empty())
            {
                left[i] = sl.top()+1;
            }else{
                left[i] = 0;
            }
            sl.push(i);
       
        }else{
            
            left[i] = sl.top()+1;
            sl.push(i);
        }
    }


    for (int i = n-1; i >= 0; --i)
    {
        if (sr.empty())
        {
            sr.push(i);
            right[i] = i;
        }else if (A[sr.top()]>=A[i]){
            
            while(!sr.empty() && A[sr.top()]>=A[i]){
                sr.pop();
            }
            if (!sr.empty())
            {
                right[i] = sr.top()-1;
            }else{
                right[i] = n-1;
            }
            sr.push(i);
       
        }else{
            
            right[i] = sr.top()-1;
            sr.push(i);
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        // cout<<"i:"<<i<<" "<<left[i]<<" "<<right[i]<<endl;
        out[i] = (right[i]-left[i]+1)*(A[i]);
        ans = max(ans, out[i]);
    }

    return ans;

}