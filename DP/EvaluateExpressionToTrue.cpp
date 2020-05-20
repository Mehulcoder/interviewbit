
#define MOD 1003
typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair

map<string, pii> m;

pii helper(string A){
	if (A.size()==1)
	{
		if (A=="T")
		{
			return mp(1, 0);
		}
		return mp(0,1);
	}

	if (m.find(A)!=m.end())
	{
		return m[A];
	}
	pii ans = mp(0,0);
	for (int i = 1; i < A.size(); i+=2)
	{
		pii right = helper(A.substr(i+1));
		pii left = helper(A.substr(0, i));


		if(A[i] == '|'){
            ans.f = (ans.f+(left.f*right.f)%MOD)%MOD;
            ans.f = (ans.f+(left.f*right.s)%MOD)%MOD;
            ans.f = (ans.f+(left.s*right.f)%MOD)%MOD;
            ans.s = (ans.s+(left.s*right.s)%MOD)%MOD;
        }
        else if(A[i] == '&'){
            ans.f = (ans.f+(left.f*right.f)%MOD)%MOD;
            ans.s = (ans.s+(left.s*right.s)%MOD)%MOD;
            ans.s = (ans.s+(left.f*right.s)%MOD)%MOD;
            ans.s = (ans.s+(left.s*right.f)%MOD)%MOD;
        }
        else{
            ans.f = (ans.f+(left.f*right.s)%MOD)%MOD;
            ans.f = (ans.f+(left.s*right.f)%MOD)%MOD;
            ans.s = (ans.s+(left.f*right.f)%MOD)%MOD;
            ans.s = (ans.s+(left.s*right.s)%MOD)%MOD;
        }

	}

	m[A] = ans;
	return ans;

}

int Solution::cnttrue(string A) {
	return helper(A).f;
}
