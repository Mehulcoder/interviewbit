vector<int> Solution::maxone(vector<int> &A, int B) {
    int left = 0;
    int right = 0;
    int left_best = 0;
    int right_best = 0;
    int ans = 0;
    int zeroes = A[left]==0;
    while(left<=right && right<A.size()){
        if (zeroes>B)
        {
            if (A[left]==0)
            {
                zeroes--;
            }
            left++;
        }
        if (zeroes<=B)
        {

            // ans = max(ans, right - left + 1 );
            if (ans<right-left+1)
            {
                ans = right-left+1;
                right_best = right;
                left_best = left;
            }
            // left_best = left;
            // right_best = right;
            right++;
            if (A[right] == 0)
            {
                zeroes++;
            }
        }
    }

    vector<int>  out;
    for (int i = left_best; i <=right_best; ++i)
    {
        out.push_back(i);
    }

    return out;

    // return ans;
}
