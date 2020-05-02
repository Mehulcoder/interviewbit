int Solution::braces(string A) {
		stack<char> s1;

		for (int i = 0; i < A.size(); ++i)
		{
			if (A[i]=='(' || A[i]=='+' || A[i]=='-' || A[i]=='*' || A[i]=='/')
			{
				s1.push(A[i]);
			}

			if (A[i]==')')
			{
				int count = 0;
				if (s1.top()=='(')
				{
					return 1;
					// s1.pop();
				}
				while(s1.top()!='('){

					count++;
					s1.pop();
				}
				s1.pop();
			}
		}

		return 0;


}
