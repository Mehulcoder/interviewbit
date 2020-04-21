int Solution::sqrt(int A) {
    if (A==1)
    {
    	return 1;
    }

    int min = 1;
    int max = A;

    while(min<=max){
    	int mid = (min+max)/2;

    	if (mid*mid>A)
    	{
    		max = mid-1;
    		continue;
    	}

    	if (mid*mid<A)
    	{
    		min = mid+1;
    		continue;
    	}
    }

    return min;
}

