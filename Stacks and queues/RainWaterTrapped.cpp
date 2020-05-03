int Solution::trap(const vector<int> &A) {
	int i = 0;
	int j = 0;
	int sum = 0;
	int val = A[i];

	while(j<A.size()){
		while(j<A.size() && A[j]<=A[i]){
			// sum+=val-A[i];
			j++;
		}
		if (j==A.size())
		{
			break;
		}
		while(i!=j){
			sum+=val-A[i];
// 			cout<<"Sum: "<<sum<<endl;
			i++;
		}
		val = A[i];
// 		cout<<"Val: "<<val<<endl;
	}

	int p = i+1;
	if (j==A.size())
	{
		while(p<A.size()){
			int start = p;
			for (int l = p; l < A.size(); ++l)
			{
				if (A[l]>=A[p])
				{
					p = l;
				}
			}
	        // cout<<"P: "<<p<<endl;
			for (int q = start; q <= p; ++q)
			{
				sum+=A[p]-A[q];
			}
			p = p+1;
		}
		
	}

	return sum;
}
