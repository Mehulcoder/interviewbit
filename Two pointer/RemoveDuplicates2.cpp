int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i = 0;
    int j = i+1;
    int count = 0;
    while(j<A.size() && i<A.size()){
    	if (A[i]==A[j])
    	{
    		count++;
    		j++;
    		continue;
    	}else{
    		if (count<2)
	    	{
	    		i = j;
	    		j++;
	    		continue;
	    	}else{
	    	  //  cout<<i<<" "<<j<<endl;
	    		A.erase(A.begin()+i+2, A.begin()+j);
	    		i=i+2;
	    		j=i+1;
	   // 		cout<<"i "<<A[i]<<" "<<j<<endl;
	    		count = 0;
	    	}
    		
    	}
    }

    if (count>=2)
    {
        // cout<<"here"<<endl;
    	A.erase(A.begin()+i+2, A.begin()+j);
    }

    return A.size();
}
