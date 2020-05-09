string Solution::fractionToDecimal(int A, int B) {
	bool isNegative = 0;
	if ((A<0 && B>0)||(A>0 && B<0))
	{
		isNegative = 1;
	}

	int startSize = 0;
	int start = A/B;
	string ans;
	if (isNegative)
	{
		ans+="-";
	}
	ans += to_string(start);
	if (A%B==0)
	{
		return ans;
	}

	ans+=".";
	startSize = ans.size();

	int rem = A%B;
	map<int, int> m1;
	m1[rem];
	int index = 0;
	
	while(1){
		if (m1[rem]!=0)
		{
			return (ans.substr(0, startSize)+"("+ans.substr(startSize)+")");
		}

		index++;
		m1[rem] = index;
		int number = (rem*10)/B;
		rem = (rem*10)%B;
		ans+= to_string(number);

	}
}
