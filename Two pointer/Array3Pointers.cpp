int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
	int ans = INT_MAX;
	int j = 0;
	int k = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		
		
		while(1){
			int p1 = abs(A[i]-B[j]);
			int p2 = abs(C[k]-B[j]);
			int p3 = abs(A[i]-C[k]);

			int temp_ans = max(p1, max(p2,p3));
			ans = min(ans, temp_ans);
// 			if(A[i]==10){
//                 cout<<p1<<" "<<p2<<" "<<p3<<endl;
//             }
			if (B[j]>=A[i] && C[k]>=A[i])
			{
				break;
			}

			if (B[j]<=A[i] && C[k]>=A[i])
			{
				if (j==B.size()-1)
				{
					break;
				}
				j++;
				continue;
			}

			if (B[j]>=A[i] && C[k]<=A[i])
			{
				if (k==C.size()-1)
				{
					break;
				}
				k++;
				continue;
			}
            
			if (p1>=p2)
			{
				if (j==B.size()-1)
				{
					break;
				}
				j++;
				continue;
			}
			if (k==C.size()-1)
			{
				break;
			}
			k++;


		}

		
	}
	return ans;

}
