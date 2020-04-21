int mod = 1000003;

bool isPossible(int A, int B, vector<int> &C, int X){
	long long painters = B;
	long long current_painter = 1;
	long long temp = 0;
	long long ans = INT_MIN;
	long long n = C.size();
	long long i = 0;

	while(i<n){
		if (painters<current_painter)
		{
			return 0;
		}
		if (C[i]>X)
		{
			return 0;
		}

		temp+=C[i];
		if (temp>X)
		{
			current_painter++;
			ans = max(ans, temp);
			temp = 0;
			i--;
		}

		i++;
	}


	if (ans == X)
	{
		return 1;
	}
}


int Solution::paint(int A, int B, vector<int> &C) {
	long long end = 0;
	long long start = 0;

	for (int i = 0; i < C.size(); ++i)
	{
		end+=C[i];
		start = max(start, C[i]);
	}

	long long ans = end;
	while(start<=end){
		long long mid = (start+end)/2;
		if (isPossible(A, B, C, mid))
		{
			ans = mid;
			end = mid-1;
		}else{
			start = mid+1;
		}
	}

	return (int)((ans%mod)*(B)%mod)%mod;
}
