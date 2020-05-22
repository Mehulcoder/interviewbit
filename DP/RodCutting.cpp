/*

                Name: Mehul Chaturvedi
                IIT-Guwahati

*/

/*
                PROBLEM STATEMENT

*/

#include <bits/stdc++.h>
using namespace std;

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

void helper(int l, int r, vector<int> indices, vector<int> &ans, vector<vector<int>>&minCost){
	if (minCost[l][r]!=-1)
	{
		return;
	}

	if (l>=r)
	{
		return;
	}

	//Make a cut at i
	vector<int> temp = ans;
	fr(i, l, r){
		ans.push_back(i);
		int cost+=r-l;
		//leftPartCost
		helper(l, i, indices, )
	}
}


vector<int> Solution::rodCut(int A, vector<int> &B) {
	vector<int> ans;
	vector<vector<int>> minCost(A, vector<int>(A,-1));
	helper(0, A, B, ans, minCost);
}
