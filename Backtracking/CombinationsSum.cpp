class Solution {
public:

	void doWork(vector<int> &candidates, int index, vector<int> &current, int currentSum, int target, vector<vector<int> > &ans) {
		if (currentSum > target) {
			return;
		}
		if (currentSum == target) {
			ans.push_back(current);
			return;
		}
		for (int i = index; i < candidates.size(); i++) {
			current.push_back(candidates[i]);
			currentSum += candidates[i];

			doWork(candidates, i, current, currentSum, target, ans);

			current.pop_back();
			currentSum -= candidates[i];
		}

	}

	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<int> current; 
		vector<vector<int> > ans;
		sort(candidates.begin(), candidates.end());
		vector<int> uniqueCandidates;
		for (int i = 0; i < candidates.size(); i++) {
			if (i == 0 || candidates[i] != candidates[i-1]) {
				uniqueCandidates.push_back(candidates[i]);
			}
		}
		doWork(uniqueCandidates, 0, current, 0, target, ans); 
		return ans;
	}
};
