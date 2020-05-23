/*

                Name: Mehul Chaturvedi
                IIT-Guwahati

*/

/*
                PROBLEM STATEMENT

*/

#include <bits/stdc++.h>
using namespace std;
#include <chrono> 
#ifndef mehul
#pragma GCC optimize("Ofast")
#endif

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;

#define debug(x) cout << '>' << #x << ':' << x << endl;
#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

#define INF 4557430888798830399ll
#define MOD 1000000007
#define EPS 1e-7
#define PI acos(-1)


#define sz(x) (int)(x).size()
 
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define trav(a, x) for(auto& a : x)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs

#ifdef mehul
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : ";__p(arg1);cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	int bracket=0,i=0;
	for(; ;i++)
		if(names[i]==','&&bracket==0)
			break;
		else if(names[i]=='(')
			bracket++;
		else if(names[i]==')')
			bracket--;
	const char *comma=names+i;
	cout.write(names,comma-names)<<" : ";
	__p(arg1);
	cout<<"| ";
	__f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

int helper(int left, int right, vector<int> &ans, vector<int> arr2, bool isCut, vector<vector<int>>&dp, map<pii, vector<int>> &m1, vector<int> basAbnahi){
	if (right-left==1)
	{
		dp[left][right] = 0;
		m1[{left, right}] = {};
		return 0;
	}
	if (right<=left)
	{
		return 0;
	}
	// trace(left, right, dp[left][right], m1[{left, right}]);
	// if (dp[left][right]!=-1)
	// {
	// 	ans = m1[{left, right}];
	// 	return dp[left][right];
	// }
	int cost = right-left;
	int mpc = INT_MAX;
	pair<vector<int>, int> prev = {ans, mpc};
	rep(i, arr2.size()){
		int cuttedAt = -1;
		vector<int> arr = arr2;
		vector<int> temp = ans;
		int cl = 0;
		int cr = 0;
		if (arr[i]<right && arr[i]>left)
		{
			// trace(left, right, arr[i], temp);
			cuttedAt = arr[i];
			isCut = 1;
			temp.push_back(arr[i]);
			arr.erase(arr.begin()+i);
			cl = helper(left, cuttedAt, temp, arr, 0, dp,m1, basAbnahi);
			cr = helper(cuttedAt, right, temp, arr, 0, dp,m1, basAbnahi);
			if (prev.s>cl+cr)
			{
				basAbnahi = temp;
				basAbnahi.erase(basAbnahi.begin());
				prev.s = cl+cr;
				prev.f = temp;
			}
			
		}

	}
	trace(left, right, basAbnahi);
	ans = prev.f;
	if (!isCut) {dp[left][right] = 0; m1[{left, right}] = {}; return 0;}
	dp[left][right] = cost+prev.s;
	// trace(left, right, ans);
	m1[{left, right}] = ans;
	return cost+prev.s;
}


vector<int> rodCut(int A, vector<int> &B) {
	int left = 0;
	int right = A;
	vector<int> ans;
	vector<int> ans2;
	map<pii, vector<int>> m1;
	vector<int> basAbnahi;
	vector<vector<int>>dp(A+1, vector<int> (A+1,-1));
	helper(left, right, ans, B, 0, dp, m1, basAbnahi);
	trav(a,m1){
		trace(a);
	}
	return ans;

}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	#ifdef mehul
    freopen("input.txt", "r", stdin);
    clock_t start = clock();
	#endif

    int a; vector<int> b;
    cin>>a;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
    	int temp;
    	cin>>temp;
    	b.push_back(temp);
    }
    vector<int> ans=rodCut(a, b);
    for (int i = 0; i < ans.size(); ++i)
    {
    	cout << ans[i] << " ";
    }
    cout << '\n';
	
	#ifdef mehul
 	end_routine();
	#endif
    return 0 ; 
}

