class Solution {
    
    public:

        vector<vector<vector<bool> > > dp;
        vector<int> res;
        vector<int> original;
        int total_size;

        bool possible(int index, int sum, int sz) {
            if (sz == 0) return (sum == 0);
            if (index >= total_size) return false;

            if (dp[index][sum][sz] == false) return false;

            if (sum >= original[index]) {
                res.push_back(original[index]);
                if (possible(index + 1, sum - original[index], sz - 1)) return true;
                res.pop_back();
            }
            
            if (possible(index + 1, sum, sz)) return true;

            return dp[index][sum][sz] = false;
        }
    
        vector<vector<int> > avgset(vector<int> &Vec) {

            /* 
             * SUM_of_Set1 / size_of_set1 = SUM_of_Set2 / size_of_set2 
             * SUM_of_Set1 = SUM_of_Set2 * (size_of_set1 / size_of_set2)
             *
             * total_sum = Sum_of_Set1 + Sum_of_Set2
             * and size_of_set2 = total_size - size_of_set1 
             *
             * Sum_of_Set1 = (total_sum - Sum_of_Set1) * (size_of_set1 / (total_size - size_of_set1))
             * OR on simplifying, 
             *   total_sum / Sum_of_Set1 - 1 = (total_size - size_of_set1) / size_of_set1 
             *   total_sum / Sum_of_Set1 = total_size / size_of_set1 
             *   Sum_of_Set1 / size_of_set1 = total_sum / total_size 
             *
             *   Now we can just iterate on size_of_set1, and we would know the required Sum_of_Set1 
             */

            sort(Vec.begin(), Vec.end());
            original.clear();
            original = Vec;
            dp.clear();
            res.clear();

            int total_sum = 0;
            total_size = Vec.size();

            for(int i = 0; i < total_size; ++i)
                total_sum += Vec[i];
            
            dp.resize(original.size(), vector<vector<bool> > (total_sum + 1, vector<bool> (total_size, true)));

            // We need to minimize size_of_set1. So, lets search for the first size_of_set1 which is possible. 
            for (int i = 1; i < total_size; i++) {
                // Sum_of_Set1 has to be an integer
                if ((total_sum * i) % total_size != 0) continue;
                int Sum_of_Set1 = (total_sum * i) / total_size;
                if (possible(0, Sum_of_Set1, i)) {

                    // Ok. Lets find out the elements in Vec, not in res, and return the result.
                    int ptr1 = 0, ptr2 = 0;
                    vector<int> res1 = res;
                    vector<int> res2;
                    while (ptr1 < Vec.size() || ptr2 < res.size()) {
                        if (ptr2 < res.size() && res[ptr2] == Vec[ptr1]) {
                            ptr1++;
                            ptr2++;
                            continue;
                        }
                        res2.push_back(Vec[ptr1]);
                        ptr1++;
                    }

                    vector<vector<int> > ans;
                    ans.push_back(res1);
                    ans.push_back(res2);
                    return ans;
                }
            }
            // Not possible.
            vector<vector<int> > ans;
            return ans;
        }

};
