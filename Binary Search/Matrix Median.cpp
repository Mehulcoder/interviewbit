int Solution::findMedian(vector<vector<int> > &A) {
	int min = INT_MAX;
	int max = INT_MIN;
	int n = A.size()*A[0].size()+1;

	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < A[i].size(); ++j)
		{
			max = std::max(max, A[i][j]);
			min = std::min(min, A[i][j]);
		}
		
	}


	while(min<=max){
		int mid = min+(max-min)/2;

		int count = 0;
// 		cout<<"MID: "<<mid<<" ";
		for (int i = 0; i < A.size(); ++i)
		{

			int start = 0;
			int end = A[i].size();
			int mid2 = start+(end-start)/2;
		
			while(start<=end){
				mid2 = start + (end-start)/2;

				if (A[i][mid2]<=mid)
				{
					start = mid2+1;
					continue;
				}

				if (A[i][mid2]>mid)
				{
					end = mid2-1;
					continue;
				}
				
			}
			if(mid2>=A[i].size()){
			    mid2--;
			}
			if (A[i][mid2]<=mid)
			{
				count+=mid2+1;
			}else{
				count+=mid2;
			}
		}
		
// 		cout<<"count: "<<count<<" ";
// 		cout<<endl;

		if (count < n/2)
		{
			min = mid+1;
		}else{
			max = mid-1;
		}
	}

	return min;
}
