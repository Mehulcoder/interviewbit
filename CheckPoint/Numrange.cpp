int Solution::numRange(vector<int> &A, int B, int C) {
	int l = 0;
	int r = 0;
	int sum = A[0];
	int ans = 0;

	while(r<A.size()){
		if (sum>C)
		{
			sum-=A[l];
			l++;
			continue;
		}
		if (sum<B)
		{
			r++;
			sum+=A[r];
			continue;
		}
		if (sum>=B && sum<=C)
		{
			int sum2 = sum;
			int left2 = l;
			while(sum2>=B && left2<=r){
				ans++;;
				sum2-=arr[left2];
				left2++;
			}
			if (r == A.size()-1)
			{
				return ans;
			}
			r++;
			sum+=A[r];
		}
	}

	return ans;
}
